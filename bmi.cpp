#include<iostream>
using namespace std; 

int main(){

	int height, weight, BMI;

	cout<<"Enter your height in inches: "<<endl;
	cin>>height;

	cout<<"Enter your weight in punds: "<<endl; 
	cin>>weight;

	BMI = (weight*703)/(height*height);

	cout<<"here is your results"<<endl; 
	cout<<"BMI is: "<<BMI<<endl;
	cout<<"============"<<endl; 
	cout<<"Below 18.5: Underweight"<<endl
	<<"18.5 - 24.9: Average"<<endl
	<<"25.0 - 29.9: Overweight"<<endl
	<<"30 and abve: Obese"<<endl; 

}
