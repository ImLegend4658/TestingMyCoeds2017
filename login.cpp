#include <iostream>
#include <string>
#include <unistd.h>
using namespace std;
// login and logout page program
struct log{
    string name;
    int password;

};
void registers(log &ourlogin);
void menu(log &ourlogin);
void login(log &ourlogin);
void demo(log &ourlogin);
int main () {

    log ourlogin;

    // registers(ourlogin);
    menu(ourlogin);
    // registers(ourlogin);
    // login(ourlogin);
    // demo(ourlogin);
}

void menu(log &ourlogin){
    int selection;
    system("clear");
    cout<<"Hi there, welcome to space account"<<endl
    <<"if you dont have account, select to create a new account!"<<endl
    <<"if you have account with us, just login with your current pass and username"<<endl;
    cout<<endl;
    cout<<"Create account <1>"<<endl
        <<"Login          <2>"<<endl
        <<"EXIT!          <0>"<<endl;
    cin>>selection;
    switch (selection)
    {
    case 1:
    registers(ourlogin);
    break;
    case 2:
    login(ourlogin);
    break;
    case 0:
    exit(0);
    break;
    default:
    cout<<"Wrong selection, exitting now"<<endl;
    exit(0);

    }


}

void registers(log &ourlogin){
    system("clear");
    cout<<"Please select a new username and password :)"<<endl;
    
    cout<<"your new username is: "<<endl; 
    cin>>ourlogin.name;

    cout<<"your new password is: "<<endl;
    cin>>ourlogin.password;

    cout<<"your account has been created successfully"<<endl;

    cout<<"you will return to menu shortly"<<endl;
    cout<<"Please wait :)"<<endl;
    usleep(6000000);
    menu(ourlogin);
};

void login(log &ourlogin){
    string ourname; 
    int mypass;
    system("clear");
    cout<<"Hi there, welcome to login page"<<endl;
    cout<<"Also, make sure your name and pass is correct :)"<<endl;
    cout<<"Enter your username: "<<endl;
    cin>>ourname;
    cout<<"Enter your password: "<<endl; 
    cin>>mypass;

    if((ourname == ourlogin.name)&&(mypass == ourlogin.password)){
            demo(ourlogin);
    }else
    {
        cout<<"your username or password is Incorrect"<<endl;
       cout<<"try again"<<endl;
       cout<<"Please wait.... :D"<<endl; 
       usleep(3000000);
        login(ourlogin);
    }
    
}


void demo(log &ourlogin){
    char ch;
    system("clear");
    cout<<"Welcome to your account"<<endl
    <<"This is only demo :)"<<endl; 
    cout<<endl; 
    cout<<endl;

    cout<<"Your balance: $1,000,000,000"<<endl;
    cout<<"your saving: $98,39,2222,394"<<endl;
    cout<<"your phone is: Iphone :D"<<endl;
    cout<<"Do you like drink coffee or tea? no coffee please :D"<<endl;
    cout<<endl;

    cout<<"Log out? <y/n>"<<endl;
    cin>>ch; 

    if((ch == 'y')&&(ch == 'Y'))
   
         usleep(3000000);
        menu(ourlogin);
    
    
}