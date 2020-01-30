#include <iostream>

#include "Rotor.h"
//reflector AY BR CU DH EQ FS GL IP JX KN MO TZ VW

int main() {
    std::cout << "Hello, World!" << std::endl;
    try{
        Rotor rot(std::string("EKMFLGDQVZNTOWYHXUSPAIBRCJ"));
        Rotor rot1(std::string("AJDKSIRUXBLHWTMCQGZNPYFVOE"));
        Rotor rot2(std::string("BDFHJLCPRTXVZNYEIWGAKMUSQO"));
    } catch (std::string ex){
        std::cout << ex;
        return 0;
    }
    return 0;
}
