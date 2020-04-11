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

char Encrypter::encrypt(char c) {
    if(!isalpha(c))
        return c;

    m_rotors[0].setPosition('r');
    m_rotors[1].setPosition('v');
    m_rotors[2].setPosition('c');


    std::cout << m_rotors[0].getPosition() << "\t";
    std::cout << m_rotors[1].getPosition() << "\t";
    std::cout << m_rotors[2].getPosition() << std::endl;



    int pos = 0;
    for(auto& r : m_rotors){
        std::cout << c << " --> ";

        c = r.cript(c, pos);
        pos = r.getPosition();
    }
    std::cout << c << std::endl;

    c = m_reflector.cript(c, pos);

    std::string back = "";

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
//    for(auto& r : boost::adaptors::reverse(m_rotors)){
        back = (" <-- " + std::string(1, c)) + back;
        c = back_get(m_rotors[2], m_rotors[2].cript(c, (/*r.getPosition() + */pos)));
        //pos = m_rotors[2].getPosition();
//    }


        back = (" <-- " + std::string(1, c)) + back;
        c = back_get(m_rotors[1], m_rotors[1].cript(c, (m_rotors[1].getPosition() + /**/pos)));
        //pos = m_rotors[1].getPosition();

        back = (" <-- " + std::string(1, c)) + back;
        c = back_get(m_rotors[0], m_rotors[0].cript(c, (m_rotors[2].getPosition() + /**/pos)));

    back = std::string(1, c) + back;
    std::cout << back << std::endl;

    rotate();
    return c;
}
