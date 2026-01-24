// 1. write a generic program to search a value in an array 

#include<iostream>
using namespace std;

template<class T>
bool Search(T * arr, int iSize, T value)
{
    bool bFlag = false;

    for(int i = 0; i < iSize; i++)
    {
        if(arr[i] == value)
        {
            bFlag = true;
            break;
        }
    }

    return bFlag;
}

int main()
{
    int iSize = 0;
    int Find = 0;
    bool bRet = false;
    int Arr[] = {1,2,3,4,5,6,7};

    iSize = 7;
    Find = 6;

    bRet = Search(Arr, iSize, Find);

    if(bRet == true)
    {
        cout << "Value is present in array\n";
    }
    else
    {
        cout << "Value is not present in array\n";
    }

    return 0;
}