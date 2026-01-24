// 2. write a program to perform substraction of two numbers

#include<iostream>
using namespace std;

template<class T>
T Sub(T no1, T no2)
{
    return no1-no2;
}

int main()
{
    int iRet = Sub(20, 10);
    cout << "Substraction is : " << iRet << "\n";

    float fRet = Sub(20.5f, 10.5f);
    cout << "Substraction is : " << fRet << "\n";

    return 0;
}