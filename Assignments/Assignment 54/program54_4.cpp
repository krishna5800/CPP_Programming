// 4. write a generic program to reverse an array

#include<iostream>
using namespace std;

template<class T>
void Reverse(T * arr, int iSize)
{
    T * pt1 = NULL;
    T * pt2 = NULL;

    pt1 = arr;
    pt2 = arr;

    for(int i = 0; i < iSize; i++)
    {
        pt2++;
    }

    pt2--;

    while(pt1 < pt2)
    {
        swap(*pt1, *pt2);
        pt1++;
        pt2--;
    }
}

int main()
{
    int iSize = 0;
    int iRet = 0;

    int Arr[] = {1,2,3,4,5,6,7};
    iSize = 7;

    Reverse(Arr, iSize);

    for(int i = 0; i < iSize; i++)
    {
        cout << Arr[i] << "\t";
    }

    cout << "\n";

    return 0;
}