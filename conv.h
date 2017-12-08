//
// Created by nyahon on 30.09.17.
//

#ifndef PROJECTS_CONV_H
#define PROJECTS_CONV_H

#include <map>
#include "message.h"

using namespace std;

struct idMesInConv{
    int idName;
    int idMsg;
};

class conv {
public:
    conv();
    conv(string pathToFile);
    uint getNbrPerson();
    vector<message> getConv();
    vector<message> getMsg(string name);
    string toString();



private:
    vector<message> messages;
    map<string,int> namesPersons;
    vector< vector <int> > msgPersons;
    int nbMessages;
    tm start;
    tm end;
};


#endif //PROJECTS_CONV_H
