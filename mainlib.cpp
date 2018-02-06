/*  
    A library for all of my favorite functions
    created by: Jordan Winkler

    Table of contents:
        Functions:
            factorial
            choose
            pick
            min
            max
            power
            quickSort
            --changeToBase  
            --heronsFormula
            --gcd
            gcdLong
            gcdExtended
            getInt          //found bugs
            stringToPosInt
            stringToInt
            stringToFloat
            getLong
            binarySearch
            --isPrime
            timesCalled
            --breakIntoPrimes //found bugs
            intLog
            --phi             
            phiInverseCap
            phiInverse
            --tau     
            --sigma    
            --mu        
            expMod
            Carmichael      //found bugs
            power
            pseudoPrime
            nextPrime   
            nextPhi    
            decrypt
            encrypt
            modInv
            seive
            higherPrime
            lowerPrime
            lambda
        
        Objects: 
            matrix 
            com (complex numbers)
            rat (rational numbers)
            ratMatrix (rational number matrix) //broken?
            bigInt (4096 bit array) //broken
*/
#define howboutno

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include <vector>
#include <cstdlib>
using namespace std;

/****************************************************************
| Name: factorial
|    
| Precodition: nothing
| Postcondition: nothing
|
| Parameters:
|       
|   IN: number N
|   Out: nothing
|   
| Returns: the factorial of N
\****************************************************************/
template<class t>
t factorial (t N)
{
    if (N < 0) 
    {
        cout << "\nerror: bad factorial \n";
        exit(1);
    }    
    if (N > 1) return factorial (N-1) * N;
    else return 1;
}

/****************************************************************
| Name: choose 
|    
| Precodition: nothing
| Postcondition: nothing
|
| Parameters:
|       
|   IN: numbers N and K
|   Out: Nothing
|   
| Returns: N choose K from mathematics
\****************************************************************/
template<class t>
t choose (t N, t K)
{
    if (N < 0 || K < 0 || K > N) //for some problems it is better
        return 0;                //for 0 to represent failure

    return (factorial(N))/(factorial(K)*(factorial(N-K)));
}

/****************************************************************
| Name: pick
|    
| Precodition: nothing
| Postcondition: nothing
|
| Parameters:
|       
|   IN: the numbers N and K 
|   Out: nothing
|   
| Returns: N pick K from mathematics
\****************************************************************/
template<class t>
t pick (t N, t K)
{
    if (N < 0 || K < 0 || K > N) //for some problems it is better
        return 0;                //for 0 to represent failure

    return (factorial(N))/((factorial(N-K)));
}

/****************************************************************
| Name: max
|    
| Precodition: nothing
| Postcondition: nothing
|
| Parameters:
|       
|   IN: two numbers
|   Out: nothing
|   
| Returns: the highest of the two numbers
\****************************************************************/
template<class t>
t max (t a, t b)
{
    return (a > b)?a:b;
}

/****************************************************************
| Name: min
|    
| Precodition: nothing
| Postcondition: nothing
|
| Parameters:
|       
|   IN: two numbers
|   Out: nothing
|   
| Returns: the lowest of the two numbers
\****************************************************************/
template<class t>
t min (t a, t b)
{
    return (a > b)?b:a;
}

/****************************************************************
| Name: quicksort
|    
| Precodition: an array; 
|               information on the begining and end of the array
| Postcondition: a sorted array
|
| Parameters:
|       
|   IN: array, int for start and end
|   Out: same array 
|   
| Returns: nothing
\****************************************************************/
template<class t>
void quickSort(t arr[], int left, int right) {
      int i = left, j = right;
      t tmp;
      int pivot = arr[(left + right) / 2];
 
      /* partition */
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };
 
      /* recursion */
      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
}


/****************************************************************
| Name: changeToBase
|    
| Precodition: nothing
| Postcondition: nothing
|
| Parameters:
|       
|   IN: number x, base to change to, and a string to hold each
|       n-imal place
|   Out: string of changed base
|   
| Returns: nothing
\****************************************************************/
void changeToBase(int x, int base, int string[], int Max)
{
    for (int i = 0 ; x && i < Max ; i++)
    {
        string[i] = x % base;
        x = x/base;
    }
}

/****************************************************************
| Name: heronsFormula 
|    
| Precodition: Three side lengths of a triangle, <math.h>
| Postcondition: The area of the triangle
|
| Parameters:
|       
|   IN: three doubles
|   Out: nothing
|   
| Returns: double 
\****************************************************************/
double heronsFormula (double A, double B, double C)
{
    double S = (A + B + C)/2.0;
    double Area = pow((S*(S-A)*(S-B)*(S-C)), (1/2.0));
    return Area;
}

/****************************************************************
| Name: gcd
|    
| Precodition: two numbers
| Postcondition: the greatest common divisor of those two numbers
|
| Parameters:
|       
|   IN: int A, and B
|   Out: none
|   
| Returns: int
\****************************************************************/
template<class t>
t gcd(t A, t B)
{
    t T;
    while (B != 0)
    {
        T = B;
        B = A % B;
        A = T;
    }
    return A;
}    

/****************************************************************
| Name: gcdLong
|    
| Precodition: four int arrays
| Postcondition: four int arrays taking on the elements of
|                division algorithm
|
| Parameters:
|       
|   IN: four int arrays, int max length of arrays
|   Out: those same four int arrays
|   
| Returns: nothing
\****************************************************************/
int gcdLong(int aa, int qq)
{
    const int Max = 100000; // c++ 98 is strict about this...
    int a[Max]={0}, q[Max]={0}, b[Max]={0}, r[Max]={0};
    a[0] = aa;
    q[0] = qq;
    
    int lastDivisor = 0;
    for (int i = 0 ; r[i-1] || i == 0 ; i++)
    {
        r[i] = a[i] % b[i];
        q[i] = a[i] / b[i]; 
        
        a[i+1] = b[i];
        b[i+1] = r[i];
        lastDivisor++;
    }
    return b[--lastDivisor];

    //for "showing your work" or debugging
    for (int i = 0 ; r[i-1] || i == 0 ; i++)
    {
        cout << a[i] << '=' << q[i] << '*' << b[i] << '+' << r[i]
             << endl;
    }
}

/****************************************************************
| Name: getInt
|    
| Precodition: <iostream>, <stdlib> ,<math.h> used
| Postcondition: gives back a positive integer that the user typed
|
| Parameters:
|       
|   IN:  none
|   Out: none
|   
| Returns: an int from the user
\****************************************************************/
int getInt()
{
    const int ARRAY_SIZE = int(log10(pow(2, sizeof(int)*8))+1);
    char UserInput[ARRAY_SIZE];
    for (int i = 0 ; i < ARRAY_SIZE ; i++)
        UserInput[i] = 0;
    int ArraySpot = 0;
    int Rows = 0;

    do 
    {
        UserInput[ArraySpot] = cin.get();
        if (ArraySpot > ARRAY_SIZE)
        {
            cout << "\nSmaller number please\n";
            exit(1);
        }
    } while ( UserInput[ArraySpot++] != '\n');
    for (int i = 0 ; i < ArraySpot - 1 ; i++)
    {
        if (UserInput[i] <= '9' && UserInput[i] >= '0')
        {
            Rows += int(UserInput[i] - '0');
            Rows *= 10; 
        }
        else 
        {
            cout << "\nError: non-number\n";
            exit(1);
        }
    }
    return Rows /= 10;
}


/****************************************************************
| Name: stringToPosInt
|    
| Precodition: <iostream>, <stdlib> ,<math.h> used
| Postcondition: gives back a positive integer that the user typed
|
| Parameters:
|       
|   IN:  char*
|   Out: none
|   
| Returns: an int from the user
\****************************************************************/
int stringToPosInt(char* input) 
//char* assumed to come from main argv which has a lot of space on it
{
    /* for flag if number is too big for current architexture */
    const int arrayMax = int(log10(pow(2, sizeof(int)*8))+1); 

    int Rows = 0;

    /* get size of input array, minus null terminator */
    int arraySize = 0;
    while (input[arraySize++] != '\0'); 
    arraySize--;
    
    if (arraySize > arrayMax)
    {
        cout << "\nSmaller number please\n";
        exit(1);
    }

    /* transfer to int */
    for (int i = 0 ; input[i] != '\0' ; i++)
    {
        if (input[i] <= '9' && input[i] >= '0')
        {
            Rows += int(input[i] - '0');
            Rows *= 10; 
        }
        else 
        {
            cout << "\nError: non-number\n";
            exit(1);
        }
    }
    return Rows /= 10;
}


