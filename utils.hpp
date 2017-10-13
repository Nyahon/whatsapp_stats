//
// Created by nyahon on 30.09.17.
//

#pragma once

#include <string>
#include <sstream>
#include <vector>
#include <iterator>

//Pre-constructed vector.



template<typename Out >
static void split(const std::string &s, char delim, std::vector<Out> &result) {
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        result.push_back(item);
    }
}
template<>
void split<int>(const std::string &s, char delim, std::vector<int> &result) {
    std::stringstream ss;
    ss.str(s);
    std::string item;

    while (std::getline(ss, item, delim)) {
        result.push_back(std::stoi(item));
    }
}

static void splitAtFirst(const std::string &s, char delim, std::string &s1, std::string &s2){

    const auto equals_idx = s.find_first_of(delim);
    if (std::string::npos != equals_idx)
    {
        s1 = s.substr(0, equals_idx);
        s2 = s.substr(equals_idx + 1);
    }
    else
    {
        s1 = "";
        s2 = s;
    }

}
//return new vector
/*
std::vector<std::string> splitStringOO(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}
*/

