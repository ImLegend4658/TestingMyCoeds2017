#include<iostream>
using namespace std;
int main(){
cout<<"Welcome to Fibonacci sequence "<<endl; 
    int n1=0;
    int n2=1, n3;
    cout<<n1<<" "<<n2;
    cout<<" ";
    for(int i=2;i<15;i++){
        n3 = n1+n2; //0+1
        cout<<n3<<" ";
        n1 =n2;
        n2 = n3;
    }

cout<<endl; 
}