/****************************************************************
| Name: stringToInt
|    
| Precodition: <iostream>, <stdlib> ,<math.h> used
| Postcondition: gives back a positive integer that the user typed
|
| Parameters:
|       
|   IN:  char* string
|   Out: none
|   
| Returns: an int from the user
\****************************************************************/
int stringToInt(char* input) 
//char* assumed to come from main argv which has a lot of space on it
{
    /* for flag if number is too big for current architexture */
    const int arrayMax = int(log10(pow(2, sizeof(int)*8))+1); 

    int Rows = 0;

    /* get size of input array, minus null terminator */
    int arraySize = 0;
    while (input[arraySize++] != '\0'); 
    arraySize--;
    
    if (arraySize > arrayMax)
    {
        cout << "\nSmaller number please\n";
        exit(1);
    }

    /* transfer to int */
    /* if negative */
    if (input[0] == '-')
    {
        for (int i = 1 ; input[i] != '\0' ; i++)
        {
            if (input[i] <= '9' && input[i] >= '0')
            {
                Rows += int(input[i] - '0');
                Rows *= 10; 
            }
            else 
            {
                cout << "\nError: non-number\n";
                exit(1);
            }
        }
        Rows /= 10;
        Rows *= -1;
        return Rows;
    }
    /* if positive */
    for (int i = 0 ; input[i] != '\0' ; i++)
    {
        if (input[i] <= '9' && input[i] >= '0')
        {
            Rows += int(input[i] - '0');
            Rows *= 10; 
        }
        else 
        {
            cout << "\nError: non-number\n";
            exit(1);
        }
    }
    return Rows /= 10;
}

/****************************************************************
| Name: stringToFloat
|    
| Precodition: <iostream>, <stdlib> ,<math.h> used
| Postcondition: gives back a positive integer that the user typed
|
| Parameters:
|       
|   IN:  char* 
|   Out: none
|   
| Returns: a float 
\****************************************************************/
/* need to dummy proof */
double stringToFloat(char* input) 
//char* assumed to come from main argv which has a lot of space on it
{
    /* for flag if number is too big for current architexture */
    const int arrayMax = 50; //floats have 16 digits of precision

    double Rows = 0;

    /* get size of input array, minus null terminator */
    int arraySize = 0;
    while (input[arraySize++] != '\0'); 
    arraySize--;
    
    if (arraySize > arrayMax)
    {
        cout << "\nSmaller number please\n";
        exit(1);
    }

    /* transfer to int thing */
    /* if negative */
    if (input[0] == '-')
    {
        for (int i = 1 ; input[i] != '\0' ; i++)
        {
            if (input[i] <= '9' && input[i] >= '0')
            {
                Rows += int(input[i] - '0');
                Rows *= 10; 
            } /* ignores non digits */
        }
        Rows /= 10;
        Rows *= -1;

        /* find dot */
        int dot = 0; //may not have dot
        for (int i = 0 ; input[i] != '\0' ; i++)
        {
            if (input[i] == '.')
            {
                  /* starting at 0 throws off by 1 */
                dot = arraySize - i - 1; 
                break;
            }
        }
        Rows = Rows/pow(10,dot);
    } 
    else 
    {
        /* if positive */
        for (int i = 0 ; input[i] != '\0' ; i++)
        {
            if (input[i] <= '9' && input[i] >= '0')
            {
                Rows += int(input[i] - '0');
                Rows *= 10; 
            } /* ignores non digits */
        }
        Rows /= 10;

        /* find dot */
        int dot = 0; //may not have dot
        for (int i = 0 ; input[i] != '\0' ; i++)
        {
            if (input[i] == '.')
            {
                  /*starting at 0 throws off by 1 */
                dot = arraySize - i - 1; 
                break;
            }
        }
        Rows = Rows/pow(10,dot);
    }

    /* find dot, non negative */

    return Rows;
}

/****************************************************************
| Name: getLong
|    
| Precodition: <iostream>, <stdlib> ,<math.h> used
| Postcondition: gives back a positive integer that the user typed
|
| Parameters:
|       
|   IN:  none
|   Out: none
|   
| Returns: an long int from the user
\****************************************************************/
long int getLong()
{
    const int ARRAY_SIZE = 
            int(log10(pow(2, sizeof(long int)*8))+1);
    char UserInput[ARRAY_SIZE];
    for (int i = 0 ; i < ARRAY_SIZE ; i++)
        UserInput[i] = 0; // version 98...
    int ArraySpot = 0;
    long int Rows = 0;

    do 
    {
        UserInput[ArraySpot] = cin.get();
        if (ArraySpot > ARRAY_SIZE) //this error comes up 
                                    //before the other
        {
            cout << "\nSmaller number please\n";
            exit(1);
        }
    } while ( UserInput[ArraySpot++] != '\n');
    for (int i = 0 ; i < ArraySpot - 1 ; i++)
    {
        if (UserInput[i] <= '9' && UserInput[i] >= '0')
        {
            Rows += int(UserInput[i] - '0');
            Rows *= 10; 
        }
        else 
        {
            cout << "\nError: non-number\n";
            exit(1);
        }
    }
    return Rows /= 10;
}

/****************************************************************
| Name: binarySearch
|    
| Precodition: An integer array that has been sorted and
|              something to look for
| Postcondition: The location of that thing in an array
|
| Parameters:
|       
|   IN: integers of the array and size and thing to find
|   Out: the same array
|   
| Returns: int location
\****************************************************************/
int binarySearch(int target, int A[], int Size)
{
    int lo = 0, hi = Size, i;
    
    while (lo <= hi)
    {
        i = (lo + hi)/2;
        if (A[i] == target) return i;
        if (A[i] < target)
        /* change return if looking for multiple items */
            lo = i + 1;
        else
            hi = i - 1;
    }
}

/****************************************************************
| Name: isPrime
|    
| Precodition: a number to check
| Postcondition: 1 or 0 if the number is prime
|
| Parameters:
|       
|   IN: int number
|   Out: nothing
|   
| Returns: bool prime or not prime
\****************************************************************/
bool isPrime(int number)
{
    if (number < 2)
        return 0;

    int top = number;
    if (number > 100)  //uses sieve of Eratosthenes
        int top = int(ceil(pow(number, 0.5))); 
    for (int i = 2 ; i < top ; i++)        
        if (number % i == 0)
            return 0;
    return 1;
}

/****************************************************************
| Name: timesCalled
|    
| Precodition: nothing, or has been called before
| Postcondition: the number of times that this function has been
|                called.
|
| Parameters:
|       
|   IN: nothing
|   Out: nothing
|   
| Returns: an integer for how many times function was called in
|          the program
\****************************************************************/
int timesCalled()
{
    static int n = 0;
    return ++n;
}

/****************************************************************
| Name: breakIntoPrimes
|    
| Precodition: <iostream>, <stdlib.h>, an int array, and a number
|              to test
| Postcondition: an array of primes from the tested number
|
| Parameters:
|       
|   IN: int CompositeNumber, int max
|   Out: int array
|   
| Returns: nothing
\****************************************************************/
void breakIntoPrimes(int CompositeNumber, int A[], int MAX)
{
    for (int i = 0 ; i < MAX ; i++) //clean the array
        A[i] = 0;
    
    int j = 0;
    for (int i = 2 ; i <= CompositeNumber ; i++)
    {
        if (CompositeNumber % i == 0)
        { 
            A[j++] = i;
            CompositeNumber /= i;
            i--;
        }
        if (j == MAX)
        {
            cout << "Error: too many primes\n";
            exit(1);
        }
    }
}

/****************************************************************
| Name: intLog
|    
| Precodition: requires math.h
| Postcondition: a computed log
|
| Parameters:
|       
|   IN: an int base and a log int variable
|   Out: Nothing
|   
| Returns: an int logx/log(base)
\****************************************************************/
int intLog(int base, long int x)
{
    return int(log(x)/log(base));
}
int intLog(int base, int x)
{
    return int(log(x)/log(base));
}

  
/*================================================================
|| 
|| Object: matrix 
||
|| Purpose: simulates the linear algebra matrix
|| 
|| Attributes: 
||      MAX (max size of matrix)
||      A[][] (matrix for manipulations)
|| Functions:
||      matrix (Initializer)
||
||      RowEchelonForm
||          ScaleRow
||          SwitchRow
||          AddRow
||          MakePivot
||          ReduceClearDown
||
||      + (is a friend)
||      * (is a friend)
||      
||      Randomize
||      Print
||      Scan
||      Write
||      Solve (put in I if possible)
||
\*==============================================================*/

class matrix
{
public:
    matrix(int theX, int theY);
    void Randomize();
    void Print();
    int Scan();
    int Write();
    int RowEchelonForm();
    int Solve();

    friend const matrix operator +(const matrix &a, 
                                   const matrix &b);
    friend const matrix operator *(const matrix &a, 
                                   const matrix &b);
private:
    double **A; //matrix data
    int Max;    //max size of matrix
    int X;      //location x in matrix
    int Y;      //location y 

    void ScaleRow (int Row, double Scalar);
    void SwitchRow (int Row1, int Row2);
    void AddRow (int RowIn, int RowOut);
    int MakePivot (int Column, int Row);
    int ReduceClearDown (int Column, int Row);
};

