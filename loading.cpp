#include<iostream>
#include <unistd.h>
#include<string>
using namespace std; 
int main(){

//double b = INT_FAST32_MAX;
system("clear");
for (int i=1;i<31;i++)
{
    cout<<"Ramadan "<<i<<endl;
    usleep(300000);
    if (i == 30){
        for(int k=1;k<31;k++){
        cout<<"Shawwal "<<k<<endl;
         usleep(300000);
              cout<<"🎆🎇🎉🎊🎁Eid Mubarak 🎁🎊🎉🎇🎆"<<endl;

        }
//     cout<<"🎆🎇🎉🎊🎁Eid Mubarak 🎁🎊🎉🎇🎆"<<endl;
    exit(0);
     }
}


}
