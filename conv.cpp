//
// Created by nyahon on 30.09.17.
//

#include <fstream>
#include <iostream>
#include <algorithm>
#include "conv.h"
#include <ctime>


using namespace std;

#define SEP_HEADER ':'
#define SEP_TIME '-'


conv::conv() : messages(), namesPersons(){

}

conv::conv(string pathToFile){
    ifstream myfile(pathToFile);
    string line;

    time_t timeMessage;
    vector<string> lineSplit;
    string time = "";
    string body = "";
    string name = "";
    string text = "";
    string date = "";
    string timeHM = "";
    int cntPersons = 0;
    int id = 0;

    if (myfile.is_open())
    {
        while ( getline (myfile,line) ){
            //strong selection based on the current format of Whatsapp Dump - 13.10.17
            //if found, we are at the first line of a message.
            if(line.find(",") == 8 && line.find(" - ") == 15){

                splitAtFirst(line, SEP_TIME, time, body);

                //=================TIME====================
                splitAtFirst(time, ',', date, timeHM);
                tm t = {0};

                vector<int> ret;
                split(date,'.',ret);

                t.tm_mday   = ret[0];
                t.tm_mon    = ret[1];
                t.tm_year   = 100 + ret[2]; //HACKY AS FUCK TODO BETTER

                ret.clear();

                timeHM.erase(timeHM.begin());

                split(timeHM, ':', ret);
                t.tm_hour = ret[0];
                t.tm_min = ret[1];
                cout << dateToString(&t) << endl;
                ret.clear();

                //=================BODY====================
                splitAtFirst(body, SEP_HEADER, name, text);

                if(!name.empty()) {
                    //remove front space
                    name.erase(name.begin());

                    //add people to the list if not yet in.
                    if(namesPersons.count(name) == 0){
                        namesPersons[name] = cntPersons++;
                        msgPersons.resize(msgPersons.size() + 1);
                    }

                    messages.push_back( message(t, name, text, id) );
                    msgPersons.at(namesPersons[name]).push_back(id);

                }

            }else{

            }
            id++;
        }
        nbMessages = messages.size();
        start = messages[0].getDate();
        end = messages[messages.size()-1].getDate();
        cout << dateToString(&start) << "--" << dateToString(&end) << endl;
        cout << duration(&start, &end) << endl;
      //  tm inte = interval(start, end);
      //  cout << dateToString( localtime( mktime( end ) - mktime( start) ) );
    }

}

uint conv::getNbrPerson(){
    return namesPersons.size();
}
string conv::toString(){
    stringstream conv;
    for(int i = 0;i<nbMessages;++i){
        conv << messages[i].toString() << endl;
    }
    return conv.str();
}