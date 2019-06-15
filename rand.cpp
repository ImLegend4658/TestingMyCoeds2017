#include<iostream>
#include<cstdlib>
using namespace std;

int main(){
int num =0;
srand ( time(NULL) );
for (int i =0;i<10;i++)
{
num = rand();
cout<<num<<endl;
}


}