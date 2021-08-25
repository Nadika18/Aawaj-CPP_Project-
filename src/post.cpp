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
    int postId;
    char author[20];
    char postBody[250];
    time_t posttime;
    
    public:
    posts(){};
    posts(char postbody[]){
       strcpy(author, currentLoggedInUsername); 
       strcpy(postBody,postbody);
       posttime= getCurrentTime();

    }
    posts(char postbody[], int i){
        postId=getNewPostId();
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
    int getNewPostId(){
        fstream postfile;
        postfile.open("../data/posts/post.bin", ios::in | ios::ate);
        if(postfile.is_open() && postfile.tellg()!= 0){
        postfile.seekg(-sizeof(posts), ios::cur);
        posts a;
        postfile.read((char *)&a, sizeof(posts));
        postfile.close();
        return a.postId +1 ; 
        }
        postfile.close();
        return 1; 
    }
    void sendPosts(){
        fstream postfile;
        postfile.open("../data/posts/post.bin", ios::app);
        postfile.write((char *)this, sizeof(posts));
        postfile.close();
        string postId3;
        postId3= to_string(this->postId); //converting integer to string
        string extension= ".bin";
        fstream commentfile;
        commentfile.open(("../data/posts/"+postId3+extension).c_str(), ios::app);
        commentfile.close();  
    }
    bool operator < (const posts& str) const
    {
        return (posttime < str.posttime);
    }
    friend void viewPosts();
    friend void viewOwnPosts();
    
};

void changeColorr(int desiredColor){ 
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor); 
} 
void viewPosts(){
    posts p;
    vector<posts> v;
    fstream postfile;
    fstream commentfile;
    postfile.open("../data/posts/post.bin", ios::in);
    while(postfile.read((char *)&p, sizeof(posts))){
        v.push_back(p);
    };
    postfile.close();
    std::sort(v.begin(), v.end());  //sort acq posttime
    for(auto it = v.begin(); it != v.end(); it++) {
        cout<<it->author<<": "<<endl;
        changeColorr(14);
        cout<<it->postBody<<endl;
        changeColorr(15);
        cout<<asctime(localtime(&it->posttime));
        cout<<endl;
        string postId2;
        postId2= to_string(it->postId);
        string extension= ".bin";
        try{
            commentfile.open(("../data/posts/"+postId2+extension).c_str(), ios::in);
        if(!commentfile.is_open()){
            throw 1;
        }else{
        posts a;
        while(commentfile.read((char *)&a, sizeof(posts))){
            cout<<a.author<<": ";
            changeColorr(12);
            cout<<a.postBody<<endl;
            changeColorr(15);
            cout<<asctime(localtime(&a.posttime));
            cout<<endl;
           };
        
        }
        commentfile.close();
        }catch(int e){
            cout<<"There are not any comments"<<endl;
        }
        char ans;
        cout<<"Comment y/n?"<<endl;
        cin>>ans;
        if(ans == 'y'){
        commentfile.open(("../data/posts/"+postId2+extension).c_str(), ios::app);
        cout<<"Write a comment"<<endl;
        char comment[150];
        std::cin.ignore();
        std::cin.getline(comment,150);
        posts c(comment);
        commentfile.write((char *)&c, sizeof(posts));
        }
        commentfile.close();
        }
    }
