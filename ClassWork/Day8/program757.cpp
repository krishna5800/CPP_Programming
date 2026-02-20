#include<iostream>
using namespace std;

class ArrayX
{
    public:
        int *Arr;
        int iSize;
        bool Sorted;

        ArrayX(int no);
        void Accept();
        void Display();
        bool LinearSearch(int iNo);
        bool BidirectionalSearch(int iNo);
        bool CheckSorted();
        bool BinarySearch(int iNo);
        ~ArrayX();
};

ArrayX :: ArrayX(int no)
{
    cout<<"Inside constructor\n";
    iSize = no;
    Arr = new int[iSize];
    Sorted = true;
}

void ArrayX :: Accept()
{
    cout <<"Enter elements : \n";

    int iCnt = 0;

    cin >> Arr[iCnt];

    for(iCnt = 1; iCnt < iSize; iCnt++)
    {
        cin >> Arr[iCnt];

        if(Arr[iCnt-1] > Arr[iCnt])
        {
            Sorted = false;
        }
    }

    // Sorted = CheckSorted();
}

void ArrayX :: Display()
{
    cout <<"Elements of the Array are : \n";

    int iCnt = 0;

    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        cout << Arr[iCnt] << "\t";
    }

    cout << "\n";
}

bool ArrayX :: LinearSearch(int iNo)
{
    bool bFlag = false;
    int i = 0;

    for(i = 0; i < iSize; i++)
    {
        if(iNo == Arr[i])
        {
            bFlag = true;
            break;
        }
    }

    return bFlag;
}

bool ArrayX :: BidirectionalSearch(int iNo)
{
    bool bFLag = false;
    int iStart = 0;
    int iEnd = 0;

    for(iStart = 0, iEnd = iSize-1; iStart <= iEnd; iStart++, iEnd--)
    {
        if(Arr[iStart] == iNo || Arr[iEnd] == iNo)
        {
            bFLag = true;
            break;
        }
    }

    return bFLag;
}

ArrayX :: ~ArrayX()
{
    cout<<"Inside destructor\n";
    delete [] Arr;
} 

// iSize = 10

// 0    1   2   3   4   5   6   7   8   9
// 12   14  17  24  28  36  48  52  52  65  

bool ArrayX :: CheckSorted()
{
    int i = 0;
    bool bFlag = true;

    for(i = 0; i < iSize-1; i++)
    {
        if(Arr[i] > Arr[i+1])
        {
            bFlag = false;
            break;
        }
    }

    return bFlag;
}

bool ArrayX :: BinarySearch(int iNo)
{
    int iStart = 0, iEnd = 0, iMid = 0;
    bool bFlag = false;

    if(Sorted == false)
    {
        return false;
    }

    iStart = 0;
    iEnd = iSize-1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd-iStart) / 2);

        if(Arr[iMid] == iNo)
        {
            bFlag = true;
            break;
        }
        else if(iNo < Arr[iMid])
        {
            iEnd = iMid - 1;
        }
        else if(iNo > Arr[iMid])
        {
            iStart = iMid + 1;
        }
    }

    return bFlag;
}

int main()
{
    int iValue = 0;

    cout << "Enter the number of elements : \n";
    cin >> iValue;

    ArrayX aobj (iValue);

    aobj.Accept();

    aobj.Display();

    // if(aobj.LinearSearch(21))
    // {
    //     cout << "Element is present\n";
    // }
    // else
    // {
    //     cout << "Their is no such element\n";
    // }

    // if(aobj.BidirectionalSearch(21))
    // {
    //     cout << "Element is present\n";
    // }
    // else
    // {
    //     cout << "Their is no such element\n";
    // }

    // if(aobj.Sorted)
    // {
    //     cout << "Data is sorted\n";
    // }
    // else
    // {
    //     cout << "Data is not sorted\n";
    // }

    if(aobj.BinarySearch(25))
    {
        cout << "Element is present\n";
    }
    else
    {
        cout << "Their is no such element\n";
    }

    return 0;
}