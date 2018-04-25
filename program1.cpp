#include <iostream>
#include <string>
 using namespace std;
/*
Name: Aziz Aldawk
Date: 4/23/2018
Class: I308
Language : C++
purpose: Project 1 / Program 1

*/

int getPrime(int);
int hash_code_map(int act, string name);

class node
{
public:
	int account_number;
	string name;
	double balance;
	node * next;
public:
	node(int v, string n, double b);
};

node::node(int v, string n, double b)
{
	this->account_number = v;
	this->name = n;
	this->balance = b;
	this->next = NULL;
}

class hashtable
{
public:
	node ** array;
	int size;
public:
	hashtable(int n);
	void insert(int act, string n, double b);
	void remove(int act, string name);
	node * search(int act, string name);
};

hashtable::hashtable(int n)
{

    size = getPrime(n);

	array = new node*[size];
	for (int i = 0; i < size; i++)
	{
		array[i] = NULL;

	}
	this->size = size;
	// your code goes here
	// (1) determine the array size;
	// (2) allocate space for array
	// (3) set each cell in the array point to NULL



}


void hashtable::insert(int act, string n, double b)
{
	// your code goes here
	// create a node and insert it to the hashtable
	int HashValue = hash_code_map(act, n) % size;

        node * new_node= new node(act, n, b);
        new_node->next = NULL;
        new_node->next = array[HashValue];
        array[HashValue] = new_node;
}

//fixed :)
void hashtable::remove(int act, string n)
{
	// your code goes here
	// find the node and delete it.
	// do nothing if it can not be found

	int HashValue = hash_code_map(act, n)% size;

    while (array[HashValue] != NULL && array[HashValue]->name == n)
	{
		node * temp = array[HashValue];
		array[HashValue] = array[HashValue]->next;
		delete temp;
	}

	if (array[HashValue] == NULL)
		return;

	else
	{
		node * Temp_1 = array[HashValue];
		node * Temp_2 = array[HashValue]->next;

		while (Temp_2 != NULL)
		{
			if (Temp_2->name == n)
			{
				node * temp = Temp_2;
				Temp_2 = Temp_2->next;
				Temp_1->next = Temp_2;
				delete temp;
			}
			else
			{
				Temp_1 = Temp_2;
				Temp_2 = Temp_2->next;
			}
		}
	}
}

node * hashtable::search(int act, string name)
{
	// your code goes here
	// find the node and return it (the pointer).
	// retun NULL if it can not be found

     int i = hash_code_map(act, name)% size;

	while(array[i] !=NULL)
	{
        if(array[i]->account_number == act && array[i]->name == name)
            break;
        else
            array[i]= array[i]->next;
	}

return array[i];
 }

//no change
int getPrime(int n)
{
	// your code goes here
	// return the smallest prime number that is greater than n
	// suppose n>=2
for (int i =2; i<n; i++)
{
if ((n%i) ==0)
{
return getPrime(n+1);
}

}

return n;
}

//no changes
int hash_code_map(int act, string name)
{
	// your code goes here
	// map(convert) account number (act) and name into an integer
	// act + summation of the ASCII values of each character in the string
    int hash_code = act;

    for (unsigned i = 0; i< name.length(); ++i)

    hash_code+= name[i];

    return hash_code;

}


//no changes
int main()
{
	hashtable ht(100);
	ht.insert(2002, "Janet Smith", 100.99);
	ht.insert(1001, "Alex Bush", 99.88);
	ht.insert(3003, "John Rosa", 5.55);
	ht.insert(1002, "Liguo Yu", 8.88);

 	node * n;

	n = ht.search(1001, "Alex Bush");

	if (n!=NULL) cout << "the balalnc of account 1001 is "<< n->balance << endl;
	else cout << "could not find account 1001";

	ht.remove(1001, "Alex Bush");

n = ht.search(1001, "Alex Bush");
if (n!=NULL) cout << "the balalnc of account 1001 is "<< n->balance << endl;
else cout << "could not find account 1001" << endl;


	n = ht.search(1002, "Liguo Yu");

	if (n!=NULL) cout << "the balalnc of account 1002 is "<< n->balance << endl;
	else cout << "could not find account 1002";

	return 1;
}
/*
// if your hashtable is corrected implemented,
// you should see the following result:

the balalnc of account 1001 is 99.88
could not find account 1001

*/
