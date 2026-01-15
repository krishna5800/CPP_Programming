// 5. Write generic program to accept N values and reverse the contents.

// Input: 10 20 30 10 30 40 10 40 10

// Output: 10 40 10 40 30 10 30 20 10

#include<iostream>
using namespace std;

template<class T>
void Reverse(T arr[], int iSize, T iNo)
{
    int iCnt = 0;
    int iCount = iSize;

    for(iCnt = (iSize-1); iCnt >= 0; iCnt--)
    {
        cout << arr[iCnt] << "\t";
    }

    cout << "\n";
}

int main()
{
    int iRet = 0;

    int arr[] = {10, 20, 30, 10, 30, 40, 10, 40, 10};

    Reverse(arr, 9, 40);

    char brr[] = {'A','B','A','C','D','A'};

    Reverse(brr, 6, 'A');

    return 0;
}