matrix::matrix(int theX, int theY)
{
    Max = 1000;
    if (theX < Max && theY < Max)
    {
        X = theX;
        Y = theY;
    }
    else
    {
        cout << "\nError: adjust matrix size\n";
        exit(1);
    }
    A = new double*[X]; //make the matrix
    for (int i = 0; i < X; i++)
        A[i] = new double[Y];
}
/****************************************************************
| Name: Randomize
|    
| Precodition: a 2D array size double with a max size of 1000,
|              2 ints for size of array that user chooses, 
|              <time.h>
| Postcondition: a random array of intergers 1 through 9
|
| Parameters:
|       
|   IN: double array, int X, int Y
|   Out: same array with an X by Y section randomized
|   
| Returns: nothing
\****************************************************************/
void matrix::Randomize()
{
    srand (time(NULL));
    for (int j = 0 ; j < Y ; j++)
    {
        for (int i = 0 ; i < X ; i++)
        {
            A[i][j] = int(rand() % 10);
        }
    }
}

/****************************************************************
| Name: Print
|    
| Precodition: A double 2D array
| Postcondition: The double 2D array is printed onto the screen
|
| Parameters:
|       
|   IN: double 2D array, 2 ints for the dimensions to print
|   Out: The same double 2D array
|   
| Returns: nothing
\****************************************************************/
void matrix::Print()
{
    double FixedPrint; 
    for (int j = 0 ; j < Y ; j++)
    {
        for (int i = 0 ; i < X ; i++)
        {
            if (!(round(100 * A[i][j])/100)) 
                FixedPrint = 0; 
            else FixedPrint = round(100 * A[i][j])/100; 
            cout << FixedPrint << ' ';
        } cout << endl;
    } cout << endl;
}

/****************************************************************
| Name: Scan
|    
| Precodition: A file to pull a matrix from, and a matrix from 
|              mylib.cpp to print onto
| Postcondition: The matrix passed to the program for use 
|
| Parameters:
|       
|   IN: double 2D array, int X, int Y
|   Out: same double 2D array
|   
| Returns: 1 on success
\****************************************************************/
int matrix::Scan()
{
    fstream InData;
    cout << "Enter the name of the file you wish to scan "; 
    //designate file path using string
    string UserInput;
    getline(cin, UserInput);
    InData.open(UserInput.c_str());
    for (int j = 0 ; j < Y ; j++) 
        for (int i = 0 ; i < X ; i++)
            InData >> A[i][j];
    InData.close();
    return 1;
}

/****************************************************************
| Name: ScaleRow
|    
| Precodition: matrix exists
| Postcondition: a given orw of this matrix has been scaled
|
| Parameters:
|       
|   IN: integer for the row, double for the amount to scale
|   Out: Nothing
|   
| Returns: Nothing
\****************************************************************/
void matrix::ScaleRow (int Row, double Scalar)
{
    for (int i = 0 ; i < X ; i++)
    {
        A[i][Row] *= Scalar;
    }
}

/****************************************************************
| Name: SwitchRow
|    
| Precodition: matrix exists
| Postcondition: Two rows in the matrix were switched
|
| Parameters:
|       
|   IN: an integer for each row
|   Out: Nothing
|   
| Returns: Nothing
\****************************************************************/
void matrix::SwitchRow(int Row1, int Row2)
{
    int Temp;
    for (int i = 0 ; i < X ; i++)
    {
        Temp = A[i][Row1];
        A[i][Row1] = A[i][Row2];
        A[i][Row2] = Temp;
    }
}

/****************************************************************
| Name: AddRow
|    
| Precodition: matrix exists
| Postcondition: RowIn + RowOut -> RowOut
|
| Parameters:
|       
|   IN: integer for each row
|   Out: Nothing
|   
| Returns: Nothing
\****************************************************************/
void matrix::AddRow (int RowIn, int RowOut)
{
    for (int i = 0 ; i < X ; i++)
    {
        A[i][RowOut] = A[i][RowOut] + A[i][RowIn];
    }
}

/****************************************************************
| Name: MakePivot
|    
| Precodition: matrix exists
| Postcondition: a pivot element has been made at position
|                Column, Row
|
| Parameters:
|       
|   IN: int for the Column and Row
|   Out: Nothing
|   
| Returns: 1 on success, 0 on failure
\****************************************************************/
int matrix::MakePivot (int Column, int Row)
{
    for (int i = Row + 1 ; i < Y ; i++)
        if (A[Column][Row])
        {
            ScaleRow(Row, 1/A[Row][Column]);
            return 1;
        }
        else SwitchRow(Row, i);
    if (A[Column][Row]) 
    {
        ScaleRow(Row, 1/A[Row][Column]);
        return 1;
    }
    else return 0;
}

/****************************************************************
| Name: ReduceClearDown
|    
| Precodition: matrix exists
| Postcondition: a pivot element is made and the elements below
|                it are zeroed out.
|
| Parameters:
|       
|   IN: integer for Column and Row to operate on
|   Out: Nothing
|   
| Returns: 1 on success, 0 on failure
\****************************************************************/
int matrix::ReduceClearDown (int Column, int Row)
{
    if (MakePivot(Column, Row))
    {
        for (int i = Row + 1 ; i < Y ; i++)
        {
            if (A[Column][i])
            {
                ScaleRow(i, -1/A[Column][i]);
                AddRow (Row, i);
            }
        }
    } else return 0;
    return 1;
}

/****************************************************************
| Name: RowEchelonForm
|    
| Precodition: a matrix exists
| Postcondition: puts the matrix in row echelon form
|
| Parameters:
|       
|   IN: Nothing
|   Out: Nothing
|   
| Returns: Dimension of matrix
\****************************************************************/
int matrix::RowEchelonForm ()
{
    int Dimension = 0;
    for (int i = 0 ; i < X ; i++)
    {
        Dimension += ReduceClearDown(i, i);
    }
    if (!Dimension) Dimension++;
    return Dimension;
}

/****************************************************************
| Name: Write
|    
| Precodition: A matrix to save
| Postcondition: a matrix (with rounded elements) saved to a file
|
| Parameters:
|       
|   IN: Nothing
|   Out: Nothing
|   
| Returns: 1 on finishing the program
\****************************************************************/
int matrix::Write()
{
    ofstream OutData;
    cout << "Enter name of file "; /*designate file path 
                                        using string*/
    string UserInput;
    getline(cin, UserInput);
    OutData.open(UserInput.c_str());
    double FixedPrint; 
    for (int j = 0 ; j < Y ; j++)
    {
        for (int i = 0 ; i < X ; i++)
        {
            if (!(round(100 * A[i][j])/100)) 
                FixedPrint = 0; 
            else FixedPrint = round(100 * A[i][j])/100; 
            OutData << FixedPrint << ' ';
        } OutData << endl;
    } OutData << endl;
    OutData.close();
    return 1;
}

/****************************************************************
| Name: Solve
|    
| Precodition: a matrix exists
| Postcondition: the matrix is now an identity matrix,
|                it's constants are now known
|
| Parameters:
|       
|   IN: Nothing
|   Out: Nothing
|   
| Returns: 1 on completion of the function
\****************************************************************/
int matrix::Solve()
{
    RowEchelonForm();
    //solves triangle matrix
    for (int i = X - 1, j = Y - 2, n = 1 ; j >= 0 ; j--, n++) 
        for (int k = 1, h = n ; h > 0 ; k++, h--)
            A[i][j] -= A[i-k][j] * A[i][j+h];

    //changes matrix to identity
    for (int j = 0 ; j < Y ; j++)                            
        for (int i = 0 ; i < X-1 ; i++)
            A[i][j] = 0;
    for (int i = 0 ; i < X-1 ; i++)
        A[i][i] = 1;
    return 1;
}

const matrix operator +(const matrix &a, const matrix &b)
{
    if (a.X == b.X && a.Y == b.Y)
    {
        matrix OutMatrix(a.X,a.Y);

        for (int i = 0 ; i < a.X ; i++)
            for (int j = 0 ; j < a.Y ; j++)
                OutMatrix.A[i][j] = a.A[i][j] + b.A[i][j];

        return OutMatrix;
    }
    else
    {
        cout << "\nError: matrix addition size fault\n";
        exit(1);
    }
}

const matrix operator *(const matrix &a, const matrix &b)
{
    if (a.Y == b.X)
    {
        matrix OutMatrix(b.X, a.Y);            

        //clean new matrix
        for (int i = 0 ; i < b.X ; i++)        
            for (int j = 0 ; j < a.Y ; j++)
                OutMatrix.A[i][j] = 0;

        //multiply
        for (int i = 0 ; i < b.X ; i++)
            for (int j = 0 ; j < a.Y ; j++)
                for (int c = 0 ; c < b.Y ; c++)
                {
                    OutMatrix.A[i][j] += 
                        a.A[c][j] * b.A[i][c];
                }   

        return OutMatrix;
    }
    else
    {
        cout << "\nError: invalid multiplication\n";
        exit(1);
    }
}


