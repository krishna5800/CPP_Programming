// 3. Write generic program to find second largest element.

#include<iostream>
using namespace std;

template<class T>
T SecondMax(T * arr, int iSize)
{
    T iMaxI = 0;
    T iMaxII = 0;

    iMaxI = arr[0];

    for(int i = 0; i < iSize; i++)
    {
        if(iMaxI <= arr[i])
        {
            iMaxII = iMaxI;
            iMaxI = arr[i];
        }
    }

    return iMaxII;
}

int main()
{
    int iSize = 0;
    int iRet = 0;

    int Arr[] = {10,1,41,62,30,621,694,6416,40};
    iSize = 9;

    iRet = SecondMax(Arr, iSize);

    cout << "Second max is : " << iRet << "\n";

    return 0;
}