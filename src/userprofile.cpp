#pragma once
#include <iostream>
#include <fstream>
#include "login.cpp"
#include <cstring>

using std::cout;    using std::fstream;
using std::cin;     using std::ios;
using std::endl;
using std::string;
User universal_user;
string path="../data/follow/";


void view_followers()
{
    fstream p_view_follow;

    p_view_follow.open((path+LoggedInUser.name+"/followers.bin").c_str(),ios::in|ios::binary);
    if (p_view_follow)
    {
        while(!p_view_follow.eof())
        {
            name_foll name_of_follower;
            p_view_follow.read(reinterpret_cast<char*>(&name_of_follower),sizeof(name_of_follower));
            name_of_follower.display();
        }
       
        p_view_follow.close();    
    }
    else
    {
        cout<<"You dont have any followers!!.";
    }   
}

void view_following()
{
    cout<<"The people you follow are: "<<endl;
    fstream p_view_follow;

    p_view_follow.open((path+LoggedInUser.name+"/following.bin").c_str(),ios::in|ios::binary);
    if (p_view_follow)
    {
        while(!p_view_follow.eof())
        {
            name_foll name_of_follower;
            p_view_follow.read(reinterpret_cast<char*>(&name_of_follower),sizeof(name_of_follower));
            name_of_follower.display();
        }
       
        p_view_follow.close();    
    }
    else
    {
        cout<<"You don't follow anyone.";
    } 
}

void blocked_people()
{
    
    cout<<"The people you follow are: \n"<<endl;
    fstream p_view_blocked;

    p_view_blocked.open((path+LoggedInUser.name+"/blocked_to.bin").c_str(),ios::in|ios::binary);
    if (p_view_blocked)
    {
        while(!p_view_blocked.eof())
        {
            name_foll name_of_follower;
            p_view_blocked.read(reinterpret_cast<char*>(&name_of_follower),sizeof(name_of_follower));
            name_of_follower.display();
        }
       
        p_view_blocked.close();    
    }
    else
    {
        cout<<"You have not blocked anyone.";
    } 
}
 void view_posts()
 {

 }
// {
//     cout<<"Your posts are: "<<endl;
//     for (int i =0;i<=LoggedInUser.n_posts;i++)
//     {
//         cout<<i+1<<". "<<LoggedInUser.users_posts[i]<<endl;
//     }
// }
void display_profile()
{
    int answer;
    cout<<"\n\n\n\n";
    cout.fill(' ');
    cout.width(60);
    cout<<"Welcome "<<LoggedInUser.username<<"!!!\n";
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
    std::cout<<"Do you want to view the usernames of your friends?\n ";
    std::cout<<"1. View my followers?"<<std::endl;
    cout<<"2. View people who I follow?"<<endl;
    cout<<"3. Or check all your past posts?"<<endl;
    cout<<"4.Blocked people."<<endl;
    cout<<"4. Exit the program"<<endl;
    cout<<"\nYou choice: ";
    cin>>answer;
    switch(answer)
    {
        case 1:
            std::system("CLS");
            //cout<<"This is called";
            view_followers();
            break;
        case 2:
            std::system("CLS");
            view_following();
            break;
        case 3:
            std::system("CLS");
            view_posts();
            break;
        case 4:
            std::system("CLS");
            blocked_people();
            break;
        default:
            exit(0);
    }
}