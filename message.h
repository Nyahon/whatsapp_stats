//
// Created by nyahon on 30.09.17.
//
#pragma once

#include <ctime>
#include <string>
#include <vector>
#include "utils.hpp"
using namespace std;

class message {
public:
    message();
    message(tm date, string sender, vector<string> corpus);
    message(tm date, string sender, string corpus);

    tm getDate();
    string getSender();
    vector<string> getCorpus();
    string getText();
    void addCorpusLine(string corpusLine);
private:
    const tm date;
    const string sender;
    vector<string> corpus;

};


