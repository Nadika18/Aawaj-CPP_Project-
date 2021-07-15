#pragma once
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <cstring>
#include "login.cpp"

using namespace std;
class message{
    char sender[20];
    char receiver[20];
    char messageBody[250];
    time_t msgtime;
    
    public:
    message(char rec[],char msgbody[]){
        strcpy(sender, currentLoggedInUsername);
        strcpy(receiver, rec);
        strcpy(messageBody,msgbody);
        msgtime= getCurrentTime();
        
    }
    time_t getCurrentTime(){
        time_t t; // t passed as argument in function time()
        struct tm * tt; // decalring variable for localtime()
        time (&t); //passing argument to time()
        return t;
    }
    char *showMsgTime(){
    time_t t; // t passed as argument in function time()
    struct tm * tt; // decalring variable for localtime()
    time (&t); //passing argument to time()
    tt = localtime(&t);
    return asctime(tt);
    };
    void display(){
        cout.setf(ios::left);
        cout<<"sent by"<<sender<<endl;
        fstream receiverFile;
        string path="../data/messages/";
        string extension= ".bin";
        string sdr(sender), rec(receiver);
        receiverFile.open((path+rec+"/"+sdr+extension).c_str(), ios::out);
        receiverFile<<endl;
        cout.setf(ios::right);
        cout<<"received by"<<receiver<<endl;
        cout<<messageBody<<endl;
        cout<<asctime(localtime(&msgtime));



    }
};


