#pragma once
#include <iostream>
#include "message.cpp"
#include "login.cpp"
#include "userprofile.cpp"
#include "add_user.cpp"

void call_home()
{
menu:
    int i;
    std::cout<<"1. Friends"<<std::endl;
    std::cout<<"2. Post"<<std::endl;
    std::cout<<"3. Message"<<std::endl;
    std::cout<<"4. User Profile"<<std::endl;
    std::cout<<"5. Logout"<<std::endl;
    std::cout<<"Select the required optiton";
    std::cin>>i;
    switch(i)
    {
        case 1:
            //adduser();
            break;
        case 2:
            std::system("CLS");
        //message_user();
            break;
        case 3:
        message:
        {
        std::cout<<"1. Send Message"<<endl;
        std::cout<<"2. View Inbox"<<endl;
        std::cout<<"3. Exit"<<endl;
        int z;
        cin>>z;
        switch(z)
            {
            case 1:
                {
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
                    goto message;
                }
                break; 
            case 2:
                {
                    std::system("CLS");
                    char sender[20]; 
                    viewsenders();
                    cin>>sender;
                    message m(sender);
                    std::system("CLS");
                    viewmessage(m);
                    goto message;
                }
                break;
            case 3:
                call_home();
                break;
            case 4:
                std::system("CLS");
                cout<<"This is called";
                display_profile();
                break;
            case 5:
                goto menu;
                //call_home();
                break;
            }
        }
    }
}
