// 3. write a generic program to find sum of all odd elements

#include<iostream>
using namespace std;

template<class T>
T SumOdd(T * arr, int iSize)
{
    T iSum = 0;

    for(int i = 0; i < iSize; i++)
    {
        if(arr[i] % 2 != 0)
        {
            iSum = iSum + arr[i];
        }
    }

    return iSum;
}

int main()
{
    int iSize = 0;
    int Find = 0;
    int iRet = 0;

    int Arr[] = {1,2,3,4,5,6,7};

    iSize = 7;
    Find = 6;

    iRet = SumOdd(Arr, iSize);

    cout << "Sum of odd numbers is : " << iRet << "\n";

    return 0;
}