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
        databasefile.seekp(0,ios::beg);
        databasefile<<sender<<endl;
        databasefile.close();
    }
    friend void viewmessage(message &);
    
    friend ostream& operator<<(ostream &out,message &p);

};
void removeID() {
    std::string ID;
    cin >> ID; //id of the line we want to delete
    ifstream read("infos.txt");
    ofstream write("tmp.txt"); 
    if (read.is_open()) {
       std::string line;
       while (getline(read, line)) {
          if (line.find(ID) != std::string::npos)
             write << line;
       }
    } else {
       std::cerr << "Error: coudn't open file\n";
       /* additional handle */
    }

    read.close();
    write.close();
    std::remove("infos.txt");
    std::rename("tmp.txt", "infos.txt");
}
void changeColor(int);

void viewsenders(){
    char p[20];
    string path="../data/messages/";
    string rec(currentLoggedInUsername);
    fstream databasefile;
    databasefile.open((path+rec+"/database.bin").c_str(),ios::in);
    cout<<"Inbox:"<<endl;
    while(!databasefile.eof()){
    databasefile>>p;
    cout<<p<<endl;
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
    cout<<v.size()<<endl;
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


