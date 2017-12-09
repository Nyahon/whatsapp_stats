// reading a text file

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>

#include "convData.h"
using namespace std;

int dateNameCSV(convData c, string filename);

const uint NAME_WIDTH_MAX = 10;
int main () {
    convData c("../conversations/anna.txt");
    cout << "#msg in conversation: " << c.getNbMsg() << endl;

    string filename = "anna_yohann";
    dateNameCSV(c, filename);



    return 0;
}

int dateNameCSV(convData c, string filename){

    string name = "../data/" + filename + "_TimeName.csv";
    ofstream fi(name);
    if( fi.is_open() ) {

        string date;
        string sender;
        vector<message> messages = c.getConv();

        fi << "time" << "," << "name" << endl;
        for (int pers = 0; pers < c.getmsgIndexPersons().size(); pers++) {
            vector<int> msgIndexPerson = c.getmsgIndexPersons().at(pers);

            for (int i = 0; i < msgIndexPerson.size(); i++) {
                tm dateTM = messages[msgIndexPerson[i]].getDate();
                date = dateToString(&dateTM);

                sender = messages.at(msgIndexPerson[i]).getSender(); //TODO put in previous loop for improvement

                fi << mktime(&dateTM) << "," << sender << endl;
            }
        }
        cout << "data wrote in " << name << endl;
        fi.close();
    }else{
        cout << "Error opening file " << filename << endl;
    }
}