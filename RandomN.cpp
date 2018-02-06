#include<iostream>
#include<cstdlib>
/* V 1.0 ALPHA. project......
 * This program is about game guess what is right number and there is diffcualt of level that you can chose.
 * such as easy, normal and hard. 
 * The idea: the user enter the number what the user gussed and 
 * will prompt to use the number that tell if it's wrong or correct.
* Feedback: should add more chance like 3 times esle fail. *
 * All copyright@2018 Aziz Aldawk and there is no right to copy without permission.
 * .*/
using namespace std; 
void easy();
void Normal();
void hard();
// functions that tells what level of defcualty. 
int main(){

int chose;

cout<<"Welcome to the random game V 0.1 Alpha"<<endl
	<<":::::> you may got something wrong, because this is game hasnt finished yet :)"<<endl
	<<"This game about to guess what is right or wrong number>>>"<<endl
	<<"++++ the number will change everytime you play+++"<<endl;
cout<<":::::: Please choose the difficult level of game:::::::"<<endl
	<<"Easy <1> : This level for poeple who play the first time"<<endl
	<<"Normal <2> : This level is challange>"<<endl
	<<"Hard <3> : This game for expert poeple and have high patience :D :"<<endl
	<<"WARNING: YOU MAY BROKE YOUR PHONE OR SOMETHING ELASE AND I AM NOT RESPONSIBILTY ABOUT THAT :)"<<endl; 
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
*/

void easy(){

	int num, ran;
	char ch;
	int bounce=0;
	int sum=0;

	
/*2/2/18
 * last uptaed: 
 * i add while and fix some error like reapeting..... 
 * 3:34 pm
 *
 * */
	do{
	
	while(sum<4){

		cout<<":::: Please Note: you have 3 times:::::::::::: "<<endl;
	cout<<"Enter the number between <1 to 3> !!!"<<endl;
	cin>> num;

	if (!cin.good())
		return ;

	if ( num >= 4)
	{
cout<<"ERROR Where you want to go @_@ :::: YOU HAVE TO ENTER BETWEEN <1 to 3> ONLY ::::::::::::::"<<endl;
exit(0);
	}
	ran = rand() %3;

	//cout<<"============ The right number is: "<<ran<<" :D"<<endl;

	if (num == ran){
		       
		cout<<"Congrates, you got 50 Point..."<<endl;
		bounce +=50;
		cout<<"your point is: "<<bounce<<endl;
	}
	else{ 
				cout<<"Wrong number and tries: "<<sum<<endl;
		
	}
	sum++;	
	

	}
	//else{
//		cout<<"GAME OVER and the last point you got "<<bounce<<endl;
	cout<<"Do you want to try again <y/n> ?"<<endl;
	cin>>ch;
	bounce = 0; //This is become zero when mean player lose the game and to start again will get zero...
	//}

	}while((num == ran)&&(ch == 'y')||(ch == 'y'));

if (( ch == 'n')|| (ch == 'N'))
cout<<"Well! have great day buddy :D"<<endl;


}

void Normal(){

int num, ran;
char ch;
int point=0;

do{
cout<<"Enter the number between <1 to 10>"<<endl;
cin>>num;
if (num >10){
cout<<"ERROR::::: YOU HAVE TO ENTER BETWEEN <1 TO 10> ONLY:::::::::: "<<endl;
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
