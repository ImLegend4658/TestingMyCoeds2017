#include<iostream>
#include<string>
using namespace std; 

struct myhome{
    string name; 
    int age; 
};
void thename(myhome &thename);
void theage(myhome &thename);
void disp(myhome thename);
int main(){
    myhome thehome;

thename(thehome);
theage(thehome);
disp(thehome);

}

void thename(myhome &thename){

cout<<"Enter your name: "<<endl; 
getline(cin, thename.name);

}

void theage(myhome &thename){
cout<<"Please enter your age here"<<endl;
cin>>thename.age;
}

void disp(myhome thename){

    if (thename.age >= 18)
    {
        cout<<"Dear: "<<thename.name<<"you are welcome to this party"<<endl;
    }
    else
    {
         cout<<"Dear: "<<thename.name<<"you still kid and go drink a milk and sleep well"<<endl;
    }
    
}