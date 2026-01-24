// 1. Write generic program to copy one array into another

#include<iostream>
using namespace std;

template<class T>
void CopyArray(T * src, T * dest, int iSize)
{
    for(int i = 0; i < iSize; i++)
    {
        dest[i] = src[i];
    }
}

int main()
{
    int iSize = 0;

    int Arr[] = {1,2,3,4,5};
    iSize = 5;

    printf("Source Array : \n");

    for(int i = 0; i < iSize; i++)
    {
        printf("%d\n", Arr[i]);
    }

    int Brr[iSize] = {0};

    CopyArray(Arr, Brr, iSize);

    printf("Destination Array : \n");

    for(int i = 0; i < iSize; i++)
    {
        printf("%d\n", Brr[i]);
    }

    return 0;
}