/*================================================================
|| 
|| Object: com 
|| 
|| Purpose: a data type to approximate complex numbers
||      
|| Atributes: 
||      Real
||      Imaginary
|| Functions:
||      + - * operators (not members)
||
\*==============================================================*/
class com
{
public:
    com(double RealValue, double ImaginaryValue);
    com(const double &RealValue);
    com();
    
    double Real;
    double Imaginary;
};

const com operator +(const com &a, const com &b);
const com operator -(const com &a, const com &b);
const com operator *(const com &a, const com &b);

com::com(double RealValue, double ImaginaryValue)
{
    Real = RealValue;
    Imaginary = ImaginaryValue;
}

com::com(const double &RealValue)
{
    Real = RealValue;
    Imaginary = 0;
}

com::com()
{
    Real = 0;
    Imaginary = 0;
}

const com operator +(const com &a, const com &b)
{
    double finalReal = a.Real + b.Real;
    double finalImaginary = a.Imaginary + b.Imaginary;

    return com(finalReal, finalImaginary);
}

const com operator -(const com &a, const com &b)
{
    double finalReal = a.Real - b.Real;
    double finalImaginary = a.Imaginary - b.Imaginary;

    return com(finalReal, finalImaginary);
}

const com operator *(const com &a, const com &b)
{
    double finalReal = 
            a.Real * b.Real - a.Imaginary * b.Imaginary;
    double finalImaginary = a.Real * b.Imaginary 
            + a.Imaginary * b.Real;

    return com(finalReal, finalImaginary); 
}


/*================================================================
|| 
|| Object: rat 
|| 
|| Purpose: emulates the rational numbers
|| Atributes: 
||      Numerator
||      Denominator
|| Functions:
||      + - * / == != <= >= < > operators (non-members)
||      
||      toInt (non-member)
||      toFloat (non-member)
||
\*==============================================================*/


class rat
{
public:
    rat();
    rat(int theNum);
    rat(int theNum, int theDen);

    void p(); //print rational number

    int num; //numerator
    int den; //denotminator
};

const rat operator +(const rat &a, const rat &b);
const rat operator -(const rat &a, const rat &b);
const rat operator *(const rat &a, const rat &b);
const rat operator /(const rat &a, const rat &b);
inline bool operator==(const rat &a, const rat &b);
inline bool operator!=(const rat &a, const rat &b);
inline bool operator<=(const rat &a, const rat &b);
inline bool operator>=(const rat &a, const rat &b);
inline bool operator> (const rat &a, const rat &b);
inline bool operator< (const rat &a, const rat &b);

rat::rat(int theNum, int theDen)
{
    if (theDen)
    {
        num = theNum;
        den = theDen;
    }
    else 
    {
        cout << "\nError: denominator == 0\n";
        exit(1);
    }
}

rat::rat(int theNum)
{
    num = theNum;
    den = 1;
}

rat::rat()
{
    num = 0;
    den = 1;
}

const rat operator +(const rat &a, const rat &b)
{
    int finalNum = a.num * b.den + b.num * a.den;
    int finalDen = a.den * b.den;
    
    int divider = gcd(finalNum, finalDen);
    finalNum /= divider;
    finalDen /= divider;

    return rat(finalNum, finalDen);
}

const rat operator -(const rat &a, const rat &b)
{
    int finalNum = a.num * b.den - b.num * a.den;
    int finalDen = a.den * b.den;

    int divider = gcd(finalNum, finalDen);
    finalNum /= divider;
    finalDen /= divider;

    return rat(finalNum, finalDen);
}

const rat operator *(const rat &a, const rat &b)
{
    int finalNum = a.num * b.num;
    int finalDen = a.den * b.den;
    
    int divider = gcd(finalNum, finalDen);
    finalNum /= divider;
    finalDen /= divider;

    return rat(finalNum, finalDen);
}

const rat operator /(const rat &a, const rat &b)
{
    int finalNum = a.num * b.den;
    int finalDen = a.den * b.num;
    
    int divider = gcd(finalNum, finalDen);
    finalNum /= divider;
    finalDen /= divider;

    return rat(finalNum, finalDen);
}

inline bool operator==(const rat &a, const rat &b)
{
    if (a.num == b.num && a.den == b.den)
        return 1;
    else
        return 0;
}

inline bool operator!=(const rat &a, const rat &b)
{
    return !(a == b);
}

inline bool operator >(const rat &a, const rat &b)
{
    int A = a.num * b.den;
    int B = b.num * b.den;
    
    return (A > B);
}

inline bool operator <(const rat &a, const rat &b)
{
    int A = a.num * b.den;
    int B = b.num * b.den;
    
    return (A < B);
}

inline bool operator<=(const rat &a, const rat &b)
{
    return !(a > b);
}

inline bool operator>=(const rat &a, const rat &b)
{
    return !(a < b);
}

void rat::p()
{
    if (num == den)
        cout << 1;
    else if (num == 0)
        cout << 0;
    else if (den == 1)
        cout << num;
    else
        cout << num << "/" << den;
}

int toInt(rat a)
{
    return a.num/a.den;
}
float toFloat(rat a)
{
    return a.num/float(a.den);
}

  
/*================================================================
|| 
|| Object: ratMatrix 
|| 
|| Atributes: 
||      MAX (max size of ratMatrix)
||      A[][] (ratMatrix for manipulations)
||      Determinant[] (used to find the determinant)
|| Functions:
||      Randomize
||      Print
||      Scan
||      ScaleRow
||      SwitchRow
||      AddRow
||      MakePivot
||      ReduceClearDown
||      RowEchelonForm
||      Write
||      Solve
||
\*==============================================================*/

class ratMatrix
{
public:
    ratMatrix(int theX, int theY);
    void Randomize();
    void Print();
    int Scan();
    void ScaleRow (int Row, rat Scalar);
    void SwitchRow (int Row1, int Row2);
    void AddRow (int RowIn, int RowOut);
    int MakePivot (int Column, int Row);
    int ReduceClearDown (int Column, int Row);
    int RowEchelonForm();
    int Write();
    int Solve();

    rat Determinant[1000];
private:
    int Max; //declared in initializer
    rat A[1000][1000];  //col then row 
    int X;
    int Y;
};

ratMatrix::ratMatrix(int theX, int theY)
{
    Max = 1000;
    if (theX < Max && theY < Max)
    {
        X = theX;
        Y = theY;
    }
    else
    {
        cout << "\nError: adjust ratMatrix size\n";
        exit(1);
    }
}
/****************************************************************
| Name: Randomize
|    
| Precodition: a 2D array size double with a max size of 1000,
|              2 ints for size of array that user chooses, 
|              <time.h>
| Postcondition: a random array of intergers 1 through 9
|
| Parameters:
|       
|   IN: double array, int X, int Y
|   Out: same array with an X by Y section randomized
|   
| Returns: nothing
\****************************************************************/
void ratMatrix::Randomize()
{
    srand (time(NULL));
    for (int j = 0 ; j < Y ; j++)
    {
        for (int i = 0 ; i < X ; i++)
        {
            A[i][j].num = int(rand() % 10);
            A[i][j].den = 1;
        }
    }
}

/****************************************************************
| Name: Print
|    
| Precodition: A double 2D array
| Postcondition: The double 2D array is printed onto the screen
|
| Parameters:
|       
|   IN: double 2D array, 2 ints for the dimensions to print
|   Out: The same double 2D array
|   
| Returns: nothing
\****************************************************************/
void ratMatrix::Print()
{
    for (int j = 0 ; j < Y ; j++)
    {
        for (int i = 0 ; i < X ; i++)
        {
            A[i][j].p();
            cout << ' ';
        } cout << endl;
    } cout << endl;
}

/****************************************************************
| Name: Scan
|    
| Precodition: A file to pull a ratMatrix from, and a ratMatrix 
|              from 
|              mylib.cpp to print onto
| Postcondition: The ratMatrix passed to the program for use 
|
| Parameters:
|       
|   IN: double 2D array, int X, int Y
|   Out: same double 2D array
|   
| Returns: 1 on success
\****************************************************************/
int ratMatrix::Scan()
{
    fstream InData;
    cout << "Enter the name of the file you wish to scan "; 
    //designate file path using string
    string UserInput;
    getline(cin, UserInput);
    InData.open(UserInput.c_str());
    for (int j = 0 ; j < Y ; j++) 
        for (int i = 0 ; i < X ; i++)
        {
            InData >> A[i][j].num;
            A[i][j].den = 1;
        }
    InData.close();
    return 1;
}

/****************************************************************
| Name: ScaleRow
|    
| Precodition: a 2 by 2 ratMatrix
| Postcondition: 
|
| Parameters:
|       
|   IN: 
|   Out: 
|   
| Returns: 
\****************************************************************/
void ratMatrix::ScaleRow (int Row, rat Scalar)
{
    for (int i = 0 ; i < X ; i++)
    {
        A[i][Row] = A[i][Row] * Scalar;
    }
}

