// 5. write a program to find maximum of four values

#include<iostream>
using namespace std;

template<class T>
T Max(T a, T b, T c, T d)
{
    if(a > b && a > c && a > d)
    {
        return a;
    }
    else if(b > a && b > c && b > d)
    {
        return b;
    }
    else if(c > a && c > b && c > d)
    {
        return c;
    }
    else
    {
        return d;
    }
}

int main()
{
    int iRet = 0;

    iRet = Max(1,5,2,3);

    cout << iRet;
    return 0;
}