
#include <iostream>
#include <string>
#include<cstdlib>

/*
Author: Aziz Aldawk
Program: This insurance program that show all information's customer 
and add inforamtion's customers. 

all copyright@Aziz Aldawk 
please dont use it as belong to you.
or dont cheat by copy it and rename it. 
just understand the idea and do by your own code. 
Thanks.
*/
using namespace std;
class insurance{
  public:
  void INFOR(int Cust_AGE, string Cust_NAME, int H_accident, double DISCOUNT1, int Theprice);
  void menu(insurance ThierINSURENCE[]);
  void details(insurance ThierINSURENCE[]);
  void display(insurance ThierINSURENCE[]);
  int get_AGE();
  string get_name();
  int get_haccdent();
  double get_dis();
  int get_price();
  private:
  int age; 
  string nameCustomer;
  int How_many_Accdent;
  double discount; 
  int price;
};
//construct
void insurance::INFOR(int Cust_AGE, string Cust_NAME, int H_accident, double DISCOUNT1, int Theprice)
{
  age = Cust_AGE;
  nameCustomer = Cust_NAME;
  How_many_Accdent = H_accident;
  discount = DISCOUNT1;
  price = Theprice;
}
int sizs = 5; // globle variables. 

int main(){
//int sizs = 5;
insurance ThierINSURENCE[sizs];

ThierINSURENCE[sizs].menu(ThierINSURENCE);

}

void insurance::menu(insurance ThierINSURENCE[]){
// system("clear");
cout<<"welcome to Water insurance"<<endl;
cout<<"please note: if customer's age 18 or less has no discount"<<endl
    <<"if customer's age 19 or more and no accident will have discount 60%"<<endl
    <<"if customer's  age 19 or more and 2 accident will have discount 30%"<<endl
    <<"otherwise, more then 3 accident, will have no discount"<<endl; 

    int select; 

    cout<<"To enter customer informations <1>"<<endl
        <<"Display customers information  <2>"<<endl
        <<"Exit?                          <0>"<<endl; 
    cin>>select;

    switch (select)
    {
    case 1:
    system("clear");
    for (int i =0;i<sizs;i++){
      cout<<"============================="<<endl;
		cout<<"Customer number: "<<i+1<<endl;
	
	ThierINSURENCE[i].details(ThierINSURENCE);
	
	}
      cout<<"============================="<<endl;

	menu(ThierINSURENCE);

   break;

   case 2:
   system("clear");
   cout<<"Welcome to display all customers information"<<endl; 
   cout<<"There's Customers inforamtion"<<endl; 
   cout<<"============================="<<endl; 
   for (int i =0;i<sizs;i++){
    cout<<"============================="<<endl; 

		cout<<"< (--> Customer number: "<<i+1<<" <---)"<<endl;
	ThierINSURENCE[i].display(ThierINSURENCE);
	
	}
  cout<<"==============================="<<endl; 
	menu(ThierINSURENCE);
   break; 
  
  case 0: 
cout<<"Thank you for using insurance program"<<endl;
exit(0);
  break;
    default:
    cout<<"Error selection, program will exitting>>>"<<endl; 
    exit(0);
      break;
    }

}


void insurance::details(insurance ThierINSURENCE[])
{

 int age21; 
  string nameCustomer221;
  int How_many_Accdent122;
  double discount22; 
  int price22 = 500; 
  int afterdis;
  int Finalprice;

  cout<<"Enter Customer name"<<endl; 
  cin>>nameCustomer221;
  cout<<"Age ?"<<endl; 
  cin>>age21;
  cout<<"How many accident they had?"<<endl; 
  cin>>How_many_Accdent122;

  if((age21 <= 18) && (How_many_Accdent122 == 0)){
    cout<<"There is no discount for you"<<endl; 
        Finalprice = price22;

    cout<<"Price is: $"<<Finalprice<<endl; 
  }else if((age21 >= 19) && (How_many_Accdent122 == 0)){
    cout<<"There is discount %60"<<endl;
    discount22 = 0.6;
    afterdis = (price22 * discount22);
    Finalprice= (price22 - afterdis);
    cout<<"Price is: $"<<Finalprice<<endl;
  }else if((age21 >= 19) && (How_many_Accdent122 <= 2)){
    cout<<"There is discount %30"<<endl;
    discount22 = 0.3;
    afterdis = price22 * discount22;
    Finalprice= price22 - afterdis;
    cout<<"Price is: $"<<Finalprice<<endl;
  }else if((age21 >= 19) && (How_many_Accdent122 >= 2))
  {
    cout<<"There is no discount for you if you had more then 3 accident"<<endl; 
    Finalprice = price22;
    cout<<"Price is: $"<<Finalprice<<endl;
  }
  
INFOR(age21, nameCustomer221, How_many_Accdent122, discount22,Finalprice);
  
}

void insurance::display(insurance ThierINSURENCE[]){

cout<<"Customer name: "<<get_name()<<endl; 
cout<<"Customer age: "<<get_AGE()<<endl;
cout<<"number of accidents: "<<get_haccdent()<<endl; 
cout<<"Dicount: "<<get_dis()<<endl; 
cout<<"Final price: "<<get_price()<<endl; 
}

  int insurance::get_AGE(){
    return age;
  }

  string insurance::get_name(){
    return nameCustomer;
  }

  int insurance::get_haccdent(){
    return How_many_Accdent;
  }

  double insurance::get_dis(){
    return discount;
  }

  int insurance::get_price(){
    return price;
  }