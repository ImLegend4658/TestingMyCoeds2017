#include<iostream>
using namespace std; 

void test(int *p1);


int main(){

	int *p1; 

	test(p1);


}

void test(int *p1){

p1 = new int; 
 
*p1 = 79;
cout<<p1<<endl;

p1 = new int; 

*p1 = 88;
cout<<p1<<endl;

*p1= 73; // lets try to type number without new !! iam assumming it will show 88
// after testing: it shows 73 !!!! 
cout<<p1<<endl;

// on my thery: if i put <new> it will fine new address place on the memory only ....... or it will stay on same place of memory address.
}
