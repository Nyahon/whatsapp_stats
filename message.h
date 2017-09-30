//
// Created by nyahon on 30.09.17.
//

#ifndef PROJECTS_MESSAGE_H
#define PROJECTS_MESSAGE_H

#include <ctime>
#include <string>
#include <vector>
#include "utils.hpp"
using namespace std;

class message {
public:
    message();
    message(time_t date, string sender, vector<string> corpus);
    time_t getDate();
    string getSender();
    vector<string> getCorpus();
    string getText();
private:
    const time_t date;
    const string sender;
    const vector<string> corpus;

};


#endif //PROJECTS_MESSAGE_H
