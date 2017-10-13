//
// Created by nyahon on 30.09.17.
//

#include "message.h"


message::message() : date(tm()), sender(""), corpus({""}){

}
message::message(tm d, string sender, vector<string> corpus) : date(d), sender(sender), corpus(corpus){

}
message::message(tm d, string sender, string corpusLine) : date(d), sender(sender){
    corpus.push_back(corpusLine);
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
