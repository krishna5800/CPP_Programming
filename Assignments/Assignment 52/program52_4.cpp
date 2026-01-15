// 4. Write a generic program to take N numbers as input and return largest value.

#include<iostream>
using namespace std;

template<class T>
T Max(T arr[], int iSize)
{
    T nMax = 0;

    nMax = arr[1];

    for(int i = 0; i < iSize; i++)
    {
        if(nMax < arr[i])
        {
            nMax = arr[i];
        }
    }

    return nMax;
}

int main()
{ 
    int arr[] = {10,20,30,40,50};
    int iRet = 0;
    iRet = Max(arr, 5);
    cout << "Max is : " << iRet << "\n";

    float brr[] = {10.5,20.5,30.5,40.5,50.5};
    float fRet = 0.0f;
    fRet = Max(brr, 5);
    cout << "Max is : " << fRet << "\n";

    return 0;
}