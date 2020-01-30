//
// Created by Ovidiu on 29.01.2020.
//

#include "Rotor.h"

#include <iostream>
#include <stdexcept>

Rotor::Rotor() {
    m_position = 0;

    for(char i = 'z'; i >= 'a'; --i){
        m_rotor.push_back(i);
    }
}

Rotor::Rotor(std::string alphabet) {
    if(alphabet.size() != alphabet_size) {
        throw std::string("ERORR: Rotor(string) constructor. Not valid alphabet size \"" + alphabet + "\".");
    }

    m_position = 0;

    for(int i = 0; i < alphabet_size; ++i){
        if(!isalpha(alphabet[i]))
            throw std::string("ERROR: Rotor(string) constructor. Not valid alphabet chara " + alphabet + "\".");
        m_rotor.push_back(tolower(alphabet[i]));
    }
}

char Rotor::cript(char imput) {
    if(!isalpha(imput))
        return imput;

    if(isupper(imput))
        return toupper(m_rotor.at(((m_position) + toOrder(imput))%(alphabet_size)));
    else
        return m_rotor.at(((m_position) + toOrder(imput))%(alphabet_size));

}

int Rotor::toOrder(char imput) {
    return (int)(tolower(imput) - 'a');
}

void Rotor::setPosition(int p) {
    m_position = p;
}

void Rotor::setPosition(char p) {
    m_position = toOrder(p);
}
char Rotor::current() {
    return m_rotor.at(m_position);
}