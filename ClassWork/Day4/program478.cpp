#include<iostream>
using namespace std;

template<class T>
class ArrayX
{
    public:
        T *Arr;
        int iSize;

        ArrayX(int no);
        void Accept();
        void Display();
        T Addition();
        T Maximum();
        int Frequency(T);
        ~ArrayX();
};

template<class T>
ArrayX<T> :: ArrayX(int no)
{
    cout<<"Inside constructor\n";
    iSize = no;
    Arr = new T[iSize];
}

template<class T>
void ArrayX<T> :: Accept()
{
    cout <<"Enter elements : \n";

    int iCnt = 0;

    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        cin >> Arr[iCnt];
    }
}

template<class T>
void ArrayX<T> :: Display()
{
    cout <<"Elements of the Array are : \n";

    int iCnt = 0;

    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        cout << Arr[iCnt] << "\t";
    }

    cout << "\n";
}

template<class T>
T ArrayX<T> :: Addition()
{
    T iSum;
    int iCnt = 0;

    iSum = Arr[0] - Arr[0];         // Imp

    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        iSum = iSum + Arr[iCnt];
    }

    return iSum;
}

template<class T>
T ArrayX<T> :: Maximum()
{
    T iMax;
    int iCnt = 0;

    iMax = Arr[0];

    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        if(Arr[iCnt] > iMax)
        {
            iMax = Arr[iCnt];
        }
    }

    return iMax;
}

template<class T>
int ArrayX<T> :: Frequency(T iNo)
{
    int iCount = 0;
    int iCnt = 0;

    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        if(iNo == Arr[iCnt])
        {
            iCount++;
        }
    }

    return iCount;
}

template<class T>
ArrayX<T> :: ~ArrayX()
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
    ArrayX<int> *aobj = new ArrayX<int>(iValue);

    // Use Memor
    aobj->Accept();
    aobj->Display();

    cout << "Summation of all elements : " << aobj->Addition() << "\n";

    cout << "Maximum of all elements is : " << aobj->Maximum() << "\n";

    cout << "Frequency is : " << aobj->Frequency(11) << "\n";

    // Deallocate the memory
    delete aobj;

    return 0;
}