/****************************************************************
| Name: SwitchRow
|    
| Precodition: 
| Postcondition: 
|
| Parameters:
|       
|   IN: 
|   Out: 
|   
| Returns: 
\****************************************************************/
void ratMatrix::SwitchRow(int Row1, int Row2)
{
    rat Temp(1,1);
    for (int i = 0 ; i < X ; i++)
    {
        Temp = A[i][Row1];
        A[i][Row1] = A[i][Row2];
        A[i][Row2] = Temp;
    }
}

/****************************************************************
| Name: 
|    
| Precodition: 
| Postcondition: 
|
| Parameters:
|       
|   IN: 
|   Out: 
|   
| Returns: 
\****************************************************************/
void ratMatrix::AddRow (int RowIn, int RowOut)
{
    for (int i = 0 ; i < X ; i++)
    {
        A[i][RowOut] = A[i][RowOut] + A[i][RowIn];
    }
}

/****************************************************************
| Name: 
|    
| Precodition: 
| Postcondition: 
|
| Parameters:
|       
|   IN: 
|   Out: 
|   
| Returns: 
\****************************************************************/
int ratMatrix::MakePivot (int Column, int Row)
{
    rat one(1,1);
    rat zero(0,1);
    for (int i = Row + 1 ; i < Y ; i++)
        if (A[Column][Row] != zero)
        {
            Determinant[Column] = A[Column][Row]; //to get det(A) later
            ScaleRow(Row, one/A[Row][Column]);
            return 1;
        }
        else SwitchRow(Row, i);
        if (A[Column][Row] != zero) 
        {
            Determinant[Column] = A[Column][Row]; //to get det(A) later
            ScaleRow(Row, one/A[Row][Column]);
            return 1;
        }
        else return 0;
}

/****************************************************************
| Name: 
|    
| Precodition: 
| Postcondition: 
|
| Parameters:
|       
|   IN: 
|   Out: 
|   
| Returns: 
\***************************************************************/
int ratMatrix::ReduceClearDown (int Column, int Row)
{
    
    rat minusOne(-1,1); 
    rat zero(0,1);
    if (MakePivot(Column, Row))
    {
        for (int i = Row + 1 ; i < Y ; i++)
        {
            if (A[Column][i] != zero)
            {
                ScaleRow(i, minusOne/A[Column][i]);
                AddRow (Row, i);
            }
        }
    } else return 0;
    return 1;
}

/****************************************************************
| Name: RowEchelonForm
|    
| Precodition: 
| Postcondition: 
|
| Parameters:
|       
|   IN: 
|   Out: 
|   
| Returns: 
\****************************************************************/
int ratMatrix::RowEchelonForm ()
{
    int Dimension = 0;
    for (int i = 0 ; i < X ; i++)
    {
        Dimension += ReduceClearDown(i, i);
    }
    if (!Dimension) Dimension++; 
    return Dimension;
}

/****************************************************************
| Name: Write
|    
| Precodition: A ratMatrix to save
| Postcondition: a ratMatrix saved to a file
|
| Parameters:
|       
|   IN: Nothing
|   Out: Nothing
|   
| Returns: 1 on finishing the program
\****************************************************************/
int ratMatrix::Write()
{
    ofstream OutData;
    cout << "Enter name of file "; /*designate file path 
                                        using string*/
    string UserInput;
    getline(cin, UserInput);
    OutData.open(UserInput.c_str());
    double FixedPrint; 
    for (int j = 0 ; j < Y ; j++)
    {
        for (int i = 0 ; i < X ; i++)
        {
            A[i][j].p();
            cout << ' ';
        } OutData << endl;
    } OutData << endl;
    OutData.close();
    return 1;
}

/****************************************************************
| Name: solve
|    
| Precodition: matrix is triangular
| Postcondition: matrix is identity
|
\****************************************************************/
int ratMatrix::Solve()
{
    rat zero(0,1);
    rat one(1,1);
    for (int i = X - 1, j = Y - 2, n = 1 ; j >= 0 ; j--, n++) 
    //solves triangle ratMatrix
        for (int k = 1, h = n ; h > 0 ; k++, h--)
            A[i][j] = A[i][j] - (A[i-k][j] * A[i][j+h]);
    for (int j = 0 ; j < Y ; j++)                            
    //changes ratMatrix to identity
        for (int i = 0 ; i < X-1 ; i++)
            A[i][j] = zero;
    for (int i = 0 ; i < X-1 ; i++)
        A[i][i] = one;
    return 1;
}

/****************************************************************
| Name: expMod
|    
| Precodition: nothing
| Postcondition: nothing
|
| Parameters:
|       
|   IN: integer for base, exponent, and mod
|   Out: nothing
|   
| Returns: integer a for b^e ≡ a (mod n)
\****************************************************************/
unsigned long int expMod(unsigned long int a, unsigned long int n, unsigned long int m) //faster, exponential time
{
    long unsigned int x = a;
    long unsigned int y = (((n >> 0) & 1) == 1)?a:1;
    long unsigned int k = 4096; //for now
    for (int i = 1 ; i <= k ; i++)
    {
        x = (x*x) % m;
        if (((n >> i) & 1) == 1)
            y = (y == 1)?x:((x*y)%m);
    }
    return y;
}
/*
unsigned long int expMod(unsigned long int base, unsigned long int exponent, unsigned long int mod) 
{
    if (mod == 1)
        return 0;
    unsigned long int c = 1;
    for (int i = 1 ; i <= exponent ; i++)
        c = (c * base) % mod;

    return c;
}
*/

/****************************************************************
| Name: phi
|    
| Precodition: exists breakIntoPrimes, intLog, rat
| Postcondition: phi computed
|
| Parameters:
|       
|   IN: an integer 'number'
|   Out: Nothing
|   
| Returns: an integer representing the number of positive 
|          integers not exceeding 'number' that are relatively
|          prime to 'number'
\****************************************************************/
/* //fast but does not work for large numbers, odd...
int phi(int number) 
{
    int maxPrimes = number/2; //what is max primes in number?
    if (maxPrimes < 10)       //
       maxPrimes = 10; 
    int *primes = new int[maxPrimes];

    breakIntoPrimes(number, primes, maxPrimes);

    //type rat (rational) to maintain accuracy
    rat one(1);
    rat inverseP(1);
    rat lead(number);
    for (int i = 0 ; primes[i] && i < maxPrimes ; i++)
    {   
        if (primes[i] != primes[i+1])
        {
            inverseP.den = primes[i];
            lead = lead * (one - inverseP); //using theorem 7.3
        }
    }

    delete [] primes;

    return toInt(lead);
}
*/
int phi(int n) //slower for large numbers
{
    if (n == 1) return 1;

    unsigned int Sum = 0;
    for (int i = 1 ; i < n ; i++)
        if (gcd(i,n) == 1)
            Sum += 1;
    return Sum;
}
/*
long int phi(long int p, long int q) //for RSA encryption alg
{
    return (p-1)*(q-1);
}
*/
/****************************************************************
| Name: tau
|    
| Precodition: argument is an int, negative int also calculated
| Postcondition: No change in state
|
| Parameters:
|       
|   IN: an integer called n
|   Out: Nothing
|   
| Returns: The number of positive divisors of n
\****************************************************************/
int tau(int n)
{   
    int toReturn = 0;

    for (int i = 1 ; i <= n ; i++)
        if (n % i == 0)
            toReturn++;

    return toReturn;
}
/****************************************************************
| Name: sigma
|    
| Precodition: argument is an int, negative int also calulated
| Postcondition: No change in state
|
| Parameters:
|       
|   IN: an integer called n
|   Out: Nothing
|   
| Returns: The sum of the number of positive divisors of n
\****************************************************************/
int sigma(int n)
{
    int toReturn = 0;

    for (int i = 1 ; i <= n ; i++)
        if (n % i == 0)
            toReturn += i;

    return toReturn;
}

/****************************************************************
| Name: phiInverseCap
|    
| Precodition: nothing
| Postcondition: nothing
|
| Parameters:
|       
|   IN: int n of phi^-1(n)
|   Out: nothing
|   
| Returns: largest possible element of phi^-1(n)
\****************************************************************/
int phiInverseCap(int n)
{
    /* get largest prime */
    int a = 1;
    int largestPrime = 2;
    while (a <= n)
    {
        if (isPrime(largestPrime))
            a *= largestPrime-1;
        largestPrime++;
    }
    --largestPrime;

    /* compute upper bound of phi^-1(n) */
    a = 1;
    for (int i = 2 ; i <= largestPrime ; i++)
        if (isPrime(i))
            a *= i;

    return a;
}

