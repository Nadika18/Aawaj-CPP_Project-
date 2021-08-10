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
class posts{
    protected:
    char postId;
    char author[20];
    char commenter[20];
    char postBody[250];
    time_t posttime;
    
    public:
    posts(){}
    posts(char rec[],char msgbody[]){
        strcpy(author, currentLoggedInUsername);
        strcpy(commenter, rec);
        strcpy(postsBody,msgbody);
        posttime= getCurrentTime();
        
    }
    posts(char sen[]){
        strcpy(author, sen);
        strcpy(commenter, currentLoggedInUsername);
        posttime= getCurrentTime();
        
    }
    posts(char postbody[]){
       strcpy(author, currentLoggedInUsername); 
       strcpy(postBody,postbody);
       posttime= getCurrentTime();
      
    }
    time_t getCurrentTime(){
        time_t t; // t passed as argument in function time()
        struct tm * tt; // decalring variable for localtime()
        time (&t); //passing argument to time()
        return t;
    }
    char *showposttime(){
    time_t t; // t passed as argument in function time()
    struct tm * tt; // decalring variable for localtime()
    time (&t); //passing argument to time()
    tt = localtime(&t);
    return asctime(tt);
    };
    void sendposts(){
        
        string path="../data/posts/";
        string extension= ".bin";
        string aut(author), id(postId);
        fstream authorFile;
        authorFile.open((path+aut+"/"+id+extension).c_str(), ios::app);
        authorFile.write((char *)this, sizeof(posts));
        authorFile.close();
        fstream databasefile;
        databasefile.open((path+rec+"/database.bin").c_str(),ios::app);
        databasefile<<author<<endl;
                
    }
    bool operator < (const posts& str) const
    {
        return (posttime < str.posttime);
    }
    friend void viewposts(posts &);
    
    friend ostream& operator<<(ostream &out,posts &p);

};

void changeColor(int);

void viewauthors(){
    char p[20];
    string path="../data/posts/";
    string rec(currentLoggedInUsername);
    fstream databasefile;
    databasefile.open((path+rec+"/database.bin").c_str(),ios::in);
    cout<<"Inbox:"<<endl;
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
        cout << *itr<<" "<<endl;
    }
    cout<<endl;
    cout<<"Whose post would you like to view ?"<<endl;
    cout<<endl;
    databasefile.close();
}


void viewpost(post &p){
    vector<posts> v;
    fstream authorFile;
    string path="../data/posts/";
    string extension= ".bin";
    string sdr(p.author), rec(p.commenter);
    authorFile.open((path+rec+"/"+sdr+extension).c_str(), ios::in);
    while(authorFile.read((char *)&p, sizeof(p))){
        v.push_back(p);
    }
    
    authorFile.close();
    
    fstream commenterFile;
    posts m(p.author,0);
    commenterFile.open((path+sdr+"/"+rec+extension).c_str(),ios::in);
    while(commenterFile.read((char *)&m , sizeof(m))){
        v.push_back(m);
    }
    commenterFile.close();
    std::sort(v.begin(), v.end());
   for(auto it = v.begin(); it != v.end(); it++) {
        if(!strcmp(it->author, currentLoggedInUsername)){
        cout.width(100);
        cout.setf(ios::right);
        changeColor(1);
        cout<<it->postBody<<endl;
        changeColor(7);
        cout.width(100);
        cout.setf(ios::right);
        cout<<asctime(localtime(&it->posttime))<<endl;
        }else{
            cout<<it->author<<": ";
            changeColor(14);
            cout<<it->postBody<<endl;
            changeColor(15);
            cout<<asctime(localtime(&it->posttime));
        }
        
   }   
}

void changeColor(int desiredColor){ 
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor); 
} 


