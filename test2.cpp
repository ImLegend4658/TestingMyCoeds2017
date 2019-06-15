#include<iostream>
#include <unistd.h>
#include<string>
using namespace std; 
int main(){

//double b = INT_FAST32_MAX;

for (int i=0;i<100;i++)
{
    cout<<"Loading..."<<i<<"%"<<endl;
    usleep(300000);
    if (i == 99){
         usleep(5000000);
        cout<<"Error, Disconnected...."<<endl;
    exit(0);
     }
}


}
