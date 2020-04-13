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

    m_rotors[0].setPosition('r');
    m_rotors[1].setPosition('v');
    m_rotors[2].setPosition('c');


    std::cout << m_rotors[0].getPosition() << "\t";
    std::cout << m_rotors[1].getPosition() << "\t";
    std::cout << m_rotors[2].getPosition() << std::endl;


    char c = std::tolower(k);

    int pos = 0;
    for(auto& r : m_rotors){
        c = r.cript(c, forward(pos, r.getPosition()));
        pos = r.getPosition();
    }

    c = m_reflector.cript(c, -pos);

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
//    for(auto& r : boost::adaptors::reverse(m_rotors)){
    back = (" <-- " + std::string(1, c)) + back;
    c = m_rotors[2].getBack(m_rotors[2].cript(c, (/*r.getPosition() + */pos)));
    pos = m_rotors[2].getPosition();
//    }

    back = (" <-- " + std::string(1, c)) + back;
    c =m_rotors[1].getBack(m_rotors[1].cript(c, (m_rotors[1].getPosition() + /**/pos)));
    pos = m_rotors[1].getPosition();

    back = (" <-- " + std::string(1, c)) + back;
    c = m_rotors[0].getBack(m_rotors[0].cript(c, (m_rotors[2].getPosition() + /**/pos)));

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
