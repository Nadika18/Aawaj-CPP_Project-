#pragma once
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <cstring>
#include <windows.h>
#include <cstdio> // include for std::rename
#include <vector>
#include <algorithm>
#include <iterator>
#include <set>
#include "login.cpp"

using namespace std;
class message{
    protected:
    char sender[20];
    char receiver[20];
    char messageBody[250];
    time_t msgtime;
    
    public:
    message(){}
    message(char rec[],char msgbody[]){
        strcpy(sender, currentLoggedInUsername);
        strcpy(receiver, rec);
        strcpy(messageBody,msgbody);
        msgtime= getCurrentTime();
        
    }
    message(char sen[]){
        strcpy(sender, sen);
        strcpy(receiver, currentLoggedInUsername);
        msgtime= getCurrentTime();
        
    }
    message(char rec[], int i){
       strcpy(sender, currentLoggedInUsername); 
       strcpy(receiver, rec); 
      
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
    void sendMessage(){
        
        string path="../data/messages/";
        string extension= ".bin";
        string sdr(sender), rec(receiver);
        fstream receiverFile;
        receiverFile.open((path+rec+"/"+sdr+extension).c_str(), ios::app);
        receiverFile.write((char *)this, sizeof(message));
        receiverFile.close();
        fstream databasefile;
        databasefile.open((path+rec+"/database.bin").c_str(),ios::app);
        databasefile<<sender<<std::endl;
                
    }
    bool operator < (const message& str) const
    {
        return (msgtime < str.msgtime);
    }
    friend void viewmessage(message &);
    
    friend ostream& operator<<(ostream &out,message &p);

};

void changeColor(int);

void viewsenders(){
    char p[20];
    string path="../data/messages/";
    string rec(currentLoggedInUsername);
    fstream databasefile;
    databasefile.open((path+rec+"/database.bin").c_str(),ios::in);
    std::cout<<"Inbox:"<<std::endl;
    set<string, greater<string> >s1;
    while(!databasefile.eof()){
    databasefile>>p;
    string s(p);
    s1.insert(s);
    }
    // printing set s1
    set<string, greater<string> >::iterator itr;
    for (itr = s1.begin(); itr != s1.end(); itr++)
    {
        std::cout << *itr<<" "<<std::endl;
    }
    std::cout<<std::endl;
    std::cout<<"Whose message would you like to view ?"<<std::endl;
    std::cout<<std::endl;
    databasefile.close();
}


void viewmessage(message &p){
    vector<message> v;
    fstream senderFile;
    string path="../data/messages/";
    string extension= ".bin";
    string sdr(p.sender), rec(p.receiver);
    senderFile.open((path+rec+"/"+sdr+extension).c_str(), ios::in);
    while(senderFile.read((char *)&p, sizeof(p))){
        v.push_back(p);
    }
    
    senderFile.close();
    
    fstream receiverFile;
    message m(p.sender,0);
    receiverFile.open((path+sdr+"/"+rec+extension).c_str(),ios::in);
    while(receiverFile.read((char *)&m , sizeof(m))){
        v.push_back(m);
    }
    receiverFile.close();
    std::sort(v.begin(), v.end());
   for(auto it = v.begin(); it != v.end(); it++) {
        if(!strcmp(it->sender, currentLoggedInUsername)){
        std::cout.width(100);
        std::cout.setf(ios::right);
        changeColor(1);
        std::cout<<it->messageBody<<std::endl;
        changeColor(7);
        std::cout.width(100);
        std::cout.setf(ios::right);
        std::cout<<asctime(localtime(&it->msgtime))<<std::endl;
        }else{
            std::cout<<it->sender<<": ";
            changeColor(14);
            std::cout<<it->messageBody<<std::endl;
            changeColor(15);
            std::cout<<asctime(localtime(&it->msgtime));
        }
        
   }   
}

void changeColor(int desiredColor){ 
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor); 
} 


