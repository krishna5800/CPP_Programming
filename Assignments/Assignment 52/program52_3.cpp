// 3. Write a generic program to take N numbers as input and display their addition

#include<iostream>
using namespace std;

template<class T>
T AddN(T arr[], int iSize)
{
    T sum = 0;

    for(int i = 0; i < iSize; i++)
    {
        sum = arr[i] + sum;
    }

    return sum;
}

int main()
{ 
    int arr[] = {10,20,30,40,50};
    int iRet = 0;
    iRet = AddN(arr, 5);
    cout << "Addition is : " << iRet << "\n";

    float brr[] = {10.5,20.5,30.5,40.5,50.5};
    float fRet = 0.0f;
    fRet = AddN(brr, 5);
    cout << "Addition is : " << fRet << "\n";

    return 0;
}