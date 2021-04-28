#include<iostream>
#include<string>
 using namespace std; 

struct num{
   string name;
};

void entername(num &thisname);
void countChar(num &thisname);
void backWord(num &thisname);
void vo_letter(num &thisname);

int main(){
num thisname; 

entername(thisname);
countChar(thisname);
backWord(thisname);
vo_letter(thisname);


}


void entername(num &thisname){
   cout<<"Enter your name sir:"<<endl; 
   getline(cin,thisname.name);

 cout<<"Your name: "<<thisname.name<<endl;
}


void countChar(num &thisname){
   int len = 0;

   for(int i=0;i<=thisname.name.length();i++){
      if(thisname.name[i] != ' '){
         len++;
      // cout<<thisname.name.length()<<endl;   
     // cout<<i<<endl;
   //   break;

      } 
   }
   cout<<"Letters: "<<len-1<<endl;
   
}

void backWord(num &thisname){

string temp;
    for (int i = thisname.name.length()-1;i>=0;i--){
temp+= thisname.name[i];
}
cout<<temp<<endl;
}

void vo_letter(num &thisname){
   int a =0;
   int e =0;
   int I = 0;
   int o = 0;
   int U = 0;

  for(int i=0;i<=thisname.name.length();i++){
      if((thisname.name[i] == 'a') || (thisname.name[i] == 'A')){
         a++;

      }else if((thisname.name[i] == 'e') || (thisname.name[i] == 'E') ){
         e++;
      }else if((thisname.name[i] == 'i') || (thisname.name[i] == 'i') ){
         I++;
      }else if((thisname.name[i] == 'o') || (thisname.name[i] == 'O')) {
         o++;
      }else if ((thisname.name[i] == 'u') || (thisname.name[i] == 'U')) {
         U++;
      }

   }

   cout<<"A: "<<a<<endl;
   cout<<"E: "<<e<<endl;
   cout<<"I: "<<I<<endl;

   cout<<"O: "<<o<<endl;

   cout<<"U: "<<U<<endl;

}
