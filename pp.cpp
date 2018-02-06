#include<iostream>
using namespace std;
/*This program only like scratch paper. 
 * anyway: the idea is to study about the pointer how to react and follow the way of connection. 
 * Also, see what is varity between new or without new fucction. 
 *
 * Please note: this is pointer idea only and it much different then link list and this 
 * IS NOT LINK LIST IDEA EVER 
 *
 * All copy right@2017 Aziz Aldawk and please feel free to copy or study about it :) */
int main(){

int *p1, *p2;

p1 = new int;
*p1=77; // on my thery on the beginning, has to put <new> to locate address on memory. 
cout<<*p1<<endl;

cout<<"=========="<<endl;
//*p1 =23;
p2= p1;

cout<<*p2 <<"---"<<*p1<<endl; // reminder: has to put star or it will show up the memory address .

cout<<"======== make it oppsite: ===:"<<endl;

p1= p2;

cout<<*p2<<"===="<<*p1<<endl;
// same result and there is no much different::::

cout<<"==== lets put p2 number and play with it==="<<endl;

*p2 = 100;

cout<<*p2 <<"===="<<*p1<<endl; // it copy by self from (p1=p2)
// which mean p2 assigned to p1 as pointer.

cout<<"---- what if i make it oppisite to p2= p1---"<<endl;

p2=p1; 
cout<<*p2<<"====="<<*p1<<endl;
// on my thery it takes from last point is 100
//


p1= new int;
*p1 =95;

cout<<*p1<<"==="<<*p2<<endl;

p2=p1;
cout<<*p1<<"==="<<*p2<<endl;
p1=p2;
cout<<*p1<<"-=-="<<*p2<<endl;


}

/*Ok it makes sens if i put new only on P2, it will change the number
 * but if i assigned like p2 to p1 will be assigned from last one 
 * for example:
 * p1 = new int
 * *p1 = 88;
 * it will be like : p1 as 88 and p2 as 100 
 * but if i did like 
 * p1 = p2
 * both of them will be 88 from p1 because it assined as pointer unless if i use new function...................... Note for pointer 23/10/2017 */

