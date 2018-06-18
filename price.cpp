#include<iostream>
using namespace std; 

int main(){
/*
Auther: Aziz Aldawk
Program: C++ language. 
INFormaiton: This program will recieve the price of the itme
	     the customer and it will show them price discount after
	     calcutation.
Copyright@ Aziz Aldawk 2018. 
*/
double discount, price, DisZ; 
double AftDiscount, Finalprice;
char ch;

do{ // do loop the repeat this program over over again.

cout<<"What is price for this item??"<<endl;
cin>>price;//ask the customer how much the items.
 
cout<<"how much discount is?"<<endl;
cin>>discount;  // receive the discount number.

DisZ = discount / 100; // the number will convert to decimal.


AftDiscount = price * DisZ;

//will calculate price with percentage first.
Finalprice= price - AftDiscount;

// then, it will calculate orginal price substarct with (AftDiscount) that has calculated before..
cout<<"Price was: $"<<price<<endl
<<"The discount: $"<<discount<<endl
<<"The Price now after discount: $"<<Finalprice<<endl;

//prompt to user the price and discount....

cout<<"Do you want to continu? <y/n>"<<endl; // It asks the user if she/he need to keep going.
cin>>ch;  // will recieve yes or no.

}while((ch == 'y') || (ch == 'Y'));

//Ask user if they need to keep going, else program will close....
if ((ch =='n') || (ch == 'N')){
cout<<"Great. Have a great day friend :)"<<endl;
}// END OF if Statment....

}// END OF MAIN......
