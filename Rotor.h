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


    void rotate(){
        if(m_position < alphabet_size)
            ++m_position;
        else
            m_position = 0;
    }
    void setPosition(int);
    void setPosition(char);
    char current();
    char cript(char);

private:
    std::vector<char> m_rotor;
    int m_position;

    int find(int);
    int find(char);
    int toOrder(char);
    int alphabet_size = 26;



};


#endif //ENIGMA_ROTOR_H
