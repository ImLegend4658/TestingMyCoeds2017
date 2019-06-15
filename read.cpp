#include <iostream>
#include <fstream>
#include <string>

using namespace std; 

int main (){

ifstream input;
char num;

input.open("confess.txt");

while (! input.eof()){

input.get(num);

cout<<num; 


}

input.close();
}