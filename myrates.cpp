#include <iostream>
#include <string>
#include <fstream>
/*
 *This program about write the note the located on the files. For example, 
 i can write note that located on the desktops. 
 *
 * All copy right @ Aziz Aldawk and please do not do any edit on this code wihout permission. Thanks :)
 */ 
using namespace std; 
//
 int main(){
 string line; 
 cout<<"please write the note you want to keep it here"<<endl; 
 getline(cin,line);
// // in order to write whatever you want you have you ask user first
// / // that value can transfer to inside the file. 
 ofstream readme;


 readme.open("rates.txt");
 readme<<line<<endl; 
 readme.close();

 }
