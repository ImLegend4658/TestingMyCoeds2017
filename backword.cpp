#include<iostream>
#include<algorithm>    // std::sort
#include<string>
using namespace std;

 int main(){

 string name;

string temp;
 cout<<"write here"<<endl;
 getline(cin, name);

 for (int i = name.length()-1;i>=0;i--){
temp+= name[i];
}
cout<<temp<<endl;
}

