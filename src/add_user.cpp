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
void block_friend()
{

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