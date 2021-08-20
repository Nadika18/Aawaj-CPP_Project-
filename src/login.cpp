#pragma once
#include <iostream>
#include <fstream>
#include <process.h>
#include <dir.h>
#include <cstring>
#include <cstring>
#include <string>
enum usertype
{
    admin,
    user
};
char currentLoggedInUsername[20];
bool isLoggedIn, isUser;

class Person
{
protected:
    char name[20];
    int age;
    char username[20];
    char password[20];
};

class Admin : public Person
{
public:
    friend std::ifstream &operator>>(std::ifstream &, Admin);
    friend std::ofstream &operator<<(std::ofstream &, Admin);
};

class User : public Person
{
protected: 
public:
    friend std::ifstream &operator>>(std::ifstream &, User &);
    friend std::ofstream &operator<<(std::ofstream &, User &);
    friend std::istream &operator>>(std::istream &, User &);
    friend std::ostream &operator<<(std::ostream &, User &);
    void operator=(User &a)
    {
        std::strcpy(name,a.name);
        age = a.age;
        std::strcpy(username,a.username);
        std::strcpy(password,a.password);
    }
    friend bool Register();
    friend bool login(char [], char [], usertype);
    friend void add_friend();
    friend void block_friend();
    friend void display_profile();
    friend void view_followers();
    friend void view_following();
    friend void view_posts();
    friend void blocked_people();
};


User LoggedInUser;

std::ifstream &operator>>(std::ifstream &ifile, User &p)
{
    ifile.read((char *)&p, sizeof(p));
    return ifile;
};

std::istream &operator>>(std::istream &ifile, User &p)
{
     std::cout << "\t\t" <<char(218);  for(int i=0; i<25; i++){std::cout << char(196);}  std::cout << char(191) << std::endl;
std::cout <<"\t\t" << char(179) << "  Enter your name :      " << char(179) << std::endl;
std::cout << "\t\t" <<char(192);  for(int i=0; i<25; i++){std::cout << char(196);}   std::cout << char(217) << std::endl;
std::cin >> p.name;
std::cout << "\t\t" <<char(218);  for(int i=0; i<25; i++){std::cout << char(196);}  std::cout << char(191) << std::endl;
std::cout << "\t\t" <<char(179) << "  Enter your age      :  " << char(179) << std::endl;
std::cout << "\t\t" <<char(192);  for(int i=0; i<25; i++){std::cout << char(196);}   std::cout << char(217) << std::endl;
std::cin >> p.age;
std::cout << "\t\t" <<char(218);  for(int i=0; i<25; i++){std::cout << char(196);}  std::cout << char(191) << std::endl;
std::cout << "\t\t" <<char(179) << "  Enter your username :  " << char(179) << std::endl;
std::cout << "\t\t" <<char(192);  for(int i=0; i<25; i++){std::cout << char(196);}   std::cout << char(217) << std::endl;
std::cin >> p.username;
 std::cout << "\t\t" <<char(218);  for(int i=0; i<25; i++){std::cout << char(196);}  std::cout << char(191) << std::endl;
std::cout << "\t\t" <<char(179) << "  Enter your password:   " << char(179) << std::endl;
std::cout << "\t\t" <<char(192);  for(int i=0; i<25; i++){std::cout << char(196);}   std::cout << char(217) << std::endl;
std::cin >> p.password;
    return ifile;
};
std::ostream &operator<<(std::ostream &out, User &p)
{
    std::cout << p.name << std::endl;
    std::cout << p.age<< std::endl;
    std::cout << p.username<< std::endl;
    std::cout << p.password<< std::endl;
    return out;
};

std::ofstream &operator<<(std::ofstream &ofile, User &p)
{
    ofile.write((char *)&p, sizeof(p));
    return ofile;
};
bool login(char username[], char password[], usertype a = user)
{
    std::ifstream userfile;
    try
    {
        userfile.open("user.bin", std::ios::binary | std::ios::in);
        if (!userfile.is_open())
            throw 1;
        User a;
        bool userfound = false;
        while (userfile.read((char *)&a, sizeof(User)))
        {
            if (!std::strcmp(username,a.username))
            {
                userfound = true;
                break;
            }
        }
        userfile.close();
        if (!userfound)
        {
            std::cout << "User not found, check your username or register" << std::endl;
            return false;
        }
        if (!std::strcmp(password,a.password))
        {
            std::strcpy(currentLoggedInUsername,a.username);
            isLoggedIn = true;
            LoggedInUser = a;

            return true;
        }else{
            std::cout<<"Wrong Password"<<std::endl;
            std::cout<<"Please login with correct credential or register"<<std::endl;
        }
    }
    catch (...)
    {
        std::cout << "No user file exists" << std::endl;
        std::cout << "Be sure to register first" << std::endl;
    }
    return false;
};

bool Register()
{
    User p;
    std::fstream userfile;
    std::cin >> p;
check:
    userfile.open("user.bin", std::ios::binary | std::ios::in);
    User a;
    bool userfound = false;
    if (userfile.is_open())
    {
        while (userfile.read((char*)&a, sizeof(User)))
        {
            if (!std::strcmp(p.username,a.username))
            {
                userfound = true;
                break;
            }
        }
        userfile.close();
    }
    if (userfound)
    {
        
        std::cout << "User with the given username already exists" << std::endl;
        std::cout << "\t\t" <<char(218);  for(int i=0; i<25; i++){std::cout << char(196);}  std::cout << char(191) << std::endl;
        std::cout << "\t\t" <<char(179) << "  Enter your username :  " << char(179) << std::endl;
        std::cout << "\t\t" <<char(192);  for(int i=0; i<25; i++){std::cout << char(196);}   std::cout << char(217) << std::endl;
        std::cin >> p.username;
        goto check;
    }
    else
    {
        userfile.open("user.bin", std::ios::app);
        userfile.write((char *)&p, sizeof(User));
        std::string path="../data/messages/";
        mkdir((path+p.username).c_str());
        std::string path1="../data/follow/";
        mkdir((path1+p.username).c_str());

        return true;
    }
    return false;
};

class name_foll
{
    private:
        char nnamm[20];
    public:
        name_foll() {};
        name_foll(char a[20])
        {
            std::strcpy(nnamm,a);
        }
        void display()
        {   
            std::cout<<nnamm<<std::endl;
        }
        friend bool check_user(char []);
};
bool check_user(char usernamee[])
{
    std::string path= "../data/follow/";
    std::fstream to_check_for_block;
    bool userfoundd = false;
    try 
        {
            to_check_for_block.open((path+currentLoggedInUsername+"blocked_by.bin").c_str(), std::ios::binary | std::ios::in);
            if (!to_check_for_block.is_open())
                throw 1;
            name_foll a;
            
            while (to_check_for_block.read((char *)&a, sizeof(name_foll)))
            {
                if (!std::strcmp(usernamee,a.nnamm))
                {
                    userfoundd = true;
                    break;
                }
            }
            }
            catch (...)
            {
                std::cout << "No user file exists" << std::endl;
                
            }
        return userfoundd;
}