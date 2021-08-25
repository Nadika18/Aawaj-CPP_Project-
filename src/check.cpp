#include<iostream>
using namespace std;


int main(){ 
    char title[12][62]=
	{
                            
      "            _______ _______             \n"   ,  
      "         ---I   0   |    0  I----       \n"   ,
      "            I____ /   \\_____I           \n"   ,  
      "                 ( ___ )                \n"   ,
      "               \\_________/              \n"   ,  
      "                  \\___/                 \n"   ,
      "   ----------------------------------- \n"
	};
    
    for(int i=0;i<12;i++){
        for (int j=0;j<62; j++)
            
                   
            cout<<(title[i][j]);
            
        }
    }
