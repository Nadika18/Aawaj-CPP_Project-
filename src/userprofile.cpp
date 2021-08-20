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

using std::cout;    using std::fstream;
using std::cin;     using std::ios;
using std::endl;
using std::string;
using std::set;

User universal_user;
string path="../data/follow/";

void display_photo(){
       std:: ifstream file("my.txt");
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

void display_profile()
{
    int answer;
    cout<<"\n\n\n\n";
    cout.fill(' ');
    cout.width(60);    
    cout<<"Welcome "<<LoggedInUser.username<<"!!!\n";
    cout.setf(ios::left);
    cout.width(40);
    cout.fill(' ');
    cout<<" ";
    cout.setf(ios::left);
    cout.width(50);
    cout.fill('_');
    cout<<"_";
        display_photo();
    cout<<endl<<endl<<endl;
    std::cout<<std::endl<<std::endl<<std::endl;

    //std::cout<<"Do you want to view the usernames of your friends?\n ";
       std::system("CLS");std::cout << "\t\t" <<char(218);  for(int i=0; i<20; i++){std::cout << char(196);}  std::cout << char(191) << std::endl;
std::cout <<"\t\t" << char(179) << "   1.Followers      " << char(179) << std::endl;

std::cout << "\t\t" <<char(195);  for(int i=0; i<20; i++){std::cout << char(196);}  std::cout << char(180)  << std::endl;
std::cout << "\t\t" <<char(179) << "   2.Followings      " << char(179) << std::endl;

std::cout << "\t\t" <<char(195);  for(int i=0; i<20; i++){std::cout << char(196);}  std::cout << char(180)  << std::endl;
std::cout << "\t\t" <<char(179) << "   3.Blocked Users   " << char(179) << std::endl;

std::cout << "\t\t" <<char(195);  for(int i=0; i<20; i++){std::cout << char(196);}  std::cout << char(180)  << std::endl;
std::cout << "\t\t" <<char(179) << "   4.Exit            " << char(179) << std::endl;

std::cout << "\t\t" <<char(192);  for(int i=0; i<20; i++){std::cout << char(196);}   std::cout << char(217) << std::endl;
    
    cout<<"\nYour choice: ";
    cin>>answer;
    switch(answer)
    {
        case 1:
            std::system("CLS");
            //cout<<"This is called";
            view_followers();
            break;
        case 2:
            std::system("CLS");
            view_following();
            break;
        case 3:
            std::system("CLS");
            blocked_people();
            break;
        default:
            exit(0);
    }
}