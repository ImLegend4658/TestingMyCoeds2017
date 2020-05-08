#include<iostream>
using namespace std; 
/*
This is program about ATM, if the user wants to 
diposit the money or withdraw or saving it.
*/
struct ATM{
    int wallet =0;
    int saving =0;
};
//saving value in memory locaion
void choice(ATM &atms);
void withdraw(ATM &atms);
void Diposit(ATM &atms);
void Display(ATM &atms);
void Saving(ATM &atms);
//delclare functions.
int main(){
ATM atms;

choice(atms);
//takes you to menu.
}

/*
This function give you choice what you want to do 
like withdraw, deposit, or else.
*/
void choice(ATM &atms){
system("clear"); //for linux
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

         default:
         cout<<"error input, exiting now"<<endl; 
         exit(0);
     };
}
/*
withdraw is taking a cash with you 
and there is many option of cash 
or you can select number of cash you want.
*/
void withdraw(ATM &atms){
    int money;
    int num;
    char ch;
    system("clear"); //for linux

    cout<<"Choice the withdraw you want"<<endl
        <<"$50 <1>"<<" $100 <2>"<<endl
        <<"$200 <3>"<<"$300 <4>"<<endl
        <<"Other? <5>"<<endl
        <<"return to menu? <6>"<<endl;
    cin>>num;

    switch (num)
    {
    case 1:
    atms.wallet -=50;
    //take out from your wallet to give you a cash.
    if(atms.wallet > 0){
        cout<<"you withdraw: 50"<<endl;
        cout<<"your balance now: "<<atms.wallet<<endl;
        cout<<"Do you want somthing else? (back to menu) <y/n>"<<endl; 
        cin>>ch;
        if((ch == 'Y') || (ch == 'y')){

            choice(atms);
        }else if((ch == 'N') || (ch == 'n')){
            cout<<"Thank you for using ATM"<<endl;
            exit(0);
        }
    }else if(atms.wallet < 0)
    {
        cout<<"There's no enough money in your wallet!!"<<endl;
        cout<<"Do you want return to menu? <y/n>"<<endl; 
        cin>>ch;
        if((ch == 'Y') || (ch == 'y')){

            choice(atms);
        }else if((ch == 'N') || (ch == 'n')){
            cout<<"Thank you for using ATM"<<endl;
            exit(0);
        }
    }
        break;
    case 2:
    atms.wallet -=100;
    if(atms.wallet > 0){
       cout<<"you withdraw: 100"<<endl;
        cout<<"your balance now: "<<atms.wallet<<endl;
        cout<<"Do you want somthing else? (back to menu)<y/n>"<<endl; 
        cin>>ch;
        if((ch == 'Y') || (ch == 'y')){

            choice(atms);
        }else if((ch == 'N') || (ch == 'n')){
            cout<<"Thank you for using ATM"<<endl;
            exit(0);
        }
    }else if(atms.wallet < 0)
    {
         cout<<"There's no enough money in your wallet!!"<<endl;
        cout<<"Do you want return to menu? <y/n>"<<endl; 
        cin>>ch;
        if((ch == 'Y') || (ch == 'y')){

            choice(atms);
        }else if((ch == 'N') || (ch == 'n')){
            cout<<"Thank you for using ATM"<<endl;
            exit(0);
        }
    }
    break;
    case 3:
    atms.wallet -=200;
    if(atms.wallet > 0){
          cout<<"you withdraw: 200"<<endl;
        cout<<"your balance now: "<<atms.wallet<<endl;
        cout<<"Do you want somthing else? (back to menu) <y/n>"<<endl; 
        cin>>ch;
        if((ch == 'Y') || (ch == 'y')){

            choice(atms);
        }else if((ch == 'N') || (ch == 'n')){
            cout<<"Thank you for using ATM"<<endl;
            exit(0);
        }
    }else if(atms.wallet < 0)
    {
        cout<<"There's no enough money in your wallet!!"<<endl;
        cout<<"Do you want return to menu? <y/n>"<<endl; 
        cin>>ch;
        if((ch == 'Y') || (ch == 'y')){

            choice(atms);
        }else if((ch == 'N') || (ch == 'n')){
            cout<<"Thank you for using ATM"<<endl;
            exit(0);
        }
            }
    break;
    case 4: 
    atms.wallet -=300;
    if(atms.wallet > 0){
         cout<<"you withdraw: 300"<<endl;
        cout<<"your balance now: "<<atms.wallet<<endl;
        cout<<"Do you want somthing else? (back to menu) <y/n>"<<endl; 
        cin>>ch;
        if((ch == 'Y') || (ch == 'y')){

            choice(atms);
        }else if((ch == 'N') || (ch == 'n')){
            cout<<"Thank you for using ATM"<<endl;
            exit(0);
        }
    }else if(atms.wallet < 0)
    {
 cout<<"There's no enough money in your wallet!!"<<endl;
        cout<<"Do you want return to menu? <y/n>"<<endl; 
        cin>>ch;
        if((ch == 'Y') || (ch == 'y')){

            choice(atms);
        }else if((ch == 'N') || (ch == 'n')){
            cout<<"Thank you for using ATM"<<endl;
            exit(0);
        } 
           }
    break;
    case 5:
    cout<<"Enter amount you want to withdraw"<<endl;
    cin>>money;
    atms.wallet -=money;
    if(atms.wallet > 0){
         cout<<"you withdraw: "<<money<<endl;
        cout<<"your balance now: "<<atms.wallet<<endl;
        cout<<"Do you want somthing else? (back to menu) <y/n>"<<endl; 
        cin>>ch;
        if((ch == 'Y') || (ch == 'y')){

            choice(atms);
        }else if((ch == 'N') || (ch == 'n')){
            cout<<"Thank you for using ATM"<<endl;
            exit(0);
        }
    }else if(atms.wallet < 0)
    {
cout<<"There's no enough money in your wallet!!"<<endl;
        cout<<"Do you want return to menu? (back to menu) <y/n>"<<endl; 
        cin>>ch;
        if((ch == 'Y') || (ch == 'y')){

            choice(atms);
        }else if((ch == 'N') || (ch == 'n')){
            cout<<"Thank you for using ATM"<<endl;
            exit(0);
        } 
            }
    break;
    case 6:
    choice(atms);
    break;
    default:
        cout<<"Error input"<<endl; 
        exit(0);
    }

}


