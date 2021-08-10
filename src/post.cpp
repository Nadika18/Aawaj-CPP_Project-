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
    static int postId;
    char author[20];
    char commenter[20];
    char postBody[250];
    time_t posttime;
    
    public:
    posts(){};
    posts(char postbody[]){
       strcpy(author, currentLoggedInUsername); 
       strcpy(postBody,postbody);
       posttime= getCurrentTime();
       postId++;
      
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
    void sendPosts(){
        fstream postfile;
        postfile.open("../data/posts/post.bin", ios::app);
        postfile.write((char *)this, sizeof(posts));
        postfile.close();
    }
    bool operator < (const posts& str) const
    {
        return (posttime < str.posttime);
    }
    friend void viewPosts();
    
};
int posts::postId;
void changeColorr(int desiredColor){ 
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor); 
} 
void viewPosts(){
    posts p;
    vector<posts> v;
    fstream postfile;
    postfile.open("../data/posts/post.bin", ios::in);
    while(postfile.read((char *)&p, sizeof(posts))){
        v.push_back(p);
    };
    fstream commentfile;
    commentfile.close();
    commentfile.open("../data/posts/comments.bin", ios::app);
    std::sort(v.begin(), v.end());
    for(auto it = v.begin(); it != v.end(); it++) {
        cout<<it->author<<": "<<endl;
        changeColorr(14);
        cout<<it->postBody<<endl;
        changeColorr(15);
        cout<<asctime(localtime(&it->posttime));
        cout<<endl;
        char ans;
        cout<<"View Comments: y/n ?"<<endl;
        cin>>ans;
        if(ans == 'y'){
           while(commentfile.read((char *)&p, sizeof(posts))){
               cout<<p.author<<": ";
                changeColor(14);
                cout<<p.postBody<<endl;
                changeColor(15);
                cout<<asctime(localtime(&p.posttime));
           };     
        }
    }
    commentfile.close();
    }