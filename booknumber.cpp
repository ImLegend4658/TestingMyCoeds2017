#include<iostream>
#include<string>
using namespace std; 
/*
Author by Aziz 
This program to save only 3 numbers
if more, the program will exit and
if user enter no, program will exit too :)
*/
struct numberList{
    int number;
    string name;
};
void info(numberList &ListNum);
int main(){
 int si_z = 4;
numberList ListNum[si_z];

for (int i = 1;i<si_z;i++){

info(ListNum[i]);
cout<<"List number: "<<i<<endl;
cout<<"Number: "<<ListNum[i].number<<" || name: "<<ListNum[i].name<<endl;
}
cout<<"Done!"<<endl;
}

void info(numberList &ListNum)
{
 string NewName;
 int NewNumber;
 char ch;
int i =1;
 
  cout<<"****************************"<<endl;
 cout<<"Enter the name"<<endl; 
 cin>>NewName;
 cout<<"Enter the number"<<endl;
 cin>>NewNumber;
 
   
 cout<<"Are you sure to save number?.. <y/n>"<<endl;
 cin>>ch;
 
 
 if((ch == 'y') || (ch == 'Y')){
 ListNum.name = NewName;
 ListNum.number = NewNumber;
 }else
 {
    cout<<"OK...."<<endl;
    exit(0);
}
 
}