void Diposit(ATM &atms){

int num , dipos;
char ch;
system("clear"); //for linux

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
        choice(atms);
    }
        break;
    
    default:
       cout<<"Error input"<<endl; 
       exit(0);
    }
}


void Display(ATM &atms){
system("clear"); //for linux

char ch;
cout<<"Your balance now is: "<<atms.wallet<<endl; 
cout<<"You have saving now: "<<atms.saving<<endl;

cout<<"if you dont want anything else choic M to back to menu"<<endl
    <<"if you want to saving option choice S"<<endl;
    cin>>ch;
if((ch == 'M') || (ch == 'm')){
        choice(atms);
    }else if((ch == 'S') || (ch == 's')){
       Saving(atms);
    }
}

void Saving(ATM &atms){
    system("clear"); //for linux

int mo;
char ch;
cout<<"Welcome to saving account"<<endl
    <<"you can transfer your money to saving"<<endl
    <<"in order to save your money for future :)"<<endl
    <<"how many you want to transfer?"<<endl; 
    cin>>mo;
    if(atms.wallet > 0){
    atms.wallet -=mo;
    atms.saving +=mo;

    cout<<"In your wallet is: "<<atms.wallet <<endl; 
    cout<<"In your saving is: "<<atms.saving<<endl; 
    }else if(atms.wallet < 0){
    cout<<endl;
    cout<<"There is no enough money in your wallet"<<endl; 
    }
    cout<<"Do you want something else? (back to menu) <y/n>"<<endl; 
    cin>>ch; 
 
    if((ch =='Y')||(ch == 'y')){
        choice(atms);
    }else if((ch =='N')||(ch == 'n')){
        cout<<"Thank you for using ATM"<<endl; 
        exit(0);
    }
}