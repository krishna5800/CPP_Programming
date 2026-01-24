// 3. write a program to perform Division of two numbers

#include<iostream>
using namespace std;

template<class T>
T Div(T no1, T no2)
{
    return no1/no2;
}

int main()
{
    int iRet = Div(20, 10);
    cout << "Division is : " << iRet << "\n";

    float fRet = Div(20.5f, 10.0f);
    cout << "Division is : " << fRet << "\n";

    return 0;
}