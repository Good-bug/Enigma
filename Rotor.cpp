//
// Created by Ovidiu on 29.01.2020.
//

#include "Rotor.h"

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <algorithm>

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

char Rotor::getBack(char const& tmp_c){
        char tmp;

        auto it = std::find_if(m_rotor.begin(), m_rotor.end(), [&tmp_c](auto const& c){return c == tmp_c;});

        if(std::isupper(tmp_c))
            tmp = std::distance(m_rotor.begin(), it) + 'A';
        else
            tmp = std::distance(m_rotor.begin(), it) + 'a';

//        auto old_pos = r.getPosition();
//        r.setPosition(tmp_c);

//        if(std::isupper(c))
//            tmp = (int)(r.getPosition() + 'A');
//        else
//            tmp = (int)(r.getPosition() + 'a');

//        r.setPosition(old_pos);

        return tmp;
    };
