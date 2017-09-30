//
// Created by nyahon on 30.09.17.
//

#ifndef PROJECTS_UTILS_HPP
#define PROJECTS_UTILS_HPP

#include <string>
#include <sstream>
#include <vector>
#include <iterator>

//Pre-constructed vector.
template<typename Out>
void split(const std::string &s, char delim, Out result) {
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}
//return new vector
std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}


#endif //PROJECTS_UTILS_HPP
