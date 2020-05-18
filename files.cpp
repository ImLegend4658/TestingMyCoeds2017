#include <iostream>
#include <fstream>
#include <string>
using namespace std; 
void menu();
void write();
void read();
int main (){

menu();
// create();
// read();
}

void menu(){
    system("clear"); //for linux
    int menu;
    cout<<"This is write and read files"<<endl
        <<"all you have to do is select the menu"<<endl
        <<"If you want to create a file (write) <1>"<<endl
        <<"if you want to read a file (Read)    <2>"<<endl
        <<"Exit? <0>"<<endl;

    cin>>menu;
    switch(menu){
        case 1:
        write();
        break;
        case 2:
        read();
        break;
        case 0:
        cout<<"exitting..."<<endl; 
        exit(0);
        break;
        default:
        cout<<"Error input"<<endl;
        exit(0);
        
    }

}


void write(){
system("clear"); //for linux
    ofstream readME;
    string filename, lines;
    cout<<"Please write whatever you want and click Enter: "<<endl; 
    cin>>lines;
    getline(cin,lines);
    
    cout<<"Enter new filename: "<<endl; 
    cin>>filename;
    
    readME.open(filename+".txt");
    readME<<lines<<endl; 
    readME.close();

    char ch = 'y'; 

    cout<<"Do you want to return to menu <y/n>"<<endl; 
    cin>>ch;

    if((ch == 'y') || (ch == 'Y')){
        menu();
    }else
    {
        cout<<"Thanks for your time :)"<<endl;
        exit(0);
    }
    
}

void read(){
    system("clear"); //for linux
    ifstream input; 
    char num; 
    string filename;
    cout<<"Please enter filename you want to read it"<<endl;
    cin>>filename;
    input.open(filename + ".txt");
    if(input.fail()){
        cout<<"is not exist, try again "<<endl;
        read();
    }
    
    while(!input.eof()){
        input.get(num);
        cout<<num;
    }
    input.close();

    char ch = 'y'; 

    cout<<"Do you want to return to menu <y/n>"<<endl; 
    cin>>ch;

    if((ch == 'y') || (ch == 'Y')){
        menu();
    }else
    {
        cout<<"Thanks for your time :)"<<endl;
        exit(0);
    }
}