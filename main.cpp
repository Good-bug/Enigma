#include <iostream>

#include "Rotor.h"
#include "Reflector.h"
#include "Encrypter.h"
//reflector AY BR CU DH EQ FS GL IP JX KN MO TZ VW

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::vector<std::string> str_rotor;

    try{
        str_rotor.push_back(std::string("EKMFLGDQVZNTOWYHXUSPAIBRCJ"));
        str_rotor.push_back(std::string("AJDKSIRUXBLHWTMCQGZNPYFVOE"));
        str_rotor.push_back(std::string("BDFHJLCPRTXVZNYEIWGAKMUSQO"));

    } catch (std::string ex){
        std::cout << ex;
        return 0;
    }
    Reflector ref(std::string("AY BR CU DH EQ FS GL IP JX KN MO TZ VW"));

    Encrypter en(str_rotor, std::string("AY BR CU DH EQ FS GL IP JX KN MO TZ VW"));
    en.setPosition("rvc");

    for(int i = 0; i < 1000; ++i){
        std::cout << en.encrypt('a')/* << std::endl*/;
    }
    std::cout << en.encrypt('A') << std::endl;

    Rotor rot(std::string("EKMFLGDQVZNTOWYHXUSPAIBRCJ"));
//    rot.setPosition('r');
//    std::cout << rot.cript('a', 0);
//    std::cout << ref.cript('m', 2) << std::endl;

    return 0;
}