/****************************************************************
| Name: phiInverse
|    
| Precodition: using <iostream>, <stdlib.h>
| Postcondition: nothing
|
| Parameters:
|       
|   IN: int image of phi function
|   Out: int preimage of phi function (also max size of array)
|   
| Returns: nothing
\****************************************************************/
void phiInverse(int k, int arry[], int MAX)
{
    /* clean array */
    for (int i = 0 ; i < MAX ; i++) 
        arry[i] = 0;
    
    /* get bounds */
    int phiInMax = phiInverseCap(k); 
    int phiInMin = k + 1;

    /* compute set of phi^-1(n) */
    int j = 0;
    for (int i = phiInMin ; i <= phiInMax ; i++)
        if (phi(i) == k)               
        {                             
            arry[j++] = i;           
                                    
            if (j == MAX)
            {
                cout << "\nError: phiInverse, arry[] too small\n";
                exit(1);
            }
        }
}
/****************************************************************
| Name: pseudoPrime
|
| description: checks if a number is pseudoprime
|    
| Precodition:  nothing 
| Postcondition: nothing
|
| Parameters:
|       
|   IN: a number n and its base
|   Out: nothing
|   
| Returns: pseudoprime if it is one or 0 if it is not
\****************************************************************/
int pseudoPrime(int n, int base)
{
    if (expMod(base, n-1, n) != 1)
        return 0;
    return n;
}

/****************************************************************
| Name: power
|
| Description: returns integer power a^b
|    
| Precodition: nothing
| Postcondition: nothing
|
| Parameters:
|       
|   IN: numbers a and b
|   Out: nothing
|   
| Returns: a^b
\****************************************************************/
int power(int a, int b)
{
    if (b == 0)
        return 1;
    int tempA = a;
    for (int i = 1 ; i < b ; i++)
        a *= tempA;
    return a;
}

/****************************************************************
| Name: Carmichael
|
| Description: checks for Carmichael numbers
|    
| Precodition: nothing
| Postcondition: nothing
|
| Parameters:
|       
|   IN: a number n
|   Out: nothing
|   
| Returns: that number if it is a Carmichael, 0 otherwise
\****************************************************************/
int Carmichael(int n)
{
/*
n={n | composite ∧ ∀b b^(n-1)≡ 1(mod n) ∧ 1 < b < n ∧ gcd(b,n)=1 }

0={n | prime V ∃b b^(n-1) !≡ 1(mod n) ∧ 1 < b < n ∧ gcd(b,n)=1 }
*/

    if ((isPrime(n)))
        return 0;
    for (int b = 2 ; b < n ; b++)
        if (gcd(b,n) == 1)
            if (expMod(b, n-1, n) != 1)
                return 0;
    
    return n;
}

/****************************************************************
| Name: mu (mobius number theoretic function)
|    
| Precodition: there exists function breakIntoPrimes 
| Postcondition: nothing
|
| Parameters:
|       
|   IN: an integer n
|   Out: nothing
|   
| Returns: the computation of the Mobius mu function
\****************************************************************/
int mu(int n)
{
    if (n == 1)
        return 1;
    
    int maxPrimes = n; 
    //what is the smallest number of primes of n

    int* primearry = new int[maxPrimes];

    for (int i = 0 ; i < maxPrimes ; i++)
        primearry[i] = 0;

    for (int i = 0 ; primearry[i] ; i++)
        for (int j = 0 ; primearry[j] ; j++)
            if (primearry[i] == primearry[j] && i != j)
                return 0;

    int r = 0;
    for (int i = 0 ; i < maxPrimes ; i++)
        if (primearry[i])
            r++;
    if (r % 2 == 0)
        return 1;
    else
        return -1;

}

/*****************************************************************
| Name: removePrime
|    
| Precodition: an int array with a known length
| Postcondition: all multiples of a prime removed from array
|
| Parameters:
|       
|   IN: an integer for prime and array length, an int array
|   Out: the same int array
|   
| Returns: nothing
\****************************************************************/
void removePrime(int prime, int a[], int arrayLength)
{
    for (int i = 0 ; i <= arrayLength ; i++)
        if (a[i] % prime == 0 && a[i] != prime)
            a[i] = 0;
}

/****************************************************************
| Name: printTrueArray
|    
| Precodition: an int array of known length
| Postcondition: the int array is printed on the screen sans
|                all of the zeros
|
| Parameters:
|       
|   IN: int array and its length
|   Out: the same array
|   
| Returns: nothing
\****************************************************************/
void printTrueArray(int a[], int arrayLength)
{
    for (int i = 2 ; i < arrayLength ; i++)
        if (a[i] != 0)
            cout << a[i] << ' ';
}

/****************************************************************
| Name: seive 
|    
| Precodition: nothing
| Postcondition: nothing
|
| Parameters:
|       
|   IN: array and its length
|   Out: array of prime numbers
|   
| Returns: nothing
\****************************************************************/
void seive(int array[], int MaxPrimes)
{
    for (int i = 0 ; i < MaxPrimes ; i++)
        array[i] = 0;

    int* TempArray = new int[MaxPrimes];

    for (int i = 0 ; i <= MaxPrimes ; i++)
        TempArray[i] = i;

   
    /* part that uses seive */
    int topPrime = int(ceil(pow(MaxPrimes, 0.5)));
    
    for (int i = 0 ; i < MaxPrimes ; i++)
        for (int j = 2 ; j <= topPrime ; j++)
            if (isPrime(j))
                removePrime(j, TempArray, MaxPrimes);

    TempArray[1] = 0; //get rid of 1
    int j = 0;
    for (int i = 0 ; i < MaxPrimes ; i++)
    {
        if (TempArray[i])
            array[j++] = TempArray[i];
    }

    delete [] TempArray;
}

/****************************************************************
| Name: lowerPrime
|    
| Precodition: nothing
| Postcondition: nothing
|
| Parameters:
|       
|   IN: a number n
|   Out: nothing
|   
| Returns: the prime number under n
\****************************************************************/
int lowerPrime(int n)
{
    while (n > 0)
    {
        if (isPrime(n))
            return n;
        else n--;
    }
}


/****************************************************************
| Name: nextPrime
|    
| Precodition: nothing
| Postcondition: nothing
|
| Parameters:
|       
|   IN: positive integer k
|   Out: nothing
|   
| Returns: the closest prime after n
\****************************************************************/
int nextPrime(int n) 
{
    while (n > 0)
    {
        n++;
        if (isPrime(n))
            return n;
    }
}

/****************************************************************
| Name: higherPrime
|    
| Precodition: nothing
| Postcondition: nothing
|
| Parameters:
|       
|   IN: an integer n
|   Out: nothing
|   
| Returns: n if it is a prime, else the next prime
\****************************************************************/
int higherPrime(int n) 
{
    while (n > 0)
    {
        if (isPrime(n))
            return n;
        else n++;
    }
}

/****************************************************************
| Name: primeStep
|
| Description: designed to test a boundary conjecture
|    
| Precodition: nothing
| Postcondition: nothing
|
| Parameters:
|       
|   IN:  a number n > 1
|   Out: nothing
|   
| Returns: lowerPrime(n)-1
\****************************************************************/
int primeStep(int n)
{
    if (n < 2)
    {
        cout << "\nerror: bad num in prime step\n";
        exit(1);
    }

    return lowerPrime(n)-1;
}

/****************************************************************
| Name: nextPhi
|    
| Precodition: nothing
| Postcondition: nothing
|
| Parameters:
|       
|   IN: positive integer k
|   Out: nothing
|   
| Returns: an n of phi(n) bigger than k
\****************************************************************/
int nextPhi(int k)
{
    int n = k; 

    while (k > phi(n))
        n++;

    return n;
}



