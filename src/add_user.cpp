#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include "login.cpp"
#include <cstring>
#include "home.cpp"
using std::string; using std::cout; using std::cin; using std::fstream; using std::ios;

void adduser();
void add_friend()
{
    std::system("CLS");
    string path="../data/follow/";
    //string extension=".bin";
    fstream main_filepointer;
    fstream p_follow;
    User a;
    bool userfound = false;
    char user_name000[20];
        
    main_filepointer.open("user.bin", std::ios::binary | std::ios::in);
    p_follow.open((path+LoggedInUser.name+"/follower.bin").c_str(),ios::app | ios::binary);
    
    std::cout<<"\n\n\nEnter the username: ";
    std::cin>>user_name000;

    if (main_filepointer.is_open())
    {
        while (main_filepointer.read((char*)&a, sizeof(User)))
        {
            if (!std::strcmp(user_name000,a.username))
            {
                userfound = true;
                LoggedInUser.n_following++;
                LoggedInUser.name_of_following[LoggedInUser.n_following]=user_name000;
                p_follow.write(user_name000, sizeof(user_name000));
                break;
            }
        }
        p_follow.close();
        main_filepointer.close();
    }
    if (userfound)
    {
        std::cout<<user_name000<<" has been added successfully!!!\n";
    }
    else 
    {
        std::cout<<"No user with username: "<<user_name000<<" exists!.";
    }
    p_follow.close();
    call_home();
}

void block_friend()
{
    std::fstream filepointer;
    char user_name000[20];
    std::system("CLS");
    std::cout<<"\n\n\nEnter the username: ";
    std::cin>>user_name000;
    filepointer.open("user.bin", std::ios::binary | std::ios::in);
    User a;
    bool userfound = false;
    if (filepointer.is_open())
    {
        while (filepointer.read((char*)&a, sizeof(User)))
        {
            if (!std::strcmp(user_name000,a.username))
            {
                
                userfound = true;
                break;
            }
        }
        filepointer.close();
    }
    if (userfound)
    {
        std::cout<<user_name000<<" has been block successfully!!!\n";
    }
    else 
    {
        std::cout<<"No user with username: "<<user_name000<<" exists!.";
    }
    call_home();
}
void adduser()
{
    int answer;
    std::cout<<std::setw(67)<<"PRIVACY\n";
    std::cout<<"1. Add a friend.\n";
    std::cout<<"2. Block a friend.\n";
    std::cout<<"3. Exit\n";
    std::cout<<"Enter the required option...";
    std::cin>>answer;
    switch(answer)
    {
        case 1:
        add_friend();
        break;
        case 2:
        block_friend();
        break;
        default:
        exit(0);
        break;
    }
}