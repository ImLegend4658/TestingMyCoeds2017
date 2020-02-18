#include <iostream>
#include <string>

using namespace std;


int main()
{

char massege[100];
int input, legnth, key; 

cout<<"Enter your massege"<<endl; 
cin.getline(massege,100);

cout<<"Enter The Key"<<endl; 
cin>>key;

 char ch; 
for(int i =0; massege[i] !='\0';i++){
ch = massege[i];

if(ch >= 'a' && ch <= 'z'){
     ch = ch+key;
     if (ch > 'z')
     {
          ch = ch - 'z' + 'a' -1; 

          }
          massege[i] = ch; 
     
} else if (ch >= 'A' && ch <= 'Z'){
     ch = ch + key; 

     if(ch > 'Z'){
          ch = ch - 'Z' + 'A' - 1;
     }
     massege[i] = ch; 
}

}
cout<<massege<<endl; 

}