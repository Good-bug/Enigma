//
// Created by Ovidiu on 09.02.2020.
//

#include "Encrypter.h"
#include <boost/range/adaptor/reversed.hpp>

Encrypter::Encrypter() {

}

Encrypter::Encrypter(std::vector<std::string> rotors, std::string reflector) : m_reflector(reflector) {
    for(auto const& str : rotors){
        m_rotors.push_back(Rotor(str));
    }

    for(auto& r : m_rotors){
        r.print();
    }

}

char Encrypter::encrypt(char k) {
    if(!isalpha(k))
        return k;

    char c = std::tolower(k);

    int pos = 0;
    for(auto& r : m_rotors){
        c = r.cript(c, forward(pos, r.getPosition()));
        pos = r.getPosition();
    }

    c = m_reflector.cript(c, -pos);

    pos = 0;
    for(auto& r : boost::adaptors::reverse(m_rotors)){
        c = r.bcript(c, backward(pos, r.getPosition()));
        pos = r.getPosition();
    }

    bool pas = true;
    for(auto& r : m_rotors){
        if(pas){
            pas = r.getPosition() == r.getAlbhabetSize();
            r.rotate();
            if(r == m_rotors.at(1) && r.getPosition() == (r.getAlbhabetSize() - 1)) {
                r.rotate();
            }
        }
    }

    char tmp = c - pos;
    tmp = tmp < 'a' ? tmp + (m_reflector.getAlbhabetSize()) : tmp;

    return std::islower(k) ? tmp : std::toupper(tmp);
}

int Encrypter::forward(int pos, int curent) {
    return (curent - pos);
}

int Encrypter::backward(int pos, int curent) {
    return (pos - curent);
}

void Encrypter::setPosition(std::string pos) {
    if(pos.size() != m_rotors.size()){
        throw std::string("ERROR: Encrypter::setPosition(std::string) -> string size " + std::to_string(pos.size()) + ", differs from rotors count " + std::to_string(m_rotors.size()));
    }

    for(int i = 0; i < m_rotors.size(); ++i){
        m_rotors.at(i).setPosition(pos[i]);
    }
}

void Encrypter::setPosition(std::vector<int> pos) {
    if(pos.size() != m_rotors.size()){
        throw std::string("ERROR: Encrypter::setPosition(std::vector<int>) -> string size " + std::to_string(pos.size()) + ", differs from rotors count " + std::to_string(m_rotors.size()));
    }

    for(int i = 0; i < m_rotors.size(); ++i){
        m_rotors.at(i).setPosition(pos[i]);
    }
}