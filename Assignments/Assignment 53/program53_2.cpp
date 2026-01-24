// 2. Write generic program to check weather array is sorted or not.

#include<iostream>
using namespace std;

template<class T>
bool CheckSorted(T * arr, int iSize)
{
    int i = 0, j = 0;
    bool bAns = false;

    j = 1;

    for(int iCnt = 0; iCnt < iSize-1; iCnt++)
    {
        if(j < iSize && arr[i] > arr[j])
        {
            bAns = true;
            break;
        }

        i++;
        j++;
    }

    return bAns;
}

int main()
{
    int iSize = 0;
    bool bRet = false;

    int Arr[] = {1,2,3,4,6,5};
    iSize = 6;

    bRet = CheckSorted(Arr,iSize);

    if(bRet == true)
    {
        cout << "Array is not sorted\n";
    }
    else
    {
        cout << "Array is sorted\n";
    }

    return 0;
}