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
      
   //system( "color 61" ); 
std::cout << "\t\t" <<char(201);      for(int i=0; i<20; i++){std::cout  << char(205);}      std::cout << char(187) << std::endl;
std::cout  <<"\t\t" << char(186) << "       AAWAJ        " << char(186) << std::endl;
std::cout  << "\t\t" <<char(200);      for(int i=0; i<20; i++){std::cout  << char(205);}      std::cout << char(188) << std::endl;
std::cout  << "\t\t" <<char(218);  for(int i=0; i<20; i++){std::cout  << char(196);}  std::cout << char(191) << std::endl;
std::cout  <<"\t\t" << char(179) << "   1.Register       " << char(179) << std::endl;

std::cout  << "\t\t" <<char(195);  for(int i=0; i<20; i++){std::cout  << char(196);}  std::cout << char(180)  << std::endl;
std::cout  << "\t\t" <<char(179) << "   2.login          " << char(179) << std::endl;
std::cout  << "\t\t"<< char(195);  for(int i=0; i<20; i++){std::cout  << char(196);}  std::cout  << char(180)  << std::endl;
std::cout  << "\t\t" <<char(179) << "   3.Exit           " << char(179) << std::endl;

std::cout  << "\t\t" <<char(192);  for(int i=0; i<20; i++){std::cout  << char(196);}   std::cout  << char(217) << std::endl;
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
            std::cout << "\t\t" <<char(218);  for(int i=0; i<25; i++){std::cout << char(196);}  std::cout << char(191) << std::endl;
        std::cout << "\t\t" <<char(179) << "  Enter your username :  " << char(179) << std::endl;
        std::cout << "\t\t" <<char(192);  for(int i=0; i<25; i++){std::cout << char(196);}   std::cout << char(217) << std::endl;
        std::cin >> usr;
       std::cout << "\t\t" <<char(218);  for(int i=0; i<25; i++){std::cout << char(196);}  std::cout << char(191) << std::endl;
        std::cout << "\t\t" <<char(179) << "  Enter your password :  " << char(179) << std::endl;
        std::cout << "\t\t" <<char(192);  for(int i=0; i<25; i++){std::cout << char(196);}   std::cout << char(217) << std::endl;
        std::cin >> pwd;
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
     std::system("CLS");std::cout << "\t\t" <<char(218);  for(int i=0; i<20; i++){std::cout << char(196);}  std::cout << char(191) << std::endl;
std::cout <<"\t\t" << char(179) << "   1.Privacy        " << char(179) << std::endl;

std::cout << "\t\t" <<char(195);  for(int i=0; i<20; i++){std::cout << char(196);}  std::cout << char(180)  << std::endl;
std::cout << "\t\t" <<char(179) << "   2.POst           " << char(179) << std::endl;
std::cout << "\t\t"<< char(195);  for(int i=0; i<20; i++){std::cout << char(196);}  std::cout << char(180)  << std::endl;
std::cout << "\t\t" <<char(179) << "   3.Message        " << char(179) << std::endl;

std::cout << "\t\t" <<char(195);  for(int i=0; i<20; i++){std::cout << char(196);}  std::cout << char(180)  << std::endl;
std::cout << "\t\t" <<char(179) << "   4.User Profile   " << char(179) << std::endl;

std::cout << "\t\t" <<char(195);  for(int i=0; i<20; i++){std::cout << char(196);}  std::cout << char(180)  << std::endl;
std::cout << "\t\t" <<char(179) << "   5.Log Out        " << char(179) << std::endl;

