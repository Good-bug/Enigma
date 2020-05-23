#include <iostream>

#include "Rotor.h"
#include "Reflector.h"
#include "Encrypter.h"

#include "mainwindow.h"
#include <QApplication>
//reflector AY BR CU DH EQ FS GL IP JX KN MO TZ VW

int main(int argc, char *argv[]) {
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

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
