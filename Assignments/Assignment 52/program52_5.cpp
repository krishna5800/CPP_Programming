// 5. Write a generic program to take N numbers as input and return smallest value.

#include<iostream>
using namespace std;

template<class T>
T Min(T arr[], int iSize)
{
    T MinNum = 0;

    MinNum = arr[1];

    for(int i = 0; i < iSize; i++)
    {
        if(MinNum > arr[i])
        {
            MinNum = arr[i];
        }
    }

    return MinNum;
}

int main()
{ 
    int arr[] = {10,20,30,40,50};
    int iRet = 0;
    iRet = Min(arr, 5);
    cout << "Min is : " << iRet << "\n";

    float brr[] = {10.5,20.5,30.5,40.5,50.5};
    float fRet = 0.0f;
    fRet = Min(brr, 5);
    cout << "Min is : " << fRet << "\n";

    return 0;
}