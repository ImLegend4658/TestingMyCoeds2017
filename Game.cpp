#include<iostream>
#include<cstdlib>
/* This program is game of guess what is right number and after that random number 
	will show up the number if equal you win, if not you lost......

	All copy right@2017 Aziz Aldawk, Please do not copy or take this code without any permission. 
Thank you..........
 */
using namespace std;

int main(){

int num;
int ran;

char ch;

do{
 
cout<<"enter the number<Between 1 to 5> that you gussed !!"<<endl;
cin>>num;

//for(int i=0; i<20;i++)

ran = rand() %5;
cout<<"=======>> The Number IS:  "<<ran<<" :D"<<endl;
if (num == ran)
cout<<"Congrates you got the number :D"<<endl; 
else 
cout<<"GAME OVER"<<endl;

cout<<"Do you want to Try Again???"<<endl; 
cin>>ch;
}while((ch == 'y') || (ch == 'Y'));
if ((ch == 'n')|| (ch == 'N')){
cout<<"Well! i hope you enjoyed the game and have a wonderful day :D"<<endl;
}
}

