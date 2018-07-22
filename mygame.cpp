#include<iostream>
#include<cstdlib>
/* This program is game guess what is right number and there is diffcualt level that you can chose
 * Also, the level is easy, normal, and hard. 
 * The idea: go put number what you guessed and prompt if it's right or worng number....
 * 
 * All copyright@2018 Aziz Aldawk and there is no alow for copy without permission
 * Completed by 45% alpha.
 .*/
using namespace std; 
void easy();
void Normal();
void hard();
// functions that tells what level of defcualty. 
int main(){

int chose;

cout<<"Welcome to the random game"<<endl
	<<"This game about to guess what is right number>>>"<<endl
	<<"++++ the number will change everytime you play+++"<<endl
	<<"please note: This game still early access which mean"<<endl
	<<"you will see many errors and glitchs.... Thanks"<<endl; 
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
*/

void easy(){

	int num, ran;
	char ch;
	int bounce=0;
	int trying = 0;
	

	
	do{
	
	cout<<"Enter the number between <1 to 3> !!!"<<endl;
	cin>> num;
	if ( num >= 4)
	{
cout<<"ERROR :::::::::: YOU HAVE TO ENTER BETWEEN <1 to 3> ONLY ::::::::::::::"<<endl;
exit(0);
	}
	ran = rand() %3;

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
	cout<<trying<<" of 5 attempts"<<endl; 
//	cout<<"Do you want to try again <y/n> ?"<<endl;
//	cin>>ch;
	bounce = 0; //This is become zero when mean player lose the game and to start again will get zero...
	}
}while(trying<=5);
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

void Normal(){

int num, ran;
char ch;
int point=0;

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
}
else
{
	cout<<"GAME OVER and the last point you got is: "<<point<<endl;

	cout<<"Do you want to try again <y/n>?"<<endl;
	cin>>ch;
	point = 0;
}
}while((num == ran)||(ch == 'y')||(ch == 'Y'));

if ((ch =='n')||( ch== 'N'))
cout<<"Well have great day"<<endl;

}


void hard(){
int num, ran; 
char ch; 
int point =0;
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
}
else {
	cout<<"GAME OVER and the last point you got is: "<<point<<endl;
cout<<"Do you want to try again <y/n>"<<endl;
cin>>ch;
point =0; 
}
}while((ch=='y')||(ch == 'Y'));
if (( ch=='n')|| (ch == 'N'))

cout<<" a good day :D"<<endl;

}
