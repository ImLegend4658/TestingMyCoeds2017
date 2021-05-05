#include<iostream>
#include<string>
 using namespace std; 
/*
Author: Abdulaziz Aldawk
Date: 5/5/2021

All copyright @Abdulaziz Aldawk..

feel free to study my code but 
please dont copy it for your homework and do it differently
or in your way. 

*/
struct num{
   string name;
};

// structure to store name as string type. 

void entername(num &thisname);
void countChar(num &thisname);
void backWord(num &thisname);
void vo_letter(num &thisname);
/*
Those are functions:

entername: functions prompt to user to enter name 
and user will enter name. 
his name will store at struct name type. 

countchar: it will count how many character of name without space.

backWord: it will show his name as backword. 

Vo_letter: it will count how many vowes in the name.
*/
int main(){
num thisname; 

entername(thisname);
countChar(thisname);
backWord(thisname);
vo_letter(thisname);
//function call.

}


void entername(num &thisname){
   cout<<"Enter your name sir:"<<endl; 
   getline(cin,thisname.name);
//prompt to user to write his name.
 cout<<"Your name: "<<thisname.name<<endl;
// prompt user name. 
}


void countChar(num &thisname){
   int len = 0;

   for(int i=0;i<=thisname.name.length();i++){
      if(thisname.name[i] != ' '){
         len++;
      // cout<<thisname.name.length()<<endl;   
     // cout<<i<<endl;
   //   break;

      } 
   }
// for loop to count the character without space.
   cout<<"Letters: "<<len-1<<endl;
//prompt string without space
   
}

void backWord(num &thisname){

string temp;
    for (int i = thisname.name.length()-1;i>=0;i--){
temp+= thisname.name[i];
}
cout<<temp<<endl;
}
//backword string or character


void vo_letter(num &thisname){
   int a =0;
   int e =0;
   int I = 0;
   int o = 0;
   int U = 0;

  for(int i=0;i<=thisname.name.length();i++){
      if((thisname.name[i] == 'a') || (thisname.name[i] == 'A')){
         a++;

      }else if((thisname.name[i] == 'e') || (thisname.name[i] == 'E') ){
         e++;
      }else if((thisname.name[i] == 'i') || (thisname.name[i] == 'i') ){
         I++;
      }else if((thisname.name[i] == 'o') || (thisname.name[i] == 'O')) {
         o++;
      }else if ((thisname.name[i] == 'u') || (thisname.name[i] == 'U')) {
         U++;
      }

   }

   cout<<"A: "<<a<<endl;
   cout<<"E: "<<e<<endl;
   cout<<"I: "<<I<<endl;

   cout<<"O: "<<o<<endl;

   cout<<"U: "<<U<<endl;

}

the output:
Enter your name sir:
Aziz Aldawk
Your name: Aziz Aldawk
Letters: 10
kwadlA zizA
A: 3
E: 0
I: 1
O: 0
U: 0

Enter your name sir:
Khalid alshamary  
Your name: Khalid alshamary
Letters: 15
yramahsla dilahK
A: 4
E: 0
I: 1
O: 0
U: 0

Enter your name sir:
Saad Alotaibi
Your name: Saad Alotaibi
Letters: 12
ibiatolA daaS
A: 4
E: 0
I: 2
O: 1
U: 0
