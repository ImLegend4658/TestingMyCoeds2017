#include<iostream>
/*This program about speed ticket in Indiana state
 * create it by Aziz Aldawk 
 *
 * All copy right@2017 */
using namespace std;

void input(int &speedTick, int &result, int &speed);
void calc(int speedTick, int result, int speed);

int main(){

	int speedTick, result,  speed;
	int i;
	while(i>5){

		input(speedTick, result, speed);
		calc(speedTick, result, speed);
		i++;
	}

}

void input(int &speedTick, int &result, int &speed)
{
//	int speed;
	cout<<"How much was your speed driving?"<<endl;
	cin>>speedTick;
	//
	cout<<"How much speed limit was in the street?"<<endl;
	cin>>speed;
	//
	result=speedTick - speed;
	cout<<"Result::: =====> "<<result<<" <====="<<endl;
	 }
	//
	 void calc(int speedTick, int result, int speed)
	 {
	//
	  if (result <= 15)
	  cout<<"your fine will be :  $25 plus $133.50 totals $158.50"<<endl;
	//
	    else if((result >=16 ) && (result <= 25))
	//
	//
	    cout<<" your fine will be with your speed:  $30 plus $133.50 totals $163.50"<<endl;
	//
	      else if (result >= 26)
	//
	      cout<<" your fine will be:  $40 plus $133.50 totals $173.50"<<endl;
	//
	      }