std::cout << "\t\t" <<char(192);  for(int i=0; i<20; i++){std::cout << char(196);}   std::cout << char(217) << std::endl;
   
    std::cout<<"Select the required optiton";
    std::cin>>i;
        }
    switch(i)
    {
        case 1:
        privacy:
        {
            std::system("CLS");
            int answer;
            cout<<std::setw(67)<<"PRIVACY\n";
            std::cout  << "\t\t" <<char(218);  for(int i=0; i<20; i++){std::cout  << char(196);}  std::cout << char(191) << std::endl;
std::cout  <<"\t\t" << char(179) << "   1.Add Friend     " << char(179) << std::endl;

std::cout  << "\t\t" <<char(195);  for(int i=0; i<20; i++){std::cout  << char(196);}  std::cout << char(180)  << std::endl;
std::cout  << "\t\t" <<char(179) << "   2.Block Friend   " << char(179) << std::endl;
std::cout  << "\t\t"<< char(195);  for(int i=0; i<20; i++){std::cout  << char(196);}  std::cout  << char(180)  << std::endl;
std::cout  << "\t\t" <<char(179) << "   3.Exit           " << char(179) << std::endl;
std::cout  << "\t\t" <<char(192);  for(int i=0; i<20; i++){std::cout  << char(196);}   std::cout  << char(217) << std::endl;
     
            cout<<"Enter the required option... ";
            cin>>answer;
            switch(answer)
            {
                case 1:
                add_friend();
                goto privacy;
                break;
                case 2:
                block_friend();
                goto privacy;
                break;
                case 3:
                goto home;
                break;
            }
        }
        case 2:
        post:
        {
        std::system("CLS");
                         std::cout << "\t\t" <<char(218);  for(int i=0; i<20; i++){std::cout << char(196);}  std::cout << char(191) << std::endl;
std::cout <<"\t\t" << char(179) << "   1.Write Post     " << char(179) << std::endl;
std::cout << "\t\t" <<char(195);  for(int i=0; i<20; i++){std::cout << char(196);}  std::cout << char(180)  << std::endl;
std::cout << "\t\t" <<char(179) << "   2.View Posts     " << char(179) << std::endl;
std::cout << "\t\t"<< char(195);  for(int i=0; i<20; i++){std::cout << char(196);}  std::cout << char(180)  << std::endl;
std::cout << "\t\t" <<char(179) << "   3.Exit           " << char(179) << std::endl;
std::cout << "\t\t" <<char(192);  for(int i=0; i<20; i++){std::cout << char(196);}   std::cout << char(217) << std::endl;
       
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
    std::cout << "\t\t" <<char(218);  for(int i=0; i<20; i++){std::cout << char(196);}  std::cout << char(191) << std::endl;
std::cout <<"\t\t" << char(179) << "   1.Send Message   " << char(179) << std::endl;
std::cout << "\t\t" <<char(195);  for(int i=0; i<20; i++){std::cout << char(196);}  std::cout << char(180)  << std::endl;
std::cout << "\t\t" <<char(179) << "   2.View Inbox     " << char(179) << std::endl;
std::cout << "\t\t"<< char(195);  for(int i=0; i<20; i++){std::cout << char(196);}  std::cout << char(180)  << std::endl;
std::cout << "\t\t" <<char(179) << "   3.Exit           " << char(179) << std::endl;
std::cout << "\t\t" <<char(192);  for(int i=0; i<20; i++){std::cout << char(196);}   std::cout << char(217) << std::endl;
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
            bool answer=check_user(receiver);
            if (answer)
            {
                std::cout<<"\n\nYou have been blocked by this user.\n\n";
            }
            else
            {
                message msg(receiver,msgbody);
                msg.sendMessage();
            }
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
        profile:
        {
            std::system("CLS");
            int answer;
            cout<<"\n\n\n\n";
            cout.fill(' ');
            cout.width(60);
            cout<<"Welcome "<<currentLoggedInUsername<<"!!!\n";
            cout.setf(ios::left);
            cout.width(40);
            cout.fill(' ');
            cout<<" ";
            cout.setf(ios::left);
            cout.width(50);
            cout.fill('_');
            cout<<"_";
            cout<<endl<<endl<<endl;
            std::cout<<std::endl<<std::endl<<std::endl;
            display_photo();
            std::cout<<"Do you want to view the usernames of your friends?\n ";
            std::cout<<"1. View my followers?"<<std::endl;
            cout<<"2. View people who I follow?"<<endl;
            cout<<"3. Or check all your past posts?"<<endl;
            cout<<"4.Blocked people."<<endl;
            cout<<"5. Exit the program"<<endl;
            cout<<"\nYou choice: ";
            cin>>answer;
            char l;
            switch(answer)
            {
                case 1:
                std::system("CLS");
                //cout<<"This is called";
                view_followers();
                std::cin>>l;
                goto profile;
                break;
                case 2:
                std::system("CLS");
                view_following();
                std::cin>>l;
                goto profile;
                break;
                case 3:
                std::system("CLS");
                view_posts();
                std::cin>>l;
                goto profile;
                break;
                case 4:
                std::system("CLS");
                blocked_people();
                std::cin>>l;
                goto profile;
                break;
                case 5:
                goto home;
                break;
            }
            break;
        case 5:
            goto menu;
    }
    }
    } 
    return 0;  
};

