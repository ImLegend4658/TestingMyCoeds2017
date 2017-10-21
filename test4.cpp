#include<iostream>
#include<string>
using namespace std; 
/*Lenth() is function that gives access or space between latters. 
for exampe: AZIZ < this on normal string, but if i use length function it will be like " A Z I Z" which mean 
have a space for each charcter or letters. 

all copy right@2017 Aziz Aldawk */
int main(){

string firstname, lastname;

cout<<"enter your first and last name"<<endl;
cin>>firstname>>lastname;

cout<<"Your last name is spelled: "<<endl;

//int i; 

for (int i=0; i<lastname.length(); i++){

cout<< lastname[i]<< " ";
lastname[i]= '-';

}
cout<<endl;

for (int i=0; i<lastname.length(); i++)

cout<<lastname[i] <<" ";

cout<<endl;

cout<<"good day "<<firstname<<endl;


}
