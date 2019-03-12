#include<iostream>
#include<string>
 using namespace std;

struct player{
    int ID;
    string name;
    //int score;
};
void info();
void names(player &p);
void id(player &p);
int main(){
    //player playr;

    info(); //funciton call allowed to be trasfer to anywhere..
}

void info(){
    player p;

    names(p);
    id(p);

}

void names(player &p){
cout<<"Hello Player Enter your name: "<<endl;
cin>>p.name;
}

void id(player &p){

p.ID = rand();
cout<<"ID: "<<p.ID<<endl;
}



