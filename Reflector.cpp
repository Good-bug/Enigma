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

    for(int i = 0; i < getAlbhabetSize(); ++i)
        m_reflector.push_back('0');

    std::cout << m_reflector.size() << std::endl;
    for(auto const& pair : tmp_ref){
        m_reflector[toOrder(pair[0])] = pair[1];
        m_reflector[toOrder(pair[1])] = pair[0];
    }
}