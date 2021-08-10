#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include "login.cpp"
#include <cstring>
void add_friend()
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
                LoggedInUser.n_following++;
                LoggedInUser.name_of_following[LoggedInUser.n_following]=user_name000;
                break;
            }
        }
        filepointer.close();
    }
    if (userfound)
    {
        std::cout<<user_name000<<" has been added successfully!!!\n";
    }
    else 
    {
        std::cout<<"No user with username: "<<user_name000<<" exists!.";
    }
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
}
void adduser()
{
    int answer;
    std::cout<<std::setw(67)<<"PRIVACY\n";
       std::cout << "\t\t" <<char(218);  for(int i=0; i<20; i++){std::cout << char(196);}  std::cout << char(191) << std::endl;
std::cout <<"\t\t" << char(179) << "   1.Add a friend   " << char(179) << std::endl;

std::cout << "\t\t" <<char(195);  for(int i=0; i<20; i++){std::cout << char(196);}  std::cout << char(180)  << std::endl;
std::cout << "\t\t" <<char(179) << "   2.Block a friend " << char(179) << std::endl;
std::cout << "\t\t"<< char(195);  for(int i=0; i<20; i++){std::cout << char(196);}  std::cout << char(180)  << std::endl;
std::cout << "\t\t" <<char(179) << "   3.Exit           " << char(179) << std::endl;
std::cout << "\t\t" <<char(192);  for(int i=0; i<20; i++){std::cout << char(196);}   std::cout << char(217) << std::endl;
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