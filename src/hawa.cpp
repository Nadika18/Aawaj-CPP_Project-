#include<iostream>
using namespace std;


int main(){ 
    char title[12][62]=
	{
                            
      "            ___"
       "___             "   ,  
      "         ---I   0   |    0  I----       " ,
      "            I __ /   / _____I           " ,  
      "                 ( _ )                "   ,
      "               / _______ /              " ,  
      "                  / _ /                 "  ,
      "   ----------------------------------- "
	};
    
    for(int i=0;i<12;i++)
    {
        for (int j=0;j<62; j++)
        {
                   
            cout<<(title[i][j]);
            
        }
    }
}