#include<stream>
#include<string>
using namespace std;

struct log{
    string username;
    int password;
};
void login(); //function is so spread
void uname(log &ll);
void upass(log &ll);

int main(){
login();

}

void login(){
    log ll;

    uname(ll);
    upass(ll);
}

void uname(log &ll){
    cout<<"Please enter a new username:: "<<endl;
    cin>>ll.username;
}

void upass(log &ll){
    cout<<"Enter a new password: "<<endl;
    cin>>ll.password;
}
