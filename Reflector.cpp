//
// Created by Ovidiu on 01.02.2020.
//

#include "Reflector.h"
#include <boost/algorithm/string.hpp>

Reflector::Reflector(){
}

Reflector::Reflector(std::string str) {
    std::vector<std::string> tmp_ref;
    boost::algorithm::split(tmp_ref, str, boost::is_any_of(" "));

    for(auto const& pair : tmp_ref){
        m_rotor[toOrder(pair[0])] = tolower(pair[1]);
        m_rotor[toOrder(pair[1])] = tolower(pair[0]);
    }
    m_position = std::distance(m_rotor.begin(), std::find(m_rotor.begin(), m_rotor.end(), 'a'));
}

//char Reflector::cript(int input)
//{
//    return getBack(input);
//}
