#include <iostream>
#include<cstdlib>
using namespace std; 
/*===============================================================
Author: Aziz Aldawk.
Date: 4/3/2017
UPDATED: 1/5/2019 
Updated: 5/1/2020
What NEW: more orgniazed, looks neat and beautiful. 
user can undersand and interact with pizza app :)
Homework #4
purpose: This program will be able to get and set pizza's order
		 from customers. the program will display what type 
		 the pizza and size with prices.
=================================================================*/
class Pizza
{
public:// member function of class.
	void OutputDescription();
	void SetThePizza(int myType, int thetype);
	int GetThePizza();
	int GetTheTypeOfPizza();
	void Set_computePrice();
	double Get_computerPrice();
private:// only on class function can access by priavite.
	int ThePizza_TypeANDSize;
	int thetypepizza;
	double price; 
};

int main(){
	const int size = 100; 	
//declare varibles for class.
	//Pizza order1[4]; // the orginal one. 
	Pizza order1[size];
	char yes; 
	//ask for each order by array. 
	
/*	for (int i = 0; i <4; i++){
		order1[i].OutputDescription();
		cout << "Your Total is: $" << order1[i].Get_computerPrice() << " enjoy your pizza" << endl;
		cout << endl; 
	}
*/

	do{
	system("clear");////
	order1[size].OutputDescription();
	cout<<"Your total is: $"<< order1[size].Get_computerPrice() <<" Enjoy your pizza :)"<<endl; 
cout<<endl; 
cout<<"Do you want anything else?<Y/N>"<<endl; 
cin>>yes; 

	}while(yes == 'y');
if( yes == 'n'){

cout<<"Thank you for visiting US and pizza will be ready shortly. :)"<<endl;
exit(0); 
};//update 2018: this function make sure if it needs keep going or stop. :)
 
	//system("pause");// please pause program; 
 }
/*========================= The Decription ============================================
The prupose: this function will ask the customers what 
             type and size the pizza, they want. 
setThePizza = it receives order from customers.
Set_ComputerPrice = takes the order to prompt price for customers
                    that how much the total is. 
=======================================================================*/
void Pizza::OutputDescription(){
	//declare varibles.
	int TypePizza; 
	int WhattheType;
	system("clear");
	//Ask customers what type of pizza, they want. 
	cout << "Welcome to our Pizza store."<<endl;
	cout <<"Please select the type of Pizza you want:"<< endl
		<< "Deep dish pizza   press <1>" << endl
		<< "Hand Tossed pizza press <2>" << endl
		<< "Pen Pizza         press <3>" << endl; 
	//prompt from the user. 
	cin >> WhattheType;
	system("clear");
	//Ask customers what size of the pizza, they want.
	cout << "Please select the size of pizza you want:" << endl
		<< "Small Pizza is $10 with Topping   press <1>" << endl
		<< "Medium Pizza is $14 with Topping  press <2>" << endl
		<< "Large Pizza is $17  with Topping  press <3>" << endl;
	//prompt from user.
	cin >> TypePizza;
	//function that takes order from costomers.
	SetThePizza(TypePizza, WhattheType);
	//calculate and prompt total.  
	Set_computePrice();
}
/*====================Set The Pizza ================================
The prupose: This function is copy Constructor that allow 
             the varibles to be used or assign with other varibles.
============================================================*/
void Pizza::SetThePizza(int myType, int thetype){

	ThePizza_TypeANDSize=myType;
	thetypepizza = thetype;
}
/*==================== three functions ================================
The prupose: those function are Constructor that allow
		     the varibles in private to be used outside 
			 the class member. 
============================================================*/
int Pizza::GetThePizza()
{
 return ThePizza_TypeANDSize;
}

int Pizza::GetTheTypeOfPizza()
{
	return thetypepizza;
}

double Pizza::Get_computerPrice(){

		return price; 
}
/*===================Set Computer Price ========================
The prupose: this function will be able to display
             the total of the price the orders. 
Get The TypeofPizza: this function will be able to prompt
					 the type of pizza. 
Get The pizza: This function wil be able to prompt 
			   total which include topping and size of pizza. 
==============================================================*/
void Pizza::Set_computePrice()
{
    
	// //declare string or characters. 
	// char s1[20] = "Deep Dish";
	// char s2[20] = "Hand Tossed";
	// char s3[5] = "Pan";
	system("clear");
	// switch (GetTheTypeOfPizza())
	// {
	// case 1:
 	// 	// s1; //Deep Dish.
    //      cout<<"Deep Dish"<<endl;
	// 	break;
	// case 2:
	// 	// s2; // Hand Tossed.
	// 	break;
	// case 3:
	// 	// s3; // Pen
	// 	break;
	// default:
	// 	cout << "error" << endl;
	// 	exit(0); // program will exit. 
	// }

	//declare varibles 
	int Topping;
	int num = 1;
    int topping; 
	// system("clear");
	//ask user how many topping, they want on the pizza.
	cout << "How many Topping do you want on the Pizza?" << endl
	     << "*** Please note: $2 per Topping ***" << endl;

	cin >> Topping; 

	topping = num + Topping;
	// it will add number the user has enterd with price of topping. 
cout<<"your order: "<<endl;
switch (GetTheTypeOfPizza())
	{
	case 1:
 		// s1; //Deep Dish.
         cout<<"Deep Dish pizza"<<endl;
		break;
	case 2:
        cout<<"Hand Tossed pizza"<<endl;
		// s2; // Hand Tossed.
		break;
	case 3:
        cout<<"Pen pizza"<<endl;
		// s3; // Pen
		break;
	default:
		cout << "error" << endl;
		exit(0); // program will exit. 
	}
    //prompt to user the output of pizza type.
    //that he/she choic it. 
	switch(GetThePizza()){

	case 1:
    cout<<"Size small is $10 with Topping"<<endl;
			price = 10 + topping;
		break;
		case 2:
            cout<<"Size Medium is $14 with Topping"<<endl;

			price = 14 + topping;
		break;
		case 3:
        cout<<"Size Larg is $17 with Topping"<<endl;
			price = 17 + topping;
		break;
		
		default:
		cout<<"error"<<endl; 
		exit(0); // will exit the program. 
    }// it calc with tapping and size too.

	}
