#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
/*
Author: Abdulaziz Aldawk
date:5/4/2020
purpose: This program will collect students name and the user will add the names with grade as well

*/
class programcourse{
	public:
	void information(int Theid, string Fname, string Lname, string emails);
	void grades(int grad);
	void lettergrade(char letters);

	void details(programcourse mycourse[]);
	int get_ID();
	int get_GRADE();
	char get_LETTER();
	string get_fname();
	string get_lname();
	string get_email();

	void set_exam(programcourse mycourse[]);
	void set_letter();
	void search(programcourse mycourse[]);
	void menu(programcourse mycourse[]);
	void Display(programcourse mycourse[]);
	private:
	int id;
	int finalgrade;
	char letterGrade;
	string studentFirstname;
	string studentLastname;
	string email;
};

int main(){
int siza = 5;
programcourse mycourse[siza];

mycourse[siza].menu(mycourse);
}

void programcourse::menu(programcourse mycourse[]){

	
	int choic;
	cout<<endl;
	cout<<"Select your choic menu:"<<endl
		<<"1) Add student details"<<endl
		<<"2) add three exams integer"<<endl
		<<"3) search for ID"<<endl
		<<"4) Display all student information"<<endl
		<<"5) to exit"<<endl;
	cin>>choic;

	switch (choic)
	{
	case 1:
	for (int i =0;i<5;i++){
		cout<<"student number: "<<i+1<<endl;
	// me[i].details();
	mycourse[i].details(mycourse);
	
	}
	menu(mycourse);
	break;
	case 2:
		for (int i =0;i<5;i++){
	cout<<"student number: "<<i+1<<endl;
	mycourse[i].set_exam(mycourse);
		}
	menu(mycourse);
	break;
	case 3:

	for (int i=0;i<5;i++){
		mycourse[i].search(mycourse);
	}
	// menu(mycourse);
	break;
	case 4:
	cout<<"Student information here:"<<endl;

	cout<<"-----------------------------------------------"<<endl;
	cout<<"ID      name(first/last)      email       grades"<<endl;
	cout<<"-----------------------------------------------"<<endl;
	for (int i =0;i<5;i++){
	// me[i].Display();
	mycourse[i].Display(mycourse);
	}
	menu(mycourse);
	break;
	case 5:
	cout<<"Thank you for using user interface :)"<<endl;
	exit(0);
	}
}

void programcourse::details(programcourse mycourse[]){

	string f_name, l_name, emailq;
	int ids;

	cout<<"Enter first name"<<endl; 
	cin>>f_name;
	cout<<"Enter last name"<<endl; 
	cin>>l_name;
	cout<<"Enter email"<<endl;
	cin>>emailq;

	ids = rand()%30;
	information(ids, f_name, l_name,emailq);

	// set_exam();
	// char ch; 
	// cout<<"return to menu? <y/n>"<<endl; 
	// cin>>ch;
	// if((ch == 'y') && (ch == 'Y')){
	// 	menu();
	// }
	// menu(mycourse);
}

void programcourse::set_exam(programcourse mycourse[]){

	int grade1, grade2, grade3, results, res2;
	int ave, myid;
	cout<<"Enter ID: "<<endl; 
	cin>>myid;
	
	cout<<"Enter three exams integer"<<endl; 
	cin>>grade1;
	cin>>grade2;
	cin>>grade3;

	results = grade1 + grade2 + grade3;
	res2 = results/3;
	if(get_ID() == myid){
	grades(res2);
	set_letter();
	// cout<<"The Student: "<<get_fname()<<" "<<get_lname()<<" "<<get_ID()<<""<<get_GRADE()<<endl;
	cout<<"ID: "<<get_ID()<<endl;
	cout<<"Student first name:"<<get_fname()<<endl;
	cout<<"Student Last name: "<<get_lname()<<endl;

	cout<<"Grade: "<<get_GRADE()<<"("<<get_LETTER()<<")";
	cout<<endl;
	}else
	{
		cout<<"not true"<<endl;
		menu(mycourse);
	}
	
	// cout<<get_LETTER()<<endl;

	// menu(mycourse);
	
}

void programcourse::set_letter(){

	if((get_GRADE() >=0 )&& (get_GRADE()<=59)){
		lettergrade('F');
	}else if((get_GRADE() >=60 )&& (get_GRADE()<=69)){
		lettergrade('D');
	}else if((get_GRADE() >=70 )&& (get_GRADE()<=79)){
		lettergrade('C');
	}else if((get_GRADE() >=80 )&& (get_GRADE()<=89)){
		lettergrade('B');
	}else if(get_GRADE() <=90 ){
		lettergrade('A');
	}else {
		cout<<"Error"<<endl;
	}

	//  set_exam();
}

void programcourse::search(programcourse mycourse[]){
	int idq;
		// cout<<get_ID()<<endl;

	cout<<"Enter ID to search for"<<endl; 
	cin>>idq;

 	if(idq == get_ID()){
		cout<<"found"<<endl;
		cout<<"ID: "<<get_ID()<<endl;
		cout<<"Student first name:"<<get_fname()<<endl;
		cout<<"Student Last name: "<<get_lname()<<endl;	
		cout<<"Grade: "<<get_GRADE()<<"("<<get_LETTER()<<")";
		cout<<endl;
		menu(mycourse);
	}else
	{
		cout<<"not found"<<endl;
		menu(mycourse);
	}
	// menu(mycourse);
}

void programcourse::Display(programcourse mycourse[]){

	// cout<<"Student information here:"<<endl;

	// cout<<"-----------------------------------------------"<<endl;
	// cout<<"ID      name       email       grades"<<endl;
	// cout<<"-----------------------------------------------"<<endl;
	cout<<" | "<<get_ID()<<" | "<<get_fname()<<" | "<<get_lname()<<" | "<<get_email()<<" | "<<get_GRADE()<<"("<<get_LETTER()<<")";
	cout<<endl;
// menu(mycourse);
}

void programcourse::information(int Theid, string Fname, string Lname, string emails){
	id = Theid;
	studentFirstname = Fname;
	studentLastname = Lname;
	email = emails;
}

void programcourse::grades(int grad){
	finalgrade = grad;
}

void programcourse::lettergrade(char letters){
	letterGrade = letters;
}

int programcourse::get_ID(){
	return id; 
}

int programcourse::get_GRADE(){
	return finalgrade;
}

string programcourse::get_fname(){
	return studentFirstname;
}

string programcourse::get_lname(){
	return studentLastname;
}

string programcourse::get_email(){
	return email;
}

char programcourse::get_LETTER(){
	return letterGrade;
}