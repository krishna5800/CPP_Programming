// 5. Write generic program to replace all occurrences of a value

#include<iostream>
using namespace std;

template<class T>
void Replace(T * arr, int iSize, T oldVal, T newVal)
{
    for(int i = 0; i < iSize; i++)
    {
        if(arr[i] == oldVal)
        {
            arr[i] = newVal;
        }
    }
}

int main()
{
    int iSize = 0;
    int iRet = 0;

    int Arr[] = {1,5,2,5,3,5,4,5};
    iSize = 8;

    Replace(Arr, iSize, 5, 10);

    for(int i = 0; i < iSize; i++)
    {
        cout << Arr[i] << "\t";
    }

    return 0;
}