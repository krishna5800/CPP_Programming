// 1. Write a generic program to multiply two numbers

#include<iostream>
using namespace std;

template<class T>
T Multiply(T No1, T No2)
{
    T Ans;
    Ans = No1*No2;
    return Ans;
}

int main()
{
    int iRet = 0;
    iRet = Multiply(11,10);
    cout << "Multiplication is : " << iRet << "\n";

    float fRet = 0;
    fRet = Multiply(11.55,10.55);
    cout << "Multiplication is : " <<  fRet << "\n";

    return 0;
}