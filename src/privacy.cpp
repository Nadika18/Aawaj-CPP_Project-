#pragma once
#include<iostream>
#include <cstring>
#include <fstream>
#include "login.cpp"
bool check_user_exists(char username01[])
{
    std::ifstream file_pointer;
    User a;
    bool userfound= false;
    try
    {
        file_pointer.open("user.bin", std::ios::binary | std::ios::in);
        if (!file_pointer.is_open())
        {
            throw 1;
        }
        while (file_pointer.read((char *)&a, sizeof(User)))
        {
            if (!std::strcmp(username01,a.username))
            {
                userfound=true;
                break;
            }
        }
        file_pointer.close();
    }
    catch(...)
    {
        std::cout<<"User file does not exist";
    }
    return userfound;
}
void add_a_friend()
{
    char friend_username[30];
    std::cout<<"Enter the username: ";
    std::cin>>friend_username;
    bool existence= check_user_exists(friend_username);
    if (existence)
    {
        std::cout<<"You have added a new friend."<<std::endl;
    }
}
void block_a_friend()
{
    char friend_username[30];
    std::cout<<"Enter the username: ";
    std::cin>>friend_username;
    bool existence= check_user_exists(friend_username);
    if (existence)
    {
        std::cout<<"You have block a user."<<std::endl;
    }
}
void add_remove_friend()
{
    int a;
    std::cout<<"1. Add a friend"<<std::endl;
    std::cout<<"2. Block a friend"<<std::endl;
    std::cout<<"please select the required option...";
    std::cin>>a;
    switch(a)
    {
        case 1:
        std::cout<<system("CLS");
        add_a_friend();
        break;
        case 2:
        std::system("CLS");
        block_a_friend();
        break;
    }
}