//Enigma encryption
//Copyright (C) 2020 Rabii Ovidiu Cristian
//
//This program is free software: you can redistribute it and/or modify
//        it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.
//
//This program is distributed in the hope that it will be useful,
//        but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with this program.  If not, see <https://www.gnu.org/licenses/>.
//Copyright (C) 2020 Rabii Ovidiu Cristian

#ifndef ENIGMA_ROTOR_H
#define ENIGMA_ROTOR_H

#include <vector>
#include <map>

class Rotor {
public:
    Rotor();
    Rotor(std::vector<char> roter);
    Rotor(std::string);


    void rotate(int step = 1){
        if(m_position < m_rotor.size() - 1){
            m_position += step;
            if(m_mid && m_position == m_rotor.size() - 1)
                rotate();
        }  else {
            m_position = 0;
        }
    }

    void rotateBack(int step = 1){
        if(m_position > 0) {
            m_position -= step;
            if(m_mid && m_position == m_rotor.size() - 1)
                rotate();
        } else {
            m_position = m_rotor.size() - 1;
        }
    }

    void setPosition(int);
    void setPosition(char);
    int getPosition();

    char current();
    char cript(char, int);
    char bcript(char, int);

    int getAlbhabetSize(){return alphabet_size;};
    void setAlphabetSize(int size){alphabet_size = size;};

    void print();
    static int toOrder(char);
    bool operator==(Rotor &left){
        return m_rotor == left.m_rotor;
    }

    void setMid(bool mid) {m_mid = mid;};
    bool isMid() { return m_mid;}

    char getBack(char const&);

private:
    int find(int);
    int find(char);

    int m_position{0};
    int alphabet_size = 26;

    bool m_mid{false};

protected:
    std::vector<char> m_rotor;
};


#endif //ENIGMA_ROTOR_H
