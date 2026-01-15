// 4. Write generic program to accept N values and search last occurrence of any specific value.

// Input: 10 20 30 10 30 40 10 40 10

// Value to search: 40.

// Output: 8

#include<iostream>
using namespace std;

template<class T>
int SearchLast(T arr[], int iSize, T iNo)
{
    int iCnt = 0;
    int iCount = iSize;

    for(iCnt = (iSize-1); iCnt >= 0; iCnt--)
    {
        if(arr[iCnt] == iNo)
        {
            return iCount;
            break;
        }

        iCount--;
    }

    return -1;
}

int main()
{
    int iRet = 0;

    int arr[] = {10, 20, 30, 10, 30, 40, 10, 40, 10};

    iRet = SearchLast(arr, 9, 40);

    if(iRet == -1)
    {
        cout << "Element is not in array\n";
    }
    else
    {
        cout << "Last occurence is : " << iRet << "\n";
    }
    
    char brr[] = {'A','B','A','C','D','A'};

    iRet = SearchLast(brr, 6, 'A');

    if(iRet == -1)
    {
        cout << "Element is not in array\n";
    }
    else
    {
        cout << "Last occurence is : " << iRet << "\n";
    }

    return 0;
}