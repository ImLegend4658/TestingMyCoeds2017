#include<iostream>
#include <unistd.h>
#include<string>
using namespace std; 
int main(){

//double b = INT_FAST32_MAX;

for (int i=1;i<29;i++)
{
    cout<<"Ramadan "<<i<<endl;
    usleep(300000);
    if (i == 29){
         usleep(5000000);
        cout<<"🎆🎇🎉🎊🎁Eid Mubarak 🎁🎊🎉🎇🎆"<<endl;
    exit(0);
     }
}


}
