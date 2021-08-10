#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include "login.cpp"
#include <cstring>
#include "home.cpp"
using std::string; using std::cout; using std::cin; using std::fstream; using std::ios;
using std::strcpy;

string path="../data/follow/";

void adduser();
void add_friend()
{
    char name_of_user[20];
    std::system("CLS");
    fstream main_filepointer;
    fstream p_follow;          //jasle follow garcha tyasko
    ofstream user_following;    //to add as following for tyo manche ko
    User a;
    bool userfound = false;
    char user_name000[20];
/*  p_follow le chahi manche le follow gare pachi tyasko following vanne folder ma add
gayera add garna lai following.bin kholcha, vane user_following le chahi tyo follow gareko manche  ko
follower vanne file kholcha ani tyasma value add garcha.  
*/

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
                strcpy(name_of_user,a.name);
                userfound = true;
                LoggedInUser.n_following++;
                p_follow.write(user_name000, sizeof(user_name000));
                user_following.open(path+name_of_user+"/followers.bin",ios::app|ios::binary);
                user_following.write(user_name000,sizeof(user_name000));
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
    std::system("CLS");
    fstream main_filepointer;
    fstream blocked_to_list;   //logged in user ko lagi block gareako ko list
    fstream blocked_by_list;     // for file of block gareko manche
    char user_name000[20];
    User a;
    bool userfound = false;
    char name_of_user[20];

    cout<<"\n\n\nEnter the username: ";
    cin>>user_name000;

    main_filepointer.open(path+LoggedInUser.name+"/blocked_to.bin", std::ios::binary | std::ios::in);

    if (main_filepointer.is_open())
    {
        while (main_filepointer.read((char*)&a, sizeof(User)))
        {
            if (!std::strcmp(user_name000,a.username))
            {
                strcpy(name_of_user,a.name);
                userfound = true;
                LoggedInUser.n_following++;
                blocked_to_list.write(user_name000, sizeof(user_name000));
                blocked_by_list.open(path+name_of_user+"/blocked_by.bin",ios::app|ios::binary);
                blocked_by_list.write(user_name000,sizeof(user_name000));
                break;
            }
        }
        blocked_by_list.close();
        blocked_to_list.close();
        main_filepointer.close();
    }
    if (userfound)
    {
        std::cout<<user_name000<<" has been block successfully!!!\n";
    }
    else 
    {
        std::cout<<"No user with username: "<<user_name000<<" exists!.";
    }
}
void adduser()
{
    int answer;
    cout<<std::setw(67)<<"PRIVACY\n";
    cout<<"1. Add a friend.\n";
    cout<<"2. Block a friend.\n";
    cout<<"3. Exit\n";
    cout<<"Enter the required option...";
    cin>>answer;
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