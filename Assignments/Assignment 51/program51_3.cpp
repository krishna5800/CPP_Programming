// 3. Write generic program to accept N values and search first occurrence of any specific value.

// Input: 10 20 30 10 30 40 10 40 10

// Value to search: 40.

// Output: 6

#include<iostream>
using namespace std;

template<class T>
int SearchFirst(T arr[], int iSize, T iNo)
{
    int iCnt = 0;
    int iCount = 1;

    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        if(arr[iCnt] == iNo)
        {
            return iCount;
            break; 
        }

        iCount++;
    }

    return -1;
}

int main()
{
    int iRet = 0;

    int arr[] = {10, 20, 30, 10, 30, 40, 10, 40, 10};

    iRet = SearchFirst(arr, 9, 40);

    if(iRet == -1)
    {
        cout << "Element is not in array\n";
    }
    else
    {
        cout << "First occurence is : " << iRet << "\n";
    }
    
    char brr[] = {'A','B','A','C','D','A'};

    iRet = SearchFirst(brr, 6, 'D');

    if(iRet == -1)
    {
        cout << "Element is not in array\n";
    }
    else
    {
        cout << "First occurence is : " << iRet << "\n";
    }

    return 0;
}