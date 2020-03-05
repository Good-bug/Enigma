//
// Created by Ovidiu on 09.02.2020.
//

#ifndef ENIGMA_ENCRYPTER_H
#define ENIGMA_ENCRYPTER_H

#include <vector>
#include <iostream>
#include "Rotor.h"
#include "Reflector.h"

class Encrypter {
public:
    Encrypter();
    Encrypter(std::vector<std::string> rotors, std::string reflector);

    int forward(int pos, int curent);
    int backward(int pos, int curent);
    char encrypt(char);

    void push_back_rotor(std::string t);
    void push_back_rotor(Rotor r);

    void setPosition(std::string);
    void setPosition(std::vector<int>);

private:
    std::vector<Rotor> m_rotors;
    Reflector m_reflector;

};


#endif //ENIGMA_ENCRYPTER_H
