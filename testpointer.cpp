#include<iostream>
using namespace std;
/* Pointer will copy the value by self without destroy the other pointer 
 * for example: 
 * ( *P1= *P3) the number on p3 will transfer to p1 without destory the pointer */
int main(){

	int *p1, *p2;

	p1 = new int; 

	*p1= 42;
	p2=p1;
	cout<<"*p1 == "<<*p1<<endl; 
	cout<<"*p2 == "<<*p2<<endl; 

	*p2 = 53; 
	cout<<"*p1== "<<*p1<<endl; 
	cout<<"*p2== "<<*p2<<endl;

	p1= new int; 
	*p1=88;
	cout<<"*p1== "<<*p1<<endl; 
	cout<<"*p2== "<<*p2<<endl; 
}
