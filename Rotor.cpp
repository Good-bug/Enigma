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

char Rotor::cript(int input, int prev_pos) {

    int curr = toOrder(current());
    int position = (input + (curr /**/- prev_pos))%(alphabet_size);
    position = position < 0 ? alphabet_size + position : position;

    return m_rotor.at(position);

}

char Rotor::bcript(int input, int prev_pos) {
    int curr = toOrder(current());

    int position = (input - (prev_pos - curr))%(alphabet_size);
    position = position < 0 ? alphabet_size + position : position;

    char val = position + 'a';
    auto const& it = std::find(m_rotor.begin(), m_rotor.end(), val/*input + 'a'*/);

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

    auto it = std::find_if(m_rotor.begin(), m_rotor.end(), [&p](auto const& c){return c == p;});
    m_position = std::distance(m_rotor.begin(), it);
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
}

void Rotor::rotate(int step){
    auto const pos = (toOrder(current()) + step) % alphabet_size;
    auto const& it = std::find(m_rotor.begin(), m_rotor.end(), pos +'a');

    m_position = std::distance(m_rotor.begin(), it);
    if(m_mid && pos +'a' == 'z'){
        rotate();
    }

}

void Rotor::rotateBack(int step){
    auto pos = (toOrder(current()) - step);
    if(pos < 0)
        pos += alphabet_size;

    auto const& it = std::find(m_rotor.begin(), m_rotor.end(), pos + 'a');
    m_position = std::distance(m_rotor.begin(), it);

    if(m_mid && pos +'a' == 'z'){
        rotateBack();
    }
}
