//
// Created by nyahon on 30.09.17.
//

#include "message.h"


message::message() : date(0), sender(""), corpus({""}){

}
message::message(time_t d, string sender, vector<string> corpus) : date(d), sender(sender), corpus(corpus){

}

time_t message::getDate(){
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
