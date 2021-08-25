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
#include "post.cpp"

using std::cout;    using std::fstream;
using std::cin;     using std::ios;
using std::endl;
using std::string;
using std::set;

User universal_user;
string path="../data/follow/";

void display_photo(){
       std:: ifstream file("../data/my.txt");
if (file.is_open())
{	
    std::string line;
	while (getline(file, line))
    {  
    	std::cout << line << std::endl;
    }
}
}

void view_followers()
{   
    fstream p_view_follow;
    name_foll n;
    p_view_follow.open((path+LoggedInUser.name+"/followers.bin").c_str(),ios::in|ios::binary);
    if (p_view_follow)
    {
        set<string> s1;
        while(!p_view_follow.eof()){
        p_view_follow.read(reinterpret_cast<char*>(&n),sizeof(name_foll));
        string s(n.nnamm);
        s1.insert(s);
    }
    // printing set s1
    set<string>::iterator itr;
    cout<<"The people who follow you: "<<endl;
    for (auto itr = s1.begin(); itr != s1.end(); itr++)
    {
        cout<<*itr<<endl;
        cout<<endl;
    }
    cout<<endl;
       
        p_view_follow.close();    
    }
    else
    {
        cout<<"You dont have any followers!!.";
    }   
}

void view_following()
{
    fstream p_view_follow;
    name_foll n;
    p_view_follow.open((path+LoggedInUser.name+"/following.bin").c_str(),ios::in|ios::binary);
    if (p_view_follow)
    {
        set<string> s1;
        while(!p_view_follow.eof()){
        p_view_follow.read(reinterpret_cast<char*>(&n),sizeof(name_foll));
        string s(n.nnamm);
        s1.insert(s);
    }
    // printing set s1
    set<string>::iterator itr;
    cout<<"The people you follow are: "<<endl;
    for (auto itr = s1.begin(); itr != s1.end(); itr++)
    {
        cout<<*itr<<endl;
        cout<<endl;
    }
    cout<<endl;
       
        p_view_follow.close();    
    }
    else
    {
        cout<<"You dont follow anyone!!";
    }  
}

void blocked_people()
{
    fstream p_view_blocked;
    name_foll n;
    p_view_blocked.open((path+LoggedInUser.name+"/blocked_to.bin").c_str(),ios::in|ios::binary);
    if (p_view_blocked)
    {
        set<string> s1;
        while(!p_view_blocked.eof()){
        p_view_blocked.read(reinterpret_cast<char*>(&n),sizeof(name_foll));
        string s(n.nnamm);
        s1.insert(s);
    }
    // printing set s1
    set<string>::iterator itr;
    cout<<"The people you have blocked are: \n"<<endl;
    for (auto itr = s1.begin(); itr != s1.end(); itr++)
    {
        cout<<*itr<<endl;
        cout<<endl;
    }
    cout<<endl;
       
        p_view_blocked.close();    
    }
    else
    {
        cout<<"You have not blocked anyone.";
    }  
}


