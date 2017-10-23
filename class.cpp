#include<iostream>
#include<string>
#include<cstdlib>
using namespace std; 
/*this program about ask user who wants to regest on webside like Facebook 
 * it will requiare user, pass and email. 
 *
 * all copy right@ Aziz Aldawk 2017*/
class resg
{
	public:
void TheUser(string &user1);
void Pass(int &password1);
void Email(string &emails11);
void setUsers();
string  getUsers();
void setPass();
int  getPass();
void setEmail();
string  getEmail();
void Display();

	private:
string user;
int password;
string email;
};

int main(){

resg REGS;
REGS.Display();
}


void resg::TheUser(string &user1){

	user = user1;
}

void resg::Pass(int &password1)
{

	password = password1;

}

void resg::Email(string &emails11)
{

	email = emails11;
}

void resg::setUsers(){
	string names;
	cout<<"Enter User name:"<<endl;
	getline(cin,names);
	TheUser(names);
}

string resg::getUsers(){
	return user;
}


void resg::setPass(){
	int passw;
	cout<<"Enter a new password"<<endl; 
	cin>>passw;
	Pass(passw);
}

int resg::getPass(){
	return password;
}


void resg::setEmail(){

	string email98;

	cout<<"please enter the Email"<<endl;
	cin>>email98;
	Email(email98);
}


string resg::getEmail(){
	return email;
	}


void resg::Display(){

	setUsers();
	setPass();
	setEmail();


	cout<<"The user name is: "<<getUsers()
		<<"the pass: "<<getPass()
		<<"Your email: "<<getEmail()<<endl;

}
