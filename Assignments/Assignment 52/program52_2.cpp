// 2. Write a generic program to find largest number in three numbers

#include<iostream>
using namespace std;

template<class T>
T Max(T No1, T No2, T No3)
{
    if(No1 > No2 && No1 > No3)
    {
        return No1;
    }
    else if(No2 > No3 && No2 > No1)
    {
        return No2;
    }
    else
    {
        return No3;
    }
}

int main()
{
    int iRet = 0;

    iRet = Max(11,21,33);

    cout << iRet;
    
    return 0;
}