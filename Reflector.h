//
// Created by Ovidiu on 01.02.2020.
//

#ifndef ENIGMA_REFLECTOR_H
#define ENIGMA_REFLECTOR_H

#include <iostream>
#include "Rotor.h"

class Reflector : public Rotor {
public:
    Reflector();
    Reflector(std::string);

    //char cript(int);

//    char cript(int, int) = delete;
    void rotate() = delete;
    void setPosition(int) = delete;
    void setPosition(char) = delete;


private:
    std::vector<char> m_reflector;

};


#endif //ENIGMA_REFLECTOR_H
