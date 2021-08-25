#pragma once
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <cstring>
#include <windows.h>
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
    // yo bujhena
    time_t getCurrentTime(){
        time_t t; // t passed as argument in function time()
        struct tm * tt; // decalring variable for localtime()
        time (&t); //passing argument to time()
        return t;
    }   
    char *showMsgTime(){
        time_t t; // t passed as argument in function time()
        struct tm * tt; // decalring variable for localtime() --here tt is a variable for local time.
        time (&t); //passing argument to time()
        tt = localtime(&t);
        return asctime(tt); 
    }

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
        databasefile<<sender<<endl;
                
    }
    bool operator < (const message& str) const
    {
        return (msgtime < str.msgtime);
    }
    friend void viewmessage(message &);
};

void changeColor(int);
void viewsenders(){
    char p[20];
    string path="../data/messages/";
    string rec(currentLoggedInUsername);
    fstream databasefile;
    databasefile.open((path+rec+"/database.bin").c_str(),ios::in);
    cout<<"Inbox:"<<endl;
    set<string, greater<string>>s1; //remain //declare
    while(!databasefile.eof()){
    databasefile>>p;
    string s(p);
    s1.insert(s);
    }
    // printing set s1
    set<string, greater<string>>::iterator itr;
    for (itr = s1.begin(); itr != s1.end(); itr++)
    {
        cout << *itr<<" "<<endl;
    }
    cout<<endl;
    cout<<"Whose message would you like to view ?"<<endl;
    cout<<endl;
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
    std::sort(v.begin(), v.end());  //sorting in vector
    for(auto it = v.begin(); it != v.end(); it++) {
        if(!strcmp(it->sender, currentLoggedInUsername)){
        cout.width(100);
        cout.setf(ios::right);
        changeColor(1);
        cout<<it->messageBody<<endl;
        changeColor(7);
        cout.width(100);
        cout.setf(ios::right);
        cout<<asctime(localtime(&it->msgtime))<<endl;
        }else{
            cout<<it->sender<<": ";
            changeColor(14);
            cout<<it->messageBody<<endl;
            changeColor(15);
            cout<<asctime(localtime(&it->msgtime));
        }
        
   }   
}

void changeColor(int desiredColor){ 
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor); 
} 


