#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include "login.cpp"
#include <cstring>

using std::string; using std::cout; using std::cin; using std::fstream; using std::ios;
using std::strcpy;
 
//void adduser();
void add_friend()
{

    char name_of_user[20];
    string path= "../data/follow/";
    std::system("CLS");
    fstream main_filepointer;
    fstream p_follow;          
    std::ofstream user_following;    
    User a;
    bool userfound = false;
    char user_name000[20];


    main_filepointer.open("user.bin", std::ios::binary | std::ios::in);
    p_follow.open((path+LoggedInUser.name+"/following.bin").c_str(),ios::app | ios::binary);

    std::cout<<"\n\n\nEnter the username: ";
    std::cin>>user_name000;
    if (main_filepointer.is_open())
    {
        while (main_filepointer.read((char*)&a, sizeof(User)))
        {
            if (!std::strcmp(user_name000,a.username))
            {
                name_foll n_foll(LoggedInUser.username);
                name_foll name_of_friend(user_name000);
                strcpy(name_of_user,a.name);
                userfound = true;
                p_follow.write(reinterpret_cast<char*>(&name_of_friend),sizeof(name_of_friend));
                user_following.open((path+name_of_user+"/followers.bin").c_str(),ios::app|ios::binary);
                user_following.write(reinterpret_cast<char*>(&n_foll),sizeof(n_foll));
                break;
            }
        }
        user_following.close();
        p_follow.close();
        main_filepointer.close();
    }
    if (userfound)
    {
        cout<<user_name000<<" has been added successfully!!!\n";
    }
    else 
    {
        cout<<"No user with username: "<<user_name000<<" exists!.";
    }
    p_follow.close();
}

void block_friend()
{
    string path= "../data/follow/";
    std::system("CLS");
    fstream main_filepointer;
    fstream blocked_to_list;   // list of user who blocked logged in user 
    fstream blocked_by_list;     // for file of blocked people
    char user_name000[20];
    User a;
    bool userfound = false;
    char name_of_user[20];

    cout<<"\n\n\nEnter the username: ";
    cin>>user_name000;

    main_filepointer.open("user.bin", std::ios::binary | std::ios::in);
    blocked_to_list.open((path+currentLoggedInUsername+"/blocked_to.bin").c_str(), std::ios::binary | std::ios::app);
    
    if (main_filepointer.is_open())
    {
        while (main_filepointer.read((char*)&a, sizeof(User)))
        {
            if (!std::strcmp(user_name000,a.username))
            {
                strcpy(name_of_user,a.name);
                userfound = true;
                name_foll n_foll(LoggedInUser.username);
                name_foll name_of_friend(user_name000);
                blocked_to_list.write(reinterpret_cast<char*>(&name_of_friend),sizeof(name_of_friend));
                blocked_by_list.open((path+name_of_user+"/blocked_by.bin").c_str(),ios::app|ios::binary);
                blocked_by_list.write(reinterpret_cast<char*>(&n_foll),sizeof(n_foll));
                break;
            }
        }
        blocked_by_list.close();
        blocked_to_list.close();
        main_filepointer.close();
    }
    if (userfound)
    {
        std::cout<<user_name000<<" has been blocked successfully!!!\n\n";
    }
    else 
    {
        std::cout<<"No user with username: "<<user_name000<<" exists!.\n\n";
    }
}

