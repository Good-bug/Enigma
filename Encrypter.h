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
//    Encrypter() = delete;
    Encrypter(std::vector<std::string> &rotors, std::string &reflector);
    char encrypt(char);
    void pushBackRotor(std::string t);
    void pushBackRotor(Rotor r);
    void rotate(int);
    void rotateBack(int);

    void rotate();
    void rotateBack();
    char getChar(int);
    void print(){
        std::cout << m_rotors.at(0).current() << std::endl;
    }

private:
    std::vector<Rotor> m_rotors;
    Reflector m_reflector;

};


#endif //ENIGMA_ENCRYPTER_H
