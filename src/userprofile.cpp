#pragma once
#include <iostream>
#include <fstream>
#include "login.cpp"
#include "home.cpp"
using std::cout;    using std::fstream;
using std::cin;     using std::ios;
using std::endl;
using std::string;
User universal_user;
void view_followers()
{
    char name_of_follower[20];
    string path="../data/follow/";
    fstream p_view_follow;
    p_view_follow.open((path+LoggedInUser.name+"/follow.bin").c_str(),ios::in|ios::binary);
    while(!p_view_follow.eof())
    {
        p_view_follow.read(name_of_follower,sizeof(name_of_follower));
        cout<<name_of_follower<<endl;
    }
    p_view_follow.close();
    call_home();
    // cout<<"Your followers are: "<<endl;
    // for (int i =0;i<=LoggedInUser.n_followers;i++)
    // {
    //     cout<<i+1<<". "<<LoggedInUser.name_of_followers[i]<<endl;
    // }
}
void view_following()
{
    cout<<"The people you follow are: "<<endl;
    for (int i =0;i<=LoggedInUser.n_following;i++)
    {
        cout<<i+1<<". "<<LoggedInUser.name_of_following[i]<<endl;
    }
}
void view_posts()
{
    cout<<"Your posts are: "<<endl;
    for (int i =0;i<=LoggedInUser.n_posts;i++)
    {
        cout<<i+1<<". "<<LoggedInUser.users_posts[i]<<endl;
    }
}
void display_profile()
{
    int answer;
    std::cout<<"\n\n\n\n";
    std::cout.width(60);
    std::cout<<"Welcome "<<LoggedInUser.username<<"!!!\n";
    std::cout.setf(std::ios::left);
    std::cout.width(40);
    std::cout.fill(' ');
    std::cout<<" ";
    std::cout.setf(std::ios::left);
    std::cout.width(50);
    std::cout.fill('_');
    std::cout<<"_";
    std::cout<<std::endl<<std::endl<<std::endl;
    std::cout<<"Followers: "<<LoggedInUser.n_followers<<"\t\t\t\t";
    std::cout<<"Following: "<<LoggedInUser.n_following<<"\t\t\t\t";
    std::cout<<"Posts: "<<LoggedInUser.n_posts<<"\t\t\t";
    std::cout<<std::endl<<std::endl<<std::endl;
    std::cout<<"Do you want to view the usernames of your friends? ";
    std::cout<<"1. View my followers?"<<std::endl;
    cout<<"2. View people who I follow?"<<endl;
    cout<<"3. Or check all your past posts?";
    cout<<"4. Exit the program"<<endl;
    cout<<"You choice: ";
    cin>>answer;
    switch(answer)
    {
        case 1:
            std::system("CLS");
            view_followers();
            break;
        case 2:
            std::system("CLS");
            view_followers();
            break;
        case 3:
            std::system("CLS");
            view_posts();
            break;
        default:
            exit(0);
    }
}