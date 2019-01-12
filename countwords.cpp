#include<iostream>
#include<string>
using namespace std;

int main(){

string name;
int num =0;
cout<<"please write here"<<endl;
getline(cin,name);

for (int x = 0; x < name.length(); x++) {
    if (name[x] != ' ') {
        num++;
    }
}
cout<<"you write: "<<name<<endl;
//cout<<"String lenght is: "<<characterCount(name)<<endl;

cout<<"String lenght is: "<<num<<endl;
}
