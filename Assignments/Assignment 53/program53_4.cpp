// 4. Write generic program to find second Smallest element.

#include<iostream>
using namespace std;

template<class T>
T SecondMin(T * arr, int iSize)
{
    T iMinI = 0;
    T iMinII = 0;

    iMinI = arr[0];

    for(int i = 0; i < iSize; i++)
    {
        if(iMinI >= arr[i])
        {
            iMinII = iMinI;
            iMinI = arr[i];
        }
    }

    return iMinII;
}

int main()
{
    int iSize = 0;
    int iRet = 0;

    int Arr[] = {10,1,41,62,30,621,694,6416,40};
    iSize = 9;

    iRet = SecondMin(Arr, iSize);

    cout << "Second max is : " << iRet << "\n";

    return 0;
}