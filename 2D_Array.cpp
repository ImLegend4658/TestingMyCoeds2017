#include <iostream>
#include <limits>
using namespace std;

int main () {

 const int size = 4;

 int arr[size][size] = {
     {10,28,22,11},
     {90,58,38,10},
     {65,48,18,41},
     {71,54,55,99}
 };
 

for (int i = 0;i<size;i++){
    for (int g = 0;g<size;g++)
    {
        cout<<"["<<i<<"]"<<"["<<g<<"]"<<"-->"<<"|"<<arr[i][g]<<"|\t";
        
    }
    cout<<endl;
}


}