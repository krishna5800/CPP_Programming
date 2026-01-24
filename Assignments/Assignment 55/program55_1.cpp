// 1. write a program to perform addition of two numbers

#include<iostream>
using namespace std;

template<class T>
T Add(T no1, T no2)
{
    return no1+no2;
}

int main()
{
    int iRet = Add(10,20);
    cout << "Addition is : " << iRet << "\n";

    float fRet = Add(10.5f, 20.5f);
    cout << "Addition is : " << fRet << "\n";

    return 0;
}