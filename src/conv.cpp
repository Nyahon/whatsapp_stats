//
// Created by nyahon on 30.09.17.
//

#include <fstream>
#include <iostream>
#include <algorithm>
#include "conv.h"
#include <ctime>


using namespace std;



conv::conv() : messages(), namesPersons(){

}

conv::conv(string pathToFile){

    char SEP_DATE, SEP_DATE_HM, SEP_HM, SEP_TIME_BODY, SEP_SENDER_CORPUS;
    int dateLength, timeLength;
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
        getline(myfile, line);
        sepCharWA(line, dateLength, timeLength, SEP_DATE, SEP_DATE_HM, SEP_HM, SEP_TIME_BODY, SEP_SENDER_CORPUS );
        myfile.seekg (0, ios::beg);
        cout << SEP_DATE << " " << SEP_DATE_HM << " " << SEP_HM << " " << SEP_TIME_BODY << " " << SEP_SENDER_CORPUS << " " << dateLength << " " << timeLength << endl;


        while ( getline (myfile,line) ){
            //strong selection based on the current format of Whatsapp Dump - 13.10.17
            //if found, we are at the first line of a message.

            if(line.find(SEP_DATE_HM) == dateLength && line.find(SEP_TIME_BODY) == timeLength ){

                int compensate = -190;
                if(dateLength == 8){
                    compensate = 100;
                }
                splitAtFirst(line, SEP_TIME_BODY, time, body);

                //=================TIME====================
                splitAtFirst(time, SEP_DATE_HM, date, timeHM);
                tm t = {0};

                vector<int> ret;
                split(date, SEP_DATE ,ret);

                t.tm_mday   = ret[0];
                t.tm_mon    = ret[1] - 1;
                t.tm_year   = compensate + ret[2]; //HACKY AS FUCK, only work for Year>2000 TODO BETTER

                ret.clear();

                timeHM.erase(timeHM.begin());

                split(timeHM, SEP_HM, ret);
                t.tm_hour = ret[0];
                t.tm_min = ret[1];
                ret.clear();

                t.tm_isdst = -1;
                //=================BODY====================
                if(body.find(SEP_SENDER_CORPUS) != string::npos){

                }
                splitAtFirst(body, SEP_SENDER_CORPUS, name, text);

                if(!name.empty()) {
                    //remove front space
                    name.erase(name.begin());

         //add people to the list if not yet in.
                    if(namesPersons.count(name) == 0){
                        namesPersons[name] = cntPersons++;
                        msgPersons.resize(msgPersons.size() + 1);
                    }

                    if(name == "Annaline" || name == "Yohann"){

                    }else{
                        cout << "ERR " << name << " : " << id << endl;
                    }
                    messages.push_back( message(t, name, text, id) );
                    msgPersons.at(namesPersons[name]).push_back(id);
                    id++;

                }

            }else{
                messages[id-1].addCorpusLine(line);
            }
        }
        nbMessages = messages.size();
        start =  messages[0].getDate();
        end = messages[messages.size()-1].getDate();

    }

}

uint conv::getNbrPerson(){
    return namesPersons.size();
}

vector<string> conv::getnamesPersons(vector<string> *names) {
    for(map<string,int>::iterator it = namesPersons.begin(); it != namesPersons.end(); ++it) {
        names->push_back(it->first);
    }
}

const vector<message> conv::getConv(){
    return messages;
}

const vector<message> conv::getMsg(string name){
    vector<message> listMsg;

    for(int i = 0;i<msgPersons[ namesPersons[name] ].size();++i){
        listMsg.push_back( messages[i] );
    }
}

const vector< vector<int> > conv::getmsgIndexPersons(){
    return msgPersons;
}

const int conv::getNbMsg(){
    return nbMessages;
}
string conv::toString(){
    stringstream conv;
    for(int i = 0;i<nbMessages;++i){
        conv << messages[i].toString() << endl;
    }
    return conv.str();
}