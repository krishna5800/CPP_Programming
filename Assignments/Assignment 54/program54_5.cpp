// 5. write a generic program to find smallest element form array

#include<iostream>
using namespace std;

template<class T>
T Min(T * arr, int iSize)
{
    T iMin = 0;
    int i = 0;

    for(i = 0, iMin = arr[0]; i < iSize; i++)
    {
        if(iMin > arr[i])
        {
            iMin = arr[i];
        }
    }

    return iMin;
}

int main()
{
    int iSize = 0;
    int iRet = 0;

    int Arr[] = {2,3,1,4,5,6,7};
    iSize = 7;

    iRet = Min(Arr, iSize);

    cout << "Minimum is : " << iRet << "\n";
    
    return 0;
}