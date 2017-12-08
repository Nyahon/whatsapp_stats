//
// Created by nyahon on 30.09.17.
//

#include <iostream>
#include <iomanip>
#include "message.h"


message::message() : date(tm()), sender(""), corpus({""}), id(){

}
message::message(tm d, string sender, vector<string> corpus, int id)
            : date(d), sender(sender), corpus(corpus), id(id){



}
message::message(tm d, string sender, string corpusLine, int id) : date(d), sender(sender), id(id){
    corpus.push_back(corpusLine);
}

int message::getId(){
    return id;
}
tm message::getDate(){
    return date;
}

string message::getSender(){
    return sender;
}

vector<string> message::getCorpus(){
  return corpus;
}

string message::getText(){
    string corp;
    for(int i = 0; i<corpus.size();++i){
        corp.append(corpus[i]);
        corp.append(" ");
    }
    return corp;
}
void message::addCorpusLine(string corpusLine){
    corpus.push_back(corpusLine);
}


string message::toString() {
    stringstream mes;

    mes  << dateToString(&date)
         << ", "        << sender << ":" << endl
         << getText() << endl;
    return  mes.str();

}
