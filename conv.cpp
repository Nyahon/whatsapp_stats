//
// Created by nyahon on 30.09.17.
//

#include <fstream>
#include <iostream>
#include <algorithm>
#include "conv.h"


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

    if (myfile.is_open())
    {
        while ( getline (myfile,line) ){
            //strong selection based on the current format of Whatsapp Dump - 13.10.17
            //if found, we are at the first line of a message.
            if(line.find(",") == 8 && line.find(" - ") == 15){

                splitAtFirst(line, SEP_TIME, time, body);
              //  cout << time << "****" << SEP_TIME << body << endl;

                //=================TIME====================
                splitAtFirst(time, ',', date, timeHM);
                tm t = {0};

                vector<int> ret;
                split(date,'.',ret);
                //for (auto r : ret)
                //    cout << r << ":::";
                t.tm_mday   = ret[0];
                t.tm_mon    = ret[1];
                t.tm_year   = 100 + ret[2]; //HACKY AS FUCK TODO BETTER

                //cout <<"TK: " << t.tm_mday << endl;
                ret.clear();

                timeHM.erase(timeHM.begin());
                //cout << timeHM << endl;

                split(timeHM, ':', ret);
                t.tm_hour = ret[0];
                t.tm_min = ret[1];
                cout << t.tm_mday << ":" << t.tm_mon << ":" << 1900+t.tm_year << "," << t.tm_hour
                     << ":" << t.tm_min << endl;
                ret.clear();

                //=================BODY====================
                splitAtFirst(body, SEP_HEADER, name, text);

                if(!name.empty()) {
                    //remove front space
                    name.erase(name.begin());

                    //add people to the list if not yet in.
                    if(namesPersons.count(name) == 0){
                        namesPersons[name] = cntPersons++;
                        cout << "*" << name << "*" << namesPersons[name]<< endl;
                    }
                    message mess = message(t, name, text);
                    messages.resize(4);
                    messages.at(namesPersons[name]).push_back(mess);

                    for(int i = 0;i<messages.at(0).size();i++){
                        cout << messages.at(0).at(i).getSender()<< ":" << messages.at(1).at(i).getSender() << endl;
                    }
                }

            }else{

            }
            //split(line, SEP_HEADER, lineSplit);
        }

    }/*
        while ( getline (myfile,line) )
        {
            //cout << line << '\n';
            if (line.find(user1) != string::npos) {
                numMessUser1++;
            }
            if (line.find(user2) != string::npos) {
                numMessUser2++;
            }

        }
        myfile.close();
*/
}

uint conv::getNbrPerson(){

}