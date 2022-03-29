#include<iostream>
#include <fstream>
#include <cstring>
#include<stdbool.h>
#include <unistd.h>
#include<string>
#include "stdio.h"
using namespace std; 
/*
author: Aziz Aldawk

Does allow to use it? no 

copyright@2020 

*/
void menu();
void write_File();
void count_domain();
int WordCount(char *string, char *word);
int main(){
 
menu();

}

void menu(){

    int number;

    cout<<"Welcome to this program,"<<endl
        <<"for this task, you need to count how many domain after user enter his email"<<endl
        <<"here select to make action"<<endl
        <<"add your email           <1> "<<endl
        <<"display how many domain? <2> "<<endl
        <<"Exit?                    <0>"<<endl;
        cin>>number;

        switch(number){

            case 1:

           write_File();
            break;

            case 2:
            count_domain();
            break;

            case 0:
            exit(0);
            break;

            default:
            cout<<"you select wrong number, exitting now...."<<endl;
            exit(0);
        } 
}


void write_File(){
    string line; 
cout<<"please write your email with domain..."<<endl; 
cin.ignore();
getline(cin,line);
 // in order to write whatever you want you have you ask user first
// that value can transfer to inside the file. 
ofstream readme;


readme.open("challange.txt");
readme<<line<<endl; 
readme.close();

cout<<"Thank you, will return to menu shortly"<<endl; 
         usleep(3000000);
         
         menu();
}



void count_domain(){
 
 
ifstream input;
char num;
int count = 0;
int count1 = 0;
int count2 = 0;
string line;
string name = "ksu";
input.open("challange.txt");

while (! input.eof()){

//input.get(num);
getline(input, line);
//cout<<line; 

size_t nPos = line.find("ksu", 0); //  
    while(nPos != string::npos)
    {
        count++;
        nPos = line.find("ksu", nPos + 1);
    }

     nPos = line.find("imamu", 0); //  
    while(nPos != string::npos)
    {
        count1++;
        nPos = line.find("imamu", nPos + 1);
    }

     nPos = line.find("kau", 0); //  
    while(nPos != string::npos)
    {
        count2++;
        nPos = line.find("kau", nPos + 1);
    }
   

}
 cout <<"KSU Domain: "<<count<<endl;
    cout <<"imamu Domain: "<<count1<<endl;
        cout <<"KAU Domain: "<<count2<<endl;

input.close();
   

 

 
cout<<"Thank you, will return to menu shortly"<<endl; 
         usleep(3000000);
         
         menu();


}
