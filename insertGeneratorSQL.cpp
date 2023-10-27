// it will generate insert for database and make sure file names. 

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream input;
    input.open("Fname");
    if (!input.is_open()) {
        cerr << "Failed to open input file!" << endl;
        return 1;
    }

  ifstream lastname;
    lastname.open("lastname");
    if (!lastname.is_open()) {
        cerr << "Failed to open lastname file!" << endl;
        return 1;
    }

    ofstream readME("insert.txt");
    if (!readME.is_open()) {
        cerr << "Failed to open output file!" << endl;
        input.close();
        lastname.close();
        return 1;
    }

    string text;
    string lname;
    int i = 1;
int st; 
    while (getline(input, text),   (getline(lastname, lname))) {
        st = rand() % 100000;
        string lines = "Insert into customer values(" + to_string(i) + ",'" + text + "','"+ lname +"'055"+ to_string(st)  +"');";
        readME << lines << endl;
        i++;
    }

    readME.close();
    input.close();
     lastname.close();
    return 0;
}
