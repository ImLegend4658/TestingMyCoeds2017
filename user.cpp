#include<iostream>
#include <string>
#include<cstdlib>
using namespace std; 
/*
This is login program and store a new pass and username. 
it does not have own purpse which mean it's for fun only. 
Im sure i will fix the bugs some day hah:D
date:2/5/2019 12:15 AM
All copy reserved Aziz@2019
*/
struct info{
	string username;
	int password;
	string email;
};

void regest(info& information);
void Display(info& information);
void login(info& information);
int main(){
	system("clear");
	info information; 
	int numbers;
	do{

cout<<"regestertion press <1>"<<endl;
cout<<"show information press <2>"<<endl;
cout<<"to login press <3>"<<endl; 
cout<<"to Exit <0>"<<endl; 
cin>>numbers;

	switch(numbers){
		case 1:
 		regest(information);
 		break;
		case 2: 
 		Display(information);
 		break;
		case 3:
 		login(information);
 		break;
		default:
		cout<<"error"<<endl;
		exit(0);

	}
}while(numbers !=0);
 //system("clear");
}

void regest(info& information){
system("clear");
cout<<"Welcome to the Twwter"<<endl; 

cout<<"Enter a new username"<<endl; 
cin>>information.username;

cout<<"Enter a new password"<<endl; 
cin>>information.password;

cout<<"Enter your Email"<<endl; 
cin>>information.email;
 }

void Display(info& information){
system("clear");
	cout<<"Your a new username is: "<<information.username<<endl;
	cout<<"your password is: "<<information.password<<endl;
	cout<<"your email is : "<<information.email<<endl;
 }

void login(info& information){
system("clear");
	string myname;
	int mypass;

	cout<<"please enter your username"<<endl; 
cin>>myname; 
	cout<<"pleaes enter your password"<<endl;
	cin>>mypass;

	if ((information.username != myname) && (information.password != mypass)){
		cout<<"try again"<<endl;
	}
	else
	{
		cout<<"your login is correct"<<endl;
	}
}