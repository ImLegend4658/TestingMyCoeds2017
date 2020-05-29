#include <iostream>
#include <string>
#include <cstdlib>

using namespace std; 

struct student{
    string name; 
    int ID; 
};

void rand(student stu[], int size);

int main(){
const int size = 5;
student stu[size];
for(int i = 0; i<size;i++){
    cout<<"Enter names of student < "<< i+1<< " > times"<<endl;
    cin>>stu[i].name;
}


rand(stu, size);

}
 
 void rand(student stu[], int size){
        srand(time(0));
        cout<<endl;
        cout<<"+++++++++++ HERE NAMES WITH ID STUDENTS :) +++++++++"<<endl;
     for(int i=0;i<size;i++){
         cout<<"*********** < "<<i+1<<" > ***********"<<endl;
         cout<<"Name is: "<<stu[i].name<<endl;
         stu[i].ID = rand();
         cout<<"ID: "<<stu[i].ID<<endl; 
        //  cout<<"******************************"<<endl;
     }
 }