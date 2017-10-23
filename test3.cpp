#include<iostream>
using namespace std; 

int main(){


cout<<"============= BE aware on this station::: test AREA 3 ::: BE aware on this station ============="<<endl; 

char next; 

do 
{

	cin.get(next);
	if (isspace(next))
		cout<<'-';
	else 
		cout<<next;
}while(next != '-');


}