/****************************************************************
| Name: gcdExtended
|    
| Precodition: nothing
| Postcondition: nothing
|
| Parameters:
|       
|   IN: integers a,b,x,y such that gcd(a,b) = ax + by = c
|   Out: integers x and y
|   
| Returns: integer c
\****************************************************************/
unsigned long int gcdExtended(unsigned long int a, unsigned long int b, unsigned long int *x, unsigned long int *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
 
    unsigned long int x1, y1; // To store results of recursive call
    unsigned long int gcd = gcdExtended(b%a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}

/****************************************************************
| Name: modInv
|    
| Precodition: nothing
| Postcondition: nothing
|
| Parameters:
|       
|   IN: u and v for equation u^-1(mod v)
|   Out: nothing
|   
| Returns: integer equal to u^-1(mod v)
\****************************************************************/
unsigned long int modInv(unsigned long int a, unsigned long int m)
{
    unsigned long int x, y;
    unsigned long int g = gcdExtended(a, m, &x, &y);
    if (g != 1)
        cout << "Inverse doesn't exist";
    else
    {
        // m is added to handle negative x
        unsigned long int res = (x%m + m) % m;
        return res;
        cout << "Modular multiplicative inverse is " << res;
    }
}

/****************************************************************
| Name: modinv //u^-1(mod v)
|    
| Precodition: nothing
| Postcondition: nothing
|
| Parameters:
|       
|   IN: u and v
|   Out: nothing
|   
| Returns: u^-1(mod v)
\****************************************************************/
unsigned long int modinv(unsigned long int u, unsigned long int v) //self contained version, may also be faster
{
    unsigned long int inv, u1, u3, v1, v3, t1, t3, q;
    int iter;
    /* Step X1. Initialise */
    u1 = 1;
    u3 = u;
    v1 = 0;
    v3 = v;
    /* Remember odd/even iterations */
    iter = 1;
    /* Step X2. Loop while v3 != 0 */
    while (v3 != 0)
    {
        /* Step X3. Divide and "Subtract" */
        q = u3 / v3;
        t3 = u3 % v3;
        t1 = u1 + q * v1;
        /* Swap */
        u1 = v1; v1 = t1; u3 = v3; v3 = t3;
        iter = -iter;
    }
    /* Make sure u3 = gcd(u,v) == 1 */
    if (u3 != 1)
        return 0;   /* Error: No inverse exists */
    /* Ensure a positive result */
    if (iter < 0)
        inv = v - u1;
    else
        inv = u1;
    return inv;
}

/****************************************************************
| Name: encrypt
|    
| Precodition: nothing
| Postcondition: nothing
|
| Parameters:
|       
|   IN: integers M, n, k of the equation M^k ≡ r (mod n)
|   Out: nothing
|   
| Returns: r, a number with an RSA encryption on it
\****************************************************************/
unsigned long int encrypt(unsigned long int M, unsigned long int n, unsigned long int k)
{
    return expMod(M, k, n);
}

/****************************************************************
| Name: decrypt
|    
| Precodition: nothing
| Postcondition: nothing
|
| Parameters:
|       
|   IN: integer r, p, q, j of the equation r^j ≡ M (mod p*q)
|   Out: nothing
|   
| Returns: M, a number that has had the RSA encryption removed
\****************************************************************/
unsigned long int decrypt(unsigned long int r, unsigned long int p, unsigned long int q, unsigned long int j)
{
    return expMod(r, j, (p*q));
}


/****************************************************************
| Name: flip String
|    
| Precodition: nothing
| Postcondition: nothing
|
| Parameters:
|       
|   IN: string and a start and end point
|   Out: string
|   
| Returns: nothing
\****************************************************************/
void flipString(int a[], int start, int end)
{ 
    int* temp = new int[end-start+1];

    int tempStart = start;
    int tempEnd = end;

    while (tempEnd >= start)
    {
        temp[tempEnd] = a[tempStart];

        tempEnd--;
        tempStart++;
    }

    while (start <= end)
    {
        a[start] = temp[start];

        start++;
    }
}
#ifndef howboutno
/*================================================================
|| 
|| Object: bigInt 
|| 
|| Purpose: a data type to calculate large integers
||      
|| Atributes: 
||
|| Functions:
||      + 
||
\*==============================================================*/
class bigInt
{ 
    public:
        //store of size __ call it __
        bigInt(); 
        bigInt(unsigned int twoToN);

        bigInt(const bigInt& obj);

        ~bigInt(); 

        /* input number */
        /* all in binary for now */
        void value(unsigned long int theNum); //from program
        void value(string fileName); // ./for file, else num
        void value(); //from cin 

        /* output number */
        void print(); //default base 2
        

        /* speed up */
        int confirmLength(); //faster computation
        void resize(); //less memory use

        friend const bigInt operator +(const bigInt &a,
                                       const bigInt &b);
        friend const bigInt operator -(const bigInt &a,
                                       const bigInt &d);
        friend const bigInt operator *(const bigInt &a, 
                                       const bigInt &b);
        friend const bigInt operator /(const bigInt &a, 
                                       const bigInt &b);
        friend const bigInt operator %(const bigInt &a, 
                                       const bigInt &mod);
        friend const int operator %(const bigInt &a, 
                                       const int &mod);
        friend bool operator >=(const bigInt &a,
                                       const bigInt &b);
        friend bool operator <=(const bigInt &a,
                                       const bigInt &b);
        friend bool operator ==(const bigInt &a,
                                       const bigInt &b);
        friend bool operator !=(const bigInt &a,
                                       const bigInt &b);
        friend bool operator <(const bigInt &a,
                                       const bigInt &b);
        friend bool operator >(const bigInt &a,
                                       const bigInt &b);
        friend bool operator &&(const bigInt &a,
                                       const int &b);

        bigInt& operator =(const bigInt& rhs); 

        

        void complement();

        void setEqualTo(unsigned long int theNum);

        void bitShift(int n);

        char* ascii();

        char* stringNum(); //bugged
        
        unsigned long int ten(); //convert to long unsigned int

        friend void flipString(bool a[], int start, int end);

        friend void changeToBase(int x, int base, 
                                 int string[], int Max);
        friend void changeToBase(bigInt x, int base, 
                                 char string[], int Max);
        
    private:
        int* num; //the number, bool is better
        int length; //the length of storage
        int max; //4096
};



bigInt::bigInt() 
{
    max = 4096;
    num = new bool[max];
    length = max;

    for (int i = 0 ; i < max ; i++)
        num[i] = 0;
}
bigInt::bigInt(unsigned int twoToN)
{
    max = 4096;
  
    if (twoToN <= max)
        length = twoToN;
    else
    {
        cout << "\nerror: change size limit of bigInt\n";
        exit(1);
    } 

    num = new bool[length];

    for (int i = 0 ; i < length ; i++)
        num[i] = 0;
}

bigInt::bigInt(const bigInt& rhs)
{
//  cout << "\ncopy constructor call\n";

    max = rhs.max;
    length = rhs.length;
    num = new bool[length];
    for (int i = 0 ; i < length ; i++)
        num[i] = rhs.num[i];
}

bigInt::~bigInt()
{
//  cout << "\ndeconstructor running\n";
//  cout << "times called: " << timesCalled() << endl;
    
//  delete [] num;
}

bigInt& bigInt::operator =(const bigInt& rhs)
{
    if (this == &rhs)
        return *this;
    

    length = rhs.length;
    max = rhs.max;
    for (int i = 0 ; i < max ; i++)
        num[i] = rhs.num[i];
        
    return *this;
}

//good for smaller values
void bigInt::value(unsigned long int theNum)
{
    max = 4096;
    num = new int[max];
    length = max;

    for (int i = 0 ; i < max ; i++)
        num[i] = 0;

    if (theNum == 1) //common enough to get its own bypass
        num[0] = 1;

    if (theNum == 0)
        num[0] = 0;
        
    //convert base 10 to base 2 array
    changeToBase(theNum, 2, num, 64); //unsigned long int is 2^64

}
void bigInt::value(string fileName)
{
    fstream inData;
    inData.open(fileName.c_str());
    char userInput;
    int userLength = 0;
    while (inData >> userInput)
    {
        if (userInput == '1' || userInput == '0')
        {
            num[userLength] = bool(userInput - '0');
            userLength++;
        }
        else 
            break;
        if (userLength > max)
            break;
    } 

    if (userLength > 1)
        flipString(num, 0, userLength-1);
    if (userLength == 0)
    {
        cout << "\nerror: did not read a num\n";
        exit(1);
    }
    
    inData.close();
}
void bigInt::value()
{
    char userInput;
    int userLength = 0;
    do
    {
        userInput = cin.get();
        if (userInput == '1' || userInput == '0')
        {
            num[userLength] = (userInput - '0');
            userLength++;
        }
        if (userLength > 4096)
            break;
    } while (userInput == '1' || userInput == '0');
    
    
    if (userLength > 1)
        flipString(num, 0, userLength-1);
    if (userLength == 0)
    {
        cout << "\nerror: did not read a num\n";
        exit(1);
    }
}



//save on computation
int bigInt::confirmLength()
{
    int index = max-1;

    while (1)
    {
        if (index == 0) break;
        if (num[index] == 1) break;
        index--;
    }
    length = index + 1; 

    return length;
}
//save on memory
void bigInt::resize()
{
    confirmLength();
    bool* temp = new bool[max];

    for (int i = 0 ; i < length ; i++)
        temp[i] = num[i];

    delete [] num;

    num = new bool[length];
    
    for (int i = 0 ; i < length ; i++)
        num[i] = temp[i];

    delete [] temp;
}


void bigInt::print()
{
    confirmLength();
    for (int i = length-1 ; i >= 0 ; i--)
        cout << num[i];

    cout << endl;
    length = max;
}

void bigInt::setEqualTo(unsigned long int theNum)
{
    for (int i = 0 ; i < length ; i++)
        num[i] = 0;

    int lengthOr64 = (length > 64)?64:length;

    changeToBase(theNum, 2, num, lengthOr64); //unsigned long int is 2^64
}
    

const bigInt operator +(const bigInt &a, const bigInt &b)
{
    bigInt c;

    int shortest = a.max;
    /* save on computaion */
    //int shortest = (a.length > b.length)?b.length:a.length;

    int carry = 0;
    for (int i = 0 ; i < shortest ; i++)
    {
        c.num[i] = (a.num[i] + b.num[i] + carry) % 2;
        if ((a.num[i]+b.num[i]+carry) < 2)
            carry = 0;
        else
            carry = 1;
    }
            
    return c;
}

const bigInt operator -(const bigInt &a, const bigInt &b)
{
    bigInt tempA;
    tempA = a;
    tempA.confirmLength();

    bigInt tempB;
    tempB = b;
    tempB.length = tempA.length;
    tempB.complement();

    tempA = tempA + tempB;

    bigInt one;
    one.value(1);

    tempA = tempA + one;
    
    
    tempA.num[tempA.confirmLength()-1] = 0; //take off last bit

    tempA.length = tempA.max;

    return tempA;
    //what if a > b and b - a?
}

void bigInt::complement()
{
    for (int i = 0 ; i < length ; i++)
        num[i] = num[i] ^ 1;
}
void bigInt::bitShift(int n)
{
    if (n > 0)
    {
        for (int i = length-1 ; i >= 0 ; i--)
            if (1 + n <= max-1)
                num[i+n] = num[i];
        for (int i = 0 ; i < n ; i++)
            num[i] = 0;
    }
    if (n < 0)
    {
        for (int i = 0 ; i < length ; i++)
            if (i+n >= 0)
                num[i+n] = num[i];
        for (int i = length-1 ; i >= max-1-n ; i--)
            num[i] = 0;
    }
}
    

const bigInt operator *(const bigInt &a, const bigInt &b)
{
    bigInt one;
    one.value(1);

    bigInt temp;
    temp = a;

    if (b.num[0] == 1) temp = temp + one;
    int i = 1;
    while (1)
    {
        if (b.num[i] == 1)
            temp.bitShift(i);
        i++;
        if (i == a.max)
            break;
    }

    return temp;
}


const bigInt operator /(const bigInt &a, const bigInt &b)
{
    bigInt one;
    one.value(1);

    bigInt temp;
    temp = a;

    if (b.num[0] == 1) temp = temp - one;
    int i = 1;
    while (1)
    {
        if (b.num[i] == 1)
            temp.bitShift(-i);
        i++;
        if (i == a.max)
            break;
    }

    return temp;
}


const bigInt operator %(const bigInt &a, const bigInt &mod)
{
    bigInt c;
    c = a;

    bigInt one; one.value(1);
    bigInt zero; zero.value(0);

    if ((mod == one) || (mod == zero))
        return zero;

    while (c >= mod)
    {
        c = c - mod; 
    }

    return c;
}
const int operator %(const bigInt &a, const int &mod)
{
    bigInt c;
    c = a;

    bigInt mods;
    mods.value(mod);

    bigInt one; one.value(1);
    bigInt zero; zero.value(0);

    if ((mods == one) || (mods == zero))
        return 0;

    while (c >= mods)
    {
        c = c - mods; 
    }

    return c.ten();
}
bool operator ==(const bigInt &a, const bigInt &b)
{
    if (a.length != b.length)
        return 0;
    
    int i = a.length-1;
    while (1)
    {
        if (a.num[i] != b.num[i])
            return 0;
        if (i == 0)
            break;
        i--;
    } 

    return 1;
}

bool operator !=(const bigInt &a, const bigInt &b)
{
    return !(a == b);
}

bool operator >(const bigInt &a, const bigInt &b)
{
    if (a.length > b.length)
        return 1;

    if (a.length < b.length)
        return 0;

    int i = a.length;
    while (1)
    {
        if (a.num[i] == b.num[i])
            i--;
        else
            if (a.num[i] > b.num[i])
                return 1;
            else
                return 0;
        if (i <= 0)
            return 0;
    }
}


bool operator <=(const bigInt &a, const bigInt &b)
{
    return !(a > b);
}

bool operator <(const bigInt &a, const bigInt &b)
{
    if (a.length < b.length)
        return 1;

    if (a.length > b.length)
        return 0;

    int i = a.length;
    while (1)
    {
        if (a.num[i] == b.num[i])
            i--;
        else
            if (a.num[i] < b.num[i])
                return 1;
            else
                return 0;
        if (i <= 0)
            return 0;
    }

}

bool operator >=(const bigInt &a, const bigInt &b)
{
    return !(a < b);
}


char* bigInt::ascii()
{
    bigInt temp;

    for (int i = 0 ; i < max ; i++)
        temp.num[i] = num[i];

    char* toReturn = new char[max];

    changeToBase(temp, 256, toReturn, max);

    

    return toReturn;
}


char* bigInt::stringNum()
{
    bigInt temp;

    for (int i = 0 ; i < max ; i++)
        temp.num[i] = num[i];

    char* toReturn = new char[max];

    changeToBase(temp, 10, toReturn, max);

    for (int i = 0 ; i < max ; i++)
        toReturn[i] += '0';

    return toReturn;
}


bool operator &&(const bigInt &a, const int &b)
{
    bigInt zero;
    zero.value(0);
    int positiveLeft;
    if (a > zero)
        positiveLeft = 1;
    if (positiveLeft && (b != 0))
        return 1;
    else
        return 0;
}
        
void changeToBase(bigInt x, int base, char string[], int Max)
{
    for (int i = 0 ; x && i < Max ; i++)
    {
        string[i] = x % base;
        x = x/base;
    }
}

unsigned long int expt(unsigned long int a, unsigned long int b)
{
    unsigned long int c = 1;
    for (int i = 1 ; i <= b; i++)
        c = (c * a); 
    return c;
}


unsigned long int bigInt::ten()
{
    unsigned long int toReturn = 0;
    if (num[0] == 1)
        toReturn = 1;
    int maxLL = 64;
    for (int i = 1 ; i < maxLL ; i++)
    {
        toReturn += num[i] * expt(2, i);
    }
    return toReturn;
}
#endif

/****************************************************************
| Name: lambda
|
| Description: lambda from number theory
|    
| Precodition: nothing
| Postcondition: nothing
|
| Parameters:
|       
|   IN: integer n
|   Out: nothing
|   
| Returns: lambda(n)
\****************************************************************/
int lambda(int n)
{
    if (n == 1)
        return 1;
    
    
    int maxPrimes = n; 
    //what is the smallest number of primes of n

    int* primearry = new int[maxPrimes];

    for (int i = 0 ; i < maxPrimes ; i++)
        primearry[i] = 0;

    breakIntoPrimes(n, primearry, maxPrimes);

    int Sum = 0;
    for (int i = 0 ; primearry[i] ; i++)
        Sum++;

    return Sum;
    
}


/****************************************************************
| Name: len
|
| description: gets length of string
\****************************************************************/
int len(char* input)
{
    int i = 0;
    while (input[i++] != '\0');

    return i;
}

/****************************************************************
| Name: realHp 
|
| description: actual hp from bethesta games
\****************************************************************/
double realHp(double DR, double hp)
{
    return (hp * 100)/(100 - DR);
}

struct int2
{
    int a;
    int b;
};

/******************************************************************
| parseDice
|
| needs mainlib.cpp
\*****************************************************************/
int2 parseDice (char* argument)
{
    int2 dice; dice.a = 0; dice.b = 0;

    /* copy over before d */
    char* numDice = new char[10]; //10 char is enough
    int i = 0;
    while (argument[i] != 'd')
    {
        numDice[i] = argument[i];
        if (i > 10)
            return dice;
        i++;
    }
    numDice[i+1] = '\0';
    dice.a = stringToInt(numDice);
    
    /* copy over after d */
    i += 1; //skip over d
    int j = 0; //new strt for sideDice
    char* sideDice = new char[10];
    while (argument[i] != '\0')
    {
        sideDice[j] = argument[i];
        if (i > 10)
            return dice;
        i++;
        j++;
    }
    dice.b = stringToInt(sideDice);

    /* return dice */
//    delete [] sideDice;
//    delete [] numDice;
    return dice;
}
    

/******************************************************************
| diceRoll
|
| needs time.h, stdlib.h. 
\*****************************************************************/
int sumDiceRoll(int numberOfDie, int sides)
{
    srand (time(NULL));

    int sum = 0;
    for (int i = 0 ; i < numberOfDie ; i++)
        sum += rand() % sides + 1;

    return sum;
}

/******************************************************************
| base 10
|
| assumes NULL terminated c string
\*****************************************************************/
int base10(char* string, int base)
{
    // make token space
    int tokens = len(string);
    int** token = new int*[tokens];
    for (int i = 0 ; i < tokens ; i++)
        token[i] = new int[int(log10(base))];

    // clean token space
    for (int i = 0 ; i < tokens ; i++)
        for (int j = 0 ; j < int(log10(base))+1 ; j++)
            token[i][j] = 0;

    for (int i = 0 ; string[0] ; i++)
    {
        
    }
}
        

