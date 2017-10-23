#include <iostream>
#include <cstdlib>
#include <string>
/*
 *this program about to recieve information about the students, numbers and gpa 

 * all copy right @ 2017 Aziz Alawk and please do not delete the names or edit something.
 * */
using namespace std;

class myStudent
{
	public:


		void myStudent1(string StudentNAme);
		void myStudent2(double studentGPA);
		void myStudent3(int THEID);

		void setMyS();
		string getMyS();

		void setMyS2();
		double getMyS2();

		void setMyS3();
		int getMyS3();

		void display();

	private:
		double gpa;
		string name;
		int id;
};

int main()
{

	    myStudent thesomething;
	
		   

	      thesomething.display(); // it will go to display functons right way>>
		   
	      


	       }



void myStudent::myStudent1(string StudentNAme)
{
	name = StudentNAme;
}

void myStudent::myStudent2(double studentGPA)
{
	gpa = studentGPA;
}

void myStudent::myStudent3(int THEID){
	id = THEID;
}


void myStudent::setMyS(){

	string YourStudentNAME;

	cout<<"Enter Student name "<<endl;
	getline(cin, YourStudentNAME);

	myStudent1(YourStudentNAME);
}

string myStudent::getMyS(){
	return name;
}


void myStudent::setMyS2()
{
	double SGPA;

	cout<<"Enter the final GPA student "<<endl;
	cin>> SGPA;

	myStudent2(SGPA);

}

double myStudent::getMyS2(){

	return gpa;

}

void myStudent::setMyS3(){

	int Theid[30];

	for (int i =0; i<30;i++)
	{
		Theid[i] = rand();
		myStudent3(Theid[i]);
	}
}

int myStudent::getMyS3(){
	return id;

}

void myStudent::display(){

	setMyS(); 
	setMyS2();
	setMyS3();
	
// it will ask the user about the name, and gpa, also it will create own ID. 
//
	 cout<<"Your student's name: "<< getMyS()<< ", his GPA is "<< getMyS2() <<" and his ID: "<<getMyS3()<<endl;
// Recieve information from user and prompt.
}
