#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "message.cpp"
#include "login.cpp"
#include "add_user.cpp"
#include "userprofile.cpp"
#include "post.cpp"

extern char currentLoggedInUsername[20];
extern bool isLoggedIn, isUser;
extern User LoggedInUser;
extern char current_user_username[20];
extern void call_home();
extern void adduser();

int main()
{
menu:
    std::system("CLS");
    std::cout<<"1. Register"<<std::endl;
    std::cout<<"2. Login"<<std::endl;
    std::cout<<"3. Exit"<<std::endl;
    std::cout<<"Press the required option 1, 2, 3...."<<std::endl;
    int i;
    std::cin>>i;
    switch(i){
        case 1:
        {
            std::system("CLS");
            Register();
            goto menu;
            break;
        }
        case 2:
        {            
            std::system("CLS");
            char usr[20];
            char pwd[20];
            std::cout<<"enter username"<<std::endl;
            std::cin>>usr;
            std::cout<<"enter password"<<std::endl;
            std::cin>>pwd;
            login(usr,pwd);
            if(isLoggedIn)
            {
                std::cout<<"Successfully Logged In!!!!!!!!!"<<std::endl;
            }
            goto home;
            break;
        }
        case 3:
            exit(0);
    }
    home:
    {
        {
    std::system("CLS");
    std::cout<<"1. Privacy"<<std::endl;
    std::cout<<"2. Post"<<std::endl;
    std::cout<<"3. Message"<<std::endl;
    std::cout<<"4. User Profile"<<std::endl;
    std::cout<<"5. Logout"<<std::endl;
    std::cout<<"Select the required optiton";
    std::cin>>i;
        }
    switch(i)
    {
        case 1:
            std::system("CLS");
            adduser();
            std::getchar();
            goto home;
            break;
        case 2:
        post:
        {
        std::system("CLS");
        std::cout<<"1. Write Post"<<endl;
        std::cout<<"2. View Posts"<<endl;
        std::cout<<"3. Exit"<<endl;
        int y;
        cin>>y;
        {
        switch(y){
            case 1:
            {
            std::system("CLS");
            char postbody[250];
            std::cout<<"Enter the post body"<<std::endl;
            std::cin.ignore();
            std::cin.getline(postbody,150);
            posts post(postbody,1);
            post.sendPosts();
            goto post;
            break; 
            }
            case 2:
            {
            std::system("CLS");
            viewPosts();
            char c;
            cout<<"Press c to contine"<<endl;
            cin>>c;
            goto post;
            break;
            }
            case 3:
            goto home;
            }

        }
        break;
        }

            break;
        case 3:
        message:
        {
        std::system("CLS");
        std::cout<<"1. Send Message"<<endl;
        std::cout<<"2. View Inbox"<<endl;
        std::cout<<"3. Exit"<<endl;
        int z;
        cin>>z;
        {
        switch(z){
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
            break; 
            }
            case 2:
            {
            std::system("CLS");
            char sender[20]; 
            viewsenders();
            cin>>sender;
            message m(sender);
            std::system("CLS");
            viewmessage(m);
            cout<<"Press c key to continue"<<endl;
            char n;
            cin>>n;
            goto message;
            break;
            }
            case 3:
            goto home;
        }

        }
        break;
        }
        case 4:
            std::system("CLS");
            display_profile();
            break;
        case 5:
            goto menu;
    }
    } 
    return 0;  
};

