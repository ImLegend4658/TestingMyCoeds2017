#include <iostream>
#include <string>

using namespace std;
void sumN(int sum);
void subN(int sub);
void miltN(int milt);
int main()
{

	int sum;
	int sub;
	int milt;

	int number;

	cout<<"The Sum numbers enter <1>"<<endl
		     <<"The sub numbers enter <2>"<<endl
		          <<"The Multiplay enter <3>"<<endl;
	     cin>>number;

	          switch(number)
		  {
			  case 1:
				  sumN(sum);
				  break;
			  case 2:
				  subN(sub);
				  break;
			  case 3:
				  miltN(milt);
				  break;
defualt:
cout<<"ERROR"<<endl;
		  }
}

void sumN(int sum)
{
	int x, y;
	cout<<"enter first and second number to sum"<<endl;
	cin>>x>>y;

	sum= x+y;

	cout<<x<<" + "<<y<<"= "<<sum<<endl;
}

void subN(int sub)
{
	int x, y;
	cout<<"enter first and second number to substract"<<endl;
	cin>>x>>y;

	sub= x-y;
	cout<<x<<" - "<<y<<" = "<<sub<<endl;

}

void miltN(int milt)
{
	int x, y;
	cout<<"enter first and second number to miltplay numbers"<<endl;
	cin>>x>>y;


	milt = x*y;

	cout<<x<<" * "<<y<<" = "<<milt<<endl;

}
