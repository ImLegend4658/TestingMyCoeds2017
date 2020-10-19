#include<iostream>
#include<ctime>
using namespace std; 

int main(){
	time_t now = time(0);
	tm *ltm = localtime(&now);

    int year,month,day;
    int dbyear,dbmonth,dbday;
    int youryear,yourmonth,yourday;


    year= 1900+ltm->tm_year;
    month = 1 + ltm->tm_mon;
    day = ltm->tm_mday;
    int future;
    cout<<"Current date is: "<<year<<"/"<<month<<"/"<<day<<endl;
    cout<<"Enter your age by year"<<endl;
    cin>>dbyear;
    cout<<"Enter your age by month"<<endl;
    cin>>dbmonth;
    cout<<"Enter your age by day"<<endl;
    cin>>dbday;

    youryear = year - dbyear;
    yourmonth = month - dbmonth;
    yourday = day - dbday;

    cout<<"your age in year: "<<youryear<<endl;
    cout<<"in month: "<<yourmonth<<endl;
    cout<<"in day: "<<yourday<<endl;
    future= youryear + year; 

    cout<<"your age will be 100 in :"<<future<<" year"<<endl; 

}