#include<iostream>
#include<cstdlib>
/* This program is game guess what is right number and there is diffcualt level that you can chose
 * Also, the level is easy, normal, and hard. 
 * The idea: go put number what you guessed and prompt if it's right or worng number....
 * 
 Author" Aziz Aldawk
 
 Language: C++

 Program: Random numbers and challange.
 
 * Copyright 2018, Aziz Aldawk. All rights reserved.


****************************************************************************
======>> V 0.3 New update: 7/23/2018 10:06 pm <<================

*/
using namespace std; 
void easy();
void Normal();
void hard();
// functions that tells what level of diffcalty. 
int main(){

int chose;
cout<<"========================= ** Caution ** ==================================="<<endl
    <<"This challenge game and please read this carefully for your heath..>>>"<<endl
    <<":::::If you have heart disease, pressure or any other symptoms dieases such as diabetes::::<==="<<endl
    <<"This game is not for you, please quite the game and stay healthy :). thank you"<<endl 
    <<"======================== ** Caution ** ===================================="<<endl;
cout<<endl; 
cout<<"Welcome to the random game"<<endl
	<<"This game about to guess what is right number>>>"<<endl
	<<"++++ the number will change everytime you play+++"<<endl
	<<"please note: This game still early access which mean"<<endl
	<<"you will see many errors and glitchs.... Thanks"<<endl;
cout<<endl;   
cout<<":::::: Please chose the difficult level:::::::"<<endl
	<<"Easy <1> : This level for poeple who play the first time"<<endl
	<<"Normal <2> : This level is challange>"<<endl
	<<"Hard <3> : This game for expert poeple and have high patience :D :"<<endl; 
cin>> chose;
// prompt to user what she/he should to do. 
switch(chose)
{
	case 1: 
		easy();
		break;
	case 2:
		Normal();
		break;
	case 3: 
		hard();
		break;
       defualt:
		cout<<"ERROR"<<endl;
		exit(0);
	

};
// switch leaving option for user to chose....
}
/* 
 *int num: receive the number from user
 * int ran: it creates random numbers with percentage..
 * char ch: leaves chose to user if she/he wants to keep going or give up.
 * bounce == is score during the game that will earned every time player win. 
 *do while : it will repeat untile the user give up and chose no.
 * 
*** on Easy function it's been fixed the bugs on 7/22/2018:
* 1- add how many attempted on the game. 
  2- fixed the bugs that make games exit automaticly. 
  3- fixed the chose if the user wants to continue or not.....
*** I edited something a new for easy and make it simple: 
such as keeping last point and chose 0 to 2 only.. 7/23/2018
*/

/*
* (easy mod) usually for begininer and test the game... 
** Also, it's good for showing up to poeple and take opinions.
*/
void easy(){

	int num, ran;
	char ch;
	int bounce=0;
	int trying = 0;
	
	cout<<"============> Welcome to Easy Mode <============="<<endl
	    <<"Please read rulse or instructions for easy mode."<<endl
	    <<"1- You have only 20 attempts."<<endl
            <<"2- If you lose, you will get the last point you have."<<endl
            <<"3- Good luck and have fun :)."<<endl; 
	cout<<endl; 	
	do{
	
	cout<<"Enter the number between <0 to 2> !!!"<<endl;
	cin>> num;
	if ( num >= 3)
	{
cout<<"ERROR :::::::::: YOU HAVE TO ENTER BETWEEN <0 to 2> ONLY ::::::::::::::"<<endl;
exit(0);
	}
	ran = rand() %2;

	cout<<"============ The right number is: "<<ran<<" :D"<<endl;

	if (num == ran){
		cout<<"Congrates, you got 50 Point..."<<endl;
		bounce +=50;
		cout<<"your point is: "<<bounce<<endl;
		trying =0; // make it zero when get bounce and win...
	}
	else{

	cout<<"GAME OVER and the last point you got "<<bounce<<endl;
	trying++;
	cout<<trying<<" of 20 attempts"<<endl; 
//	cout<<"Do you want to try again <y/n> ?"<<endl;
//	cin>>ch;
//	bounce = 0; //This is become zero when mean player lose the game and to start again will get zero...
	}
}while(trying<=19);
// if The user lose 5 times, program will ask if the user want to continue :),..

cout<<"do you want to continue? <y/n>"<<endl; 
cin>>ch;
if((ch == 'y')||(ch == 'y')){
easy();
}
else {
(( ch == 'n')|| (ch == 'N'));
cout<<"Well! have great day :D"<<endl;
}

}

/*
(Normal mod)
this for challange between friends.. 

*/
void Normal(){

int num, ran;
char ch;
int point=0;
int trying=0;

do{
cout<<"Enter the number between <1 to 10>"<<endl;
cin>>num;
if (num >10){
cout<<"ERROR::::::::::::: YOU HAVE TO ENTER BETWEEN <1 TO 10> ONLY:::::::::: "<<endl;
exit(0);
}
ran = rand() %10;

cout<<"========= The Right Number is: "<<ran<<" :D"<<endl;

if(num == ran){
	cout<<"Great job! you got the number :D"<<endl;
	point += 100;
	cout<<"Your point is: "<<point<<endl;
	trying=0;
}
else
{
	cout<<"GAME OVER and the last point you got is: "<<point<<endl;
	trying++;
	cout<<trying<<" of 5"<<endl; 
	//cout<<"Do you want to try again <y/n>?"<<endl;
	//cin>>ch;
	point = 0;
}
}while(trying<=5);

cout<<"Do you want to continue? <y/n>"<<endl; 
cin>>ch;
if((ch == 'y')||(ch == 'Y')){
Normal();
}
else{
 ((ch =='n')||( ch== 'N'));
cout<<"Well have great day"<<endl;
}

}

/*
(Hard mod)
This for hardcod and expert player that 
 want to challage between friends. 
Carefull,, maybe you will break something very value :).
*/
void hard(){
int num, ran; 
char ch; 
int point =0;
int trying=0;

do{
cout<<"Enter the number between <1 to 15>"<<endl; 
cin>>num;

if (num >15){
cout<<"ERROR::::::::: YOU HAVE TO ENTER BETWEN <1 TO 15> ONLY::::::::: "<<endl;
exit(0);
}
ran = rand() %15;

cout<<"========= The Right number is: "<<ran<<" :D"<<endl;

if( num == ran){
	cout<<"Good job you got it :D"<<endl;
	point +=150;
	cout<<"your point is: "<<endl;
	trying=0;
	
}
else {
	cout<<"GAME OVER and the last point you got is: "<<point<<endl;
	trying++;
	cout<<trying<<" of 5 attempts"<<endl;
point =0; 
}

}while(trying<=5);
cout<<"Do you want to continue? <y/n>"<<endl; 
cin>>ch;
if((ch=='y')||(ch == 'Y')){
hard();
}
else{ (( ch=='n')|| (ch == 'N'));

cout<<" a good day :D"<<endl;

}
}
