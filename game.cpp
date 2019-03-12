#include<iostream>
#include<cstdlib>
/* This program is game guess what is the right number
 * and there are diffcualt levels that you can chose
 * Also, the level are easy, normal, and hard.
 * The idea: input the number what you have guess and
 * it will prompt if it's right or worng number....
 * 
 Language: C++
 Program: Random numbers and challange.
 
 * Copyright 2019, Aziz Aldawk. All rights reserved.
****************************************************************************
Here about updates and what i've added so far::
Version update:2.1
date: 3/8/19 3:04 pm
what's new: 
I have add more function on main which that main
will have only finctions instead of have a mass of codes. 
Also, i create a new function for guess game and 
i think i will add more games on the futures. 

Version update:3.5
date: 3/11/19 10:04 pm
what's new:
I have added login functions:
what's do is
you can create a new account
and login withn your current account.
if your account correct, you will access to the game,
otherwise, you have to try again.
*/
using namespace std; 

struct log{
    string username;
    int password;
    string Newname;
    int Newpass;
};
void login(); //function is so spread
void NEWlog(log &ll);
void Current_Account(log &ll);

void easy();
void Normal();
void hard();
void guess(); // function for game guess what's number. 
// functions that tells what level of diffcalty. 
int main(){
system("clear");
login();

}// Later i will add more games. 
//ask user to select the options.
void login(){
    cout<<endl;
    log ll;
    int cho;
    do{
cout<<"Create a new account!            press <1>"<<endl
   <<"Login if you already have account press <2>"<<endl
  <<"Exit?                                    <0>"<<endl;
cin>>cho;
    switch(cho){
    case 1:
        system("clear");
        NEWlog(ll);
     break;
     case 2:
        system("clear");
        Current_Account(ll);
      break;
    default:
        cout<<"ERROR 404, Exitting for program"<<endl;
        exit(0);
    }
}while(cho !=0);
}
//Creating a new user and password.
void NEWlog(log &ll){
    cout<<"Enter a new username:: "<<endl;
    cin>>ll.Newname;

    cout<<"Enter a new password: "<<endl;
     cin>>ll.Newpass;
}
//you have account??, then access to enter the game..

void Current_Account(log &ll){

cout<<"Welcome to login page!"<<endl;
cout<<"The Game guess what's number!!"<<endl;

    cout<<"Enter your username: "<<endl;
    cin>>ll.username;

    cout<<"Enter your password: "<<endl;
    cin>>ll.password;

    if((ll.username == ll.Newname)&& (ll.password == ll.Newpass )){
        system("clear");

        guess(); // if the pass and user are correct then it will access to it.
     }
    else
    {


        cout<<"password or name is wrong, please try again"<<endl;
        cout<<endl;
        cout<<endl;
        Current_Account(ll); //if it's wrong, try again :).


    }

}



/*
* (easy mod) usually for begininer and test the game... 
** Also, it's good for showing up to poeple and take opinions.
*/
void guess(){

int chose;
//cout<<"============== ** Caution ** ========================"<<endl
  //  <<"This challenge game and please read this carefully for your heath..>>>"<<endl
   // <<":::::If you have heart disease, pressure or any other symptoms <==="<<endl
   // <<"This game is not for you, please quite the game and stay healthy."<<endl
   // <<"============== ** Caution ** ========================"<<endl;
//cout<<endl;
cout<<"Welcome to the game geuss what's right numbers."<<endl
        <<"This game about to guess what is the right number>>>"<<endl
	<<"++++ the number will change everytime you play+++"<<endl
	<<"please note: This game still early access which mean"<<endl
	<<"you will see many errors and glitchs.... Thanks"<<endl;
cout<<endl;   
cout<<":::::: Please chose the difficult level:::::::"<<endl
        <<"Easy   <1> : This level for poeple who play the first time"<<endl
	<<"Normal <2> : This level is challange>"<<endl
        <<"Hard   <3> : This level for expert poeple and have high skills :"<<endl;
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
}
void easy(){
system("clear");
	int num, ran;
	char ch;
	int bounce=0;
	int trying = 0;
	
	cout<<"============> Welcome to Easy Mode <============="<<endl
            <<"Please read instructions for easy mode."<<endl
	    <<"1- You have only 20 attempts."<<endl
            <<"2- If you lose, you will get the last point you had."<<endl
            <<"3- Good luck and have fun :)."<<endl; 
	cout<<endl; 	
	do{

            //cout<<endl;
            cout<<"*********************************************************"<<endl;
	cout<<"Enter the number between <0 to 2> !!!"<<endl;
	cin>> num;
	if ( num >= 3)
	{
cout<<"ERROR :::::::::: YOU HAVE TO ENTER BETWEEN <0 to 2> ONLY ::::::::::::::"<<endl;
exit(0);
	}
	ran = rand() %2;

        cout<<"The correct number is: "<<ran<<endl;
        cout<<endl;
	if (num == ran){
		cout<<"Congrates, you got 50 Point..."<<endl;
		bounce +=50;
		cout<<"your point is: "<<bounce<<endl;
		trying =0; // make it zero when get bounce and win...
	}

	else{

    cout<<endl;
    cout<<"*********************************************************"<<endl;
	cout<<"GAME OVER and the last point you got "<<bounce<<endl;
        cout<<endl;
        trying++;
	cout<<trying<<" of 20 attempts"<<endl; 
        cout<<endl;
        cout<<"*********************************************************"<<endl;
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
system("clear");
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
Carefull,, maybe you will break something very value like your laptop:).
*/
void hard(){
	system("clear");
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
