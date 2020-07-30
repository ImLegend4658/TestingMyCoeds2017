#include<iostream>
#include<ctime>
using namespace std; 

int main(){


	time_t now = time(0);
	tm *ltm = localtime(&now)

	int theyear; 
	theyear = 1900+ltm->tm_year; // current year;
	 cout << "Month: "<< 1 + ltm->tm_mon<< endl; // current month
	 ltm->tm_mday;// current day;
	 cout << "Time: "<< 1 + ltm->tm_hour << ":"; //current time of hour
   cout << 1 + ltm->tm_min << ":"; // current time of minuts
   cout << 1 + ltm->tm_sec << endl; // current time of second;

  //cout<< ltm-><<endl; 

}