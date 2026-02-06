// Input :  4
// Output : 1*2*3*4 = 24

#include<iostream>
using namespace std;

int Factorial(int iNo)
{
    static int iFact = 1;

    if(iNo >= 1)
    {
        iFact = iFact * iNo;
        Factorial(--iNo);       // pre decerement
    }

    return iFact;
}

int main()
{
    int iRet = 0;
    iRet = Factorial(4);
    cout << iRet;
    
    return 0;
}