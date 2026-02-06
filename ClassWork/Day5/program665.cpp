// Input :  4
// Output : 1*2*3*4 = 24

#include<iostream>
using namespace std;

int iFact = 1;

void Factorial(int iNo)
{
    if(iNo >= 1)
    {
        iFact = iFact * iNo;
        Factorial(--iNo);  
    }
}

int main()
{
    Factorial(4);
    cout << iFact;
    
    return 0;
}