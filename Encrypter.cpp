//
// Created by Ovidiu on 09.02.2020.
//

#include "Encrypter.h"
#include <boost/range/adaptor/reversed.hpp>

Encrypter::Encrypter(std::vector<std::string> &rotors, std::string &reflector) : m_reflector(reflector) {
    if(rotors.size() == 3)
        for(auto const& str : rotors){
            m_rotors.push_back(Rotor(str));
        }

    for(auto& r : m_rotors){
        r.print();
    }
    m_rotors.at(1).setMid(true);

}

void Encrypter::rotate(int roter){
    if(roter < 0 || roter > m_rotors.size()){
        return;
    }

    m_rotors.at(roter).rotate();
}

void Encrypter::rotateBack(int roter){
    if(roter < 0 || roter > m_rotors.size()){
        return;
    }

    m_rotors.at(roter).rotateBack();
}

void Encrypter::rotate()
{
    bool pas = true;
    for(auto& r : m_rotors)
        if(pas){
            pas = r.getPosition() == r.getAlbhabetSize() - 1;

            if(r.isMid()) {
                pas = r.getPosition() == r.getAlbhabetSize() - 2;
            }
            r.rotate();
        }
}

void Encrypter::rotateBack()
{

    bool pas = true;
    for(auto& r : m_rotors)
        if(pas){
            pas = r.getPosition() == r.getAlbhabetSize() - 1;

            if(r.isMid()) {
                pas = r.getPosition() == r.getAlbhabetSize() - 2;
            }
            r.rotateBack();
        }
}

char Encrypter::getChar(int roter)
{
    return m_rotors.at(roter).current();
}

char Encrypter::encrypt(char k) {
    if(!isalpha(k))
        return k;


    std::cout << Rotor::toOrder(m_rotors[0].current()) << "\t";
    std::cout << Rotor::toOrder(m_rotors[1].current()) << "\t";
    std::cout << Rotor::toOrder(m_rotors[2].current()) << std::endl;


    char c = std::tolower(k);

    int pos = 0;
    for(auto& r : m_rotors){
        std::cout << c << " --> ";
        c = r.cript(Rotor::toOrder(c), pos);
        pos = Rotor::toOrder(r.current());
    }
    std::cout << c << std::endl;

    c = m_reflector.bcript(Rotor::toOrder(c), pos);

    auto back_get =[&](Rotor& r, auto const& tmp_c){
        char tmp;

        auto old_pos = r.getPosition();
        r.setPosition(tmp_c);

        if(std::isupper(c))
            tmp = (int)(r.getPosition() + 'A');
        else
            tmp = (int)(r.getPosition() + 'a');

        r.setPosition(old_pos);

        return tmp;
    };

    pos = 0;
    std::string back;
    back = (" <-- " + std::string(1, c)) + back;
    c = m_rotors[2].bcript((Rotor::toOrder(c)), (/*r.getPosition() + */pos));
    pos = Rotor::toOrder(m_rotors[2].current());

    back = (" <-- " + std::string(1, c)) + back;
    c = m_rotors[1].bcript((Rotor::toOrder(c)), pos);
    pos = Rotor::toOrder(m_rotors[1].current());

    back = (" <-- " + std::string(1, c)) + back;
    c = m_rotors[0].bcript((Rotor::toOrder(c)), pos);
    pos = Rotor::toOrder(m_rotors[0].current());

    back = std::string(1, c) + back;
    std::cout << back << std::endl;

    rotate();

    char tmp = c - pos;
    tmp = tmp < 'a' ? tmp + (m_reflector.getAlbhabetSize()) : tmp;

    return std::islower(k) ? tmp : std::toupper(tmp);
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
