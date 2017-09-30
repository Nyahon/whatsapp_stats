//
// Created by nyahon on 30.09.17.
//

#ifndef PROJECTS_CONV_H
#define PROJECTS_CONV_H

#include "message.h"

using namespace std;

class conv {
public:
    conv();
    conv(string pathToFile);
    uint getNbrPerson();

private:
    vector<vector<message> > messages;
    vector<string> namesPersons;

};


#endif //PROJECTS_CONV_H
