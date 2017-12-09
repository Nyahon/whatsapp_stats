//
// Created by nyahon on 30.09.17.
//

#pragma once

#include <string>
#include <sstream>

#include <vector>
#include <iterator>
#include <iomanip>
#include <math.h>

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
static tm interval(tm start, tm end){
    tm x;
        x.tm_year = end.tm_year-start.tm_year;
        x.tm_mon  = end.tm_mon-start.tm_mon;
        x.tm_mday = end.tm_mday-start.tm_mday;
      //  mktime(&x);
        return x;
}
static std::string dateToString(const tm *date){
    std::stringstream t;
    t  << std::setw(2) << std::setfill('0') << date->tm_mday << "."
       << std::setw(2) << std::setfill('0') << date->tm_mon + 1 << "."
       << std::setw(4) << std::setfill(' ') << date->tm_year+1900
         << "-"
       << std::setw(2) << std::setfill('0') << date->tm_hour << ":"
       << std::setw(2) << std::setfill('0') << date->tm_min;
    return t.str();
}

static std::string duration(tm *start, tm *end){
    time_t st = mktime(start);
    time_t en = mktime(end);
    std::stringstream dur;

    double t = difftime(en, st);
    int days = t / 60 / 60 / 24;
    t-=days;
    int hours = fmod( (t / 60 / 60), 24);
    t-=hours;
    int minutes = fmod( (t / 60), 60);
    t-=minutes;
    int seconds = fmod(t,60);
    dur << days << "j " <<  hours << "d " << minutes << "m "<< seconds << "s " << "''";

    return dur.str();
}

static void sepCharWA(std::string line, char &time, char &){

    line.find_first_not_of("0123456789");
    for(char c : line){
        if(!isdigit(c));
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

