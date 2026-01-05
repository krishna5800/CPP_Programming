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
        int Addition();
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

int ArrayX :: Addition()
{
    int iSum = 0;
    int iCnt = 0;

    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        iSum = iSum + Arr[iCnt];
    }

    return iSum;
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

    // Allocate Memory
    ArrayX *aobj = new ArrayX(iValue);

    // Use Memor
    aobj->Accept();
    aobj->Display();

    cout << "Summation of all elements : " << aobj->Addition() << "\n";

    // Deallocate the memory
    delete aobj;

    return 0;
}