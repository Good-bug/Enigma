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

char Encrypter::encrypt(char c) {
//    for(int i = 0; i < m_rotors.size(); ++i)
//        std::cout << "position " << i << ": " << m_rotors[i].getPosition() << ";\t";
//    std::cout << std::endl;
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

    pos = 0;
    for(auto& r : boost::adaptors::reverse(m_rotors)){
        back = (" <-- " + std::string(1, c)) + back;
        c = r.cript(c, (r.getPosition() + pos));
    }
    back = std::string(1, c) + back;
    std::cout << back << std::endl;

    bool pas = true;
    for(auto& r : m_rotors){
        if(pas){
            pas = r.getPosition() == r.getAlbhabetSize();
            r.rotate();
        }
    }

    return c;
}