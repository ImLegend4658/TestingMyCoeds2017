#include<iostream>
using namespace std; 
/*
This is program about ATM machin, if the user wants to 
dipast the money or withdraw or saving it.
*/
struct ATM{
    int wallet =1000;
    int saving =0;
};
void choice(ATM &atms);
void withdraw(ATM &atms);
void Diposit(ATM &atms);
void Display(ATM &atms);
void Saving(ATM &atms);

int main(){
ATM atms;

choice(atms);


}

void choice(ATM &atms){

    int num;
    cout<<"Welcome to ATM Bank R"<<endl
        <<"Please choice the options"<<endl
        <<"Withdraw        <1>"<<endl
        <<"Deposit         <2>"<<endl
        <<"Display Balance <3>"<<endl
        <<"Saving          <4>"<<endl
        <<"Nothing?        <0> to exit"<<endl;
        cin>>num;
    switch(num){
        case 1:
        withdraw(atms);
        break;
        case 2:
        Diposit(atms);
        break;
         case 3:
        Display(atms);
        break;
        case 4:
        Saving(atms);
        break;
         case 0:
         exit(0);
     };
}

void withdraw(ATM &atms){
    int money;
    int num;
    cout<<"Choice the withdraw you want"<<endl
        <<"$50 <1>"<<" $100 <2>"<<endl
        <<"$200 <3>"<<"$300 <4>"<<endl
        <<"Other? <5>"<<endl;
    cin>>num;

    switch (num)
    {
    case 1:
    atms.wallet -=50;
    if(atms.wallet > 0){
        cout<<atms.wallet<<endl;
    }else if(atms.wallet < 0)
    {
        cout<<"you dont have enough moeny."<<endl;
        //to menue?
    }
        break;
    case 2:
    atms.wallet -=100;
    if(atms.wallet > 0){
        cout<<atms.wallet<<endl;
    }else if(atms.wallet < 0)
    {
        cout<<"you dont have enough moeny."<<endl;
    }
    break;
    case 3:
    atms.wallet -=200;
    if(atms.wallet > 0){
        cout<<atms.wallet<<endl;
    }else if(atms.wallet < 0)
    {
        cout<<"you dont have enough moeny."<<endl;
    }
    break;
    case 4: 
    atms.wallet -=300;
    if(atms.wallet > 0){
        cout<<atms.wallet<<endl;
    }else if(atms.wallet < 0)
    {
        cout<<"you dont have enough moeny."<<endl;
    }
    break;
    case 5:
    cout<<"Enter amount you want to withdraw"<<endl;
    cin>>money;
    atms.wallet -=money;
    if(atms.wallet > 0){
        cout<<atms.wallet<<endl;
    }else if(atms.wallet < 0)
    {
        cout<<"you dont have enough moeny."<<endl;
    }
    break;

    default:
        break; //exit
    }

}


void Diposit(ATM &atms){

int num , dipos;
char ch;
    cout<<"diposit <1>"<<endl
        <<"Exit?   <0>"<<endl;
    cin>>num;
    switch (num)
    {
    case 1:
    cout<<"How many do you want to diposit?"<<endl; 
    cin>>dipos;
    atms.wallet +=dipos;
    cout<<"you diposit: "<<dipos<<" now you have :"<<atms.wallet<<endl; 
    
    cout<<"Do you want diposit again? <y/n>"<<endl; 
    cin>>ch;
    if((ch == 'Y') || (ch == 'y')){
        Diposit(atms);
    }else if((ch == 'N') || (ch == 'n')){
        //back to menu;
    }
        break;
    
    default:
        break;
    }
}


void Display(ATM &atms){

char ch;
cout<<"Your balance now is: "<<atms.wallet<<endl; 
cout<<"You have saving now: "<<atms.saving<<endl;

cout<<"if you dont want anything else choic M to back to menu"<<endl
    <<"if you want to saving option choice S"<<endl;
    cin>>ch;
if((ch == 'M') || (ch == 'm')){
        //back to menu
    }else if((ch == 'S') || (ch == 's')){
        //back to Saving;
    }
}

void Saving(ATM &atms){
int mo;
cout<<"Welcome to saving account"<<endl
    <<"you can transfer your money to saving"<<endl
    <<"in order to save your money for future :)"<<endl
    <<"how many you want to transfer?"<<endl; 
    cin>>mo;
    atms.wallet -=mo;
    atms.saving +=mo;

    cout<<atms.wallet <<endl; 
    cout<<atms.saving<<endl; 
}