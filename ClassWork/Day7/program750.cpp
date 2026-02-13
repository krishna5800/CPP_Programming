#include<iostream>
using namespace std;

class ArrayX
{
    public:
        int *Arr;
        int iSize;

        ArrayX(int no)
        {
            cout<<"Inside constructor\n";
            iSize = no;
            Arr = new int[iSize];
        }

        void Accept()
        {
            cout <<"Enter elements : \n";

            int iCnt = 0;

            for(iCnt = 0; iCnt < iSize; iCnt++)
            {
                cin >> Arr[iCnt];
            }
        }

        void Display()
        {
            cout <<"Elements of the Array are : \n";

            int iCnt = 0;

            for(iCnt = 0; iCnt < iSize; iCnt++)
            {
                cout << Arr[iCnt] << "\t";
            }

            cout << "\n";
        }

        bool LinearSearch(int iNo)
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

        ~ArrayX()
        {
            cout<<"Inside destructor\n";
            delete [] Arr;
        }   
};

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

    return 0;
}