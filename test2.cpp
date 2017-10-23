#include<iostream>
using namespace std; 
/*
 * same the idea of getline(cin, Virable)
 * or 
 * cin.get(VARIBLE, SIZE)
 *
 * all of them gives more line and space include blanks and space*/
int main(){

char sy; 

cout<<"please write the note:::>"<<endl; 
// This loop will read any line of input and echo it exactly, including blanks. 
do 
{

	cin.get(sy);
	cout<<sy;

}while(sy != '\n');
}
