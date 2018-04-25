#include <iostream>
#include <string>
 using namespace std;
/*
Name: Aziz Aldawk
Date: 4/23/2018
Class: I308
Language : C++
purpose: Project 1 / Program 2

*/

int getPrime(int);
int hash_code_map(int act, string name);

class node
{
public:
	int account_number;
	string name;
	double balance;
	node * left;
	node * right;
public:
	node(int v, string n, double b);
};

node::node(int v, string n, double b)
{
	this->account_number = v;
	this->name = n;
	this->balance = b;
	this->left = NULL;
	this->right = NULL;
}

//no change
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

//no change
hashtable::hashtable(int n)
{

    size = getPrime(n);

	array = new node*[size];
	for (int i = 0; i < size; i++)
	{
		array[i] = NULL;

	}
	this->size = size;


}

//needs to change
void hashtable::insert(int act, string n, double b)
{
	// your code goes here
	// create a node and insert it to the hashtable
	int HashValue = hash_code_map(act, n) % size;

    if(array[HashValue] == NULL)
	{
		array[HashValue]=new node(act, n, b);
	}
	else if(act < array[HashValue]->account_number)
	{
		// one line of code goes here. hint: recursive call
		insert(act, n, b);
    }
	else if(act > array[HashValue]->account_number)
	{
		// one line of code goes here. hint: recursive call
		insert(act, n, b);
    }
	else // same value found, do not need to insert
	;

}

//needs to change
void hashtable::remove(int act, string n)
{
	// your code goes here
	// find the node and delete it.
	// do nothing if it can not be found

	int HashValue = hash_code_map(act, n)% size;

    if(array[HashValue]== NULL)
	{
		return; //item not found; do nothing
	}
	else if(act <array[HashValue]->account_number)
	{
		// one line of code goes here. hint: recursive call
		remove(act, n);
    }
	else if(act > array[HashValue]->account_number)
	{
		// one line of code goes here. hint: recursive call
		remove(act,n);
    }
	else // found the node to remove
	{
		if (array[HashValue]->left != NULL && array[HashValue]->right != NULL) // two children
		{
		remove(act,n);
		}
		else if(array[HashValue]->left != NULL) // one chiild
		{
			// your code goes here
			// delete the node
			node * oldNode = array[HashValue];

			array[HashValue] = array[HashValue]->left;
			delete oldNode;

		}
		else if(array[HashValue]->right != NULL) // one child
		{
			// your code goes here
			// delete the node
			node * oldNode = array[HashValue];
			array[HashValue] = array[HashValue]->right;
			delete oldNode;

		}
		else // no child
		{
			// your code goes here
			// delete the node

			node * oldNode =array[HashValue];
			array[HashValue] = NULL;
			delete oldNode;
		}
	}
}

//needs to change
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
            array[i]= array[i]->right;
            array[i]= array[i]->left;
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
