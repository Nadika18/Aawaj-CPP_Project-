#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "message.cpp"
#include "login.cpp"


extern char currentLoggedInUsername[20];
extern bool isLoggedIn, isUser;
extern User LoggedInUser;


int main()
{
    std::system("CLS");
    //Register();
menu:
    std::cout<<"1. Register"<<std::endl;
    std::cout<<"2. Login"<<std::endl;
    std::cout<<"3. Message"<<std::endl;
    std::cout<<"4. Exit"<<std::endl;
     std::cout<<"5. Inbox"<<std::endl;
    std::cout<<"Press the required option 1, 2, 3...."<<std::endl;
    int i;
    std::cin>>i;
    switch(i){
        case 1:
        std::system("CLS");
        Register();
        goto menu;
        break;
        case 2:
        std::system("CLS");
        char usr[20];
        char pwd[20];
        std::cout<<"enter username"<<std::endl;
        std::cin>>usr;
        std::cout<<"enter password"<<std::endl;
        std::cin>>pwd;
        login(usr,pwd);
        if(isLoggedIn){
        std::cout<<"Successfully Logged In!!!!!!!!!"<<std::endl;
        std::cout<<std::endl;
        std::cout<<std::endl;
        std::cout<<LoggedInUser;
        goto menu;
        break;
        case 3:
        if(!isLoggedIn){
            std::cout<<"Login first"<<std::endl;
            goto menu;
        }else{
            std::system("CLS");
            std::cout<<"Enter the username of receiver"<<std::endl;
            char receiver[20];
            std::cin>>receiver;
            char msgbody[250];
            std::cout<<"Enter the msg body"<<std::endl;
            std::cin.ignore();
            std::cin.getline(msgbody,150);
            message msg(receiver,msgbody);
            msg.sendMessage();
            
        break;    
        }
        case 5:
        if(!isLoggedIn){
            std::cout<<"Login first"<<std::endl;
            goto menu;
        }else{
            std::system("CLS");
            char sender[20]; 
            viewsenders();
            cin>>sender;
            message m(sender);
            std::system("CLS");
            viewmessage(m);

        }
        case 4:
        exit(0);
    }

    };
    
    return 0;
}