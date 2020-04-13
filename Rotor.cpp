//
// Created by Ovidiu on 29.01.2020.
//

#include "Rotor.h"

#include <algorithm>
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
            throw std::string("ERROR: Rotor(string) constructor. Not valid alphabet chara in \"" + alphabet + "\" at \"" + alphabet[i] + "\".");
        m_rotor.push_back(tolower(alphabet[i]));
    }
}

char Rotor::cript(char input, int algoritm) {
    if(!isalpha(input))
        return input;

    int position = (toOrder(input) + algoritm)%(alphabet_size);
    position = position < 0 ? alphabet_size + position : position;

    return m_rotor.at(position);

}

char Rotor::bcript(char input, int algoritm) {
    if(!isalpha(input))
        return input;

    int position = (toOrder(input) - algoritm)%(alphabet_size);
    position = position < 0 ? alphabet_size + position : position;

    auto const& it = std::find(m_rotor.begin(), m_rotor.end(), position + 'a');

    char enc = std::distance(m_rotor.begin(), it) + 'a';
    return enc;

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

int Rotor::getPosition(){
    return  m_position;
}

void Rotor::print() {
    std::string str = "";
    for(auto const& ch : m_rotor){
        str += ch;
    }
//    std::cout << str << std::endl;
}
