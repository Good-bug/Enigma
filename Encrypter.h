//
// Created by Ovidiu on 09.02.2020.
//

#ifndef ENIGMA_ENCRYPTER_H
#define ENIGMA_ENCRYPTER_H

#include <vector>
#include <iostream>
#include "Rotor.h"
#include "Reflector.h"
//#include <QDebug>

class Encrypter {
public:
    char encrypt(char);

    Encrypter(std::vector<std::string> &rotors, std::string &reflector);
    void rotate(int);
    void rotateBack(int);

    void rotate();
    void rotateBack();
    char getChar(int);

    void setPosition(std::string);
    void setPosition(std::vector<int>);

private:
    std::vector<Rotor> m_rotors;
    Reflector m_reflector;

};


#endif //ENIGMA_ENCRYPTER_H
