#include<iostream>
using namespace std;

class ArrayX
{
    public:
        int *Arr;
        int iSize;

        ArrayX(int no);
        void Accept();
        void Display();
        bool LinearSearch(int iNo);
        bool BidirectionalSearch(int iNo);
        ~ArrayX();
};

ArrayX :: ArrayX(int no)
{
    cout<<"Inside constructor\n";
    iSize = no;
    Arr = new int[iSize];
}

void ArrayX :: Accept()
{
    cout <<"Enter elements : \n";

    int iCnt = 0;

    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        cin >> Arr[iCnt];
    }
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

int main()
{
    int iValue = 0;

    cout << "Enter the number of elements : \n";
    cin >> iValue;

    ArrayX aobj (iValue);

    aobj.Accept();

    aobj.Display();

    if(aobj.LinearSearch(21))
    {
        cout << "Element is present\n";
    }
    else
    {
        cout << "Their is no such element\n";
    }

    if(aobj.BidirectionalSearch(21))
    {
        cout << "Element is present\n";
    }
    else
    {
        cout << "Their is no such element\n";
    }

    return 0;
}