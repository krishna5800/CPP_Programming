#include<iostream>
using namespace std;

#define INC_ORDER 1
#define DEC_ORDER 2

class ArrayX
{
    public:
        int *Arr;
        int iSize;
        bool Sorted;

        ArrayX(int no);
        ~ArrayX();

        void Accept();
        void Display();

        bool CheckSorted();   
        
        void BubbleSort();
        void BubbleSortEfficient();
        void BubbleSortEfficientX(int iOption);

        void SelectionSort();
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

void ArrayX :: BubbleSort()
{
    int i = 0, j = 0;
    int temp = 0;
    int Pass = 0;
    int Time= 0;

    if(Sorted == true)                                              // Important Filter
    {
        return;
    }

    Time = 1;

    for(i = 0, Pass = 1; i < iSize-1; i++, Pass++)                  // Outer loop
    {
        for(j = 0; j < iSize-1-i; j++, Time++)                              // Inner loop
        {
            if(Arr[j] > Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
            }
        }

        cout << "\nData after Pass  : " << i+1 << "\n";
        Display();
    }

    cout << "Number of passes for bubble sort : "  << Pass << "\n";

    cout << "Total number of iterations : " << Time << "\n";

    Sorted = true;
}

void ArrayX :: BubbleSortEfficient()
{
    int i = 0, j = 0;
    int temp = 0;

    bool bFlag = false;

    // if(Sorted == true)                                              // Important Filter
    // {
    //     return;
    // }

    bFlag = true;

    for(i = 0; (i < iSize-1) && (bFlag == true); i++)                  // Outer loop
    {
        bFlag = false;

        for(j = 0; j < iSize-1-i; j++)                              // Inner loop
        {
            if(Arr[j] > Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;

                bFlag = true;
            }
        }

        cout << "\nData after Pass  : " << i + 1<< "\n";
        Display();
    }

    cout << "Number of passes for bubble sort : "  << (i) << "\n";

    Sorted = true;
}

// 1 : Increasing
// 2 : Decreasing
void ArrayX :: BubbleSortEfficientX(int iOption = INC_ORDER)
{
    int i = 0, j = 0;
    int temp = 0;

    bool bFlag = false;

    if(iOption < INC_ORDER || iOption > DEC_ORDER)
    {
        cout << "Invalid Option for sorting\n";
        cout << "1 : Increasing\n";
        cout << "2 : Decreasing\n";
        return;
    }

    // if(Sorted == true)                                               // Important Filter
    // {
    //     return;
    // }

    bFlag = true;

    if(iOption == INC_ORDER)
    {

        for(i = 0; (i < iSize-1) && (bFlag == true); i++)                   // Outer loop
        {
            bFlag = false;

            for(j = 0; j < iSize-1-i; j++)                                  // Inner loop
            {
                if(Arr[j] > Arr[j+1])
                {
                    temp = Arr[j];
                    Arr[j] = Arr[j+1];
                    Arr[j+1] = temp;

                    bFlag = true;
                }
            }

            cout << "\nData after Pass  : " << i + 1<< "\n";
            Display();
        }
    }//end of iOption == 1
    else if(iOption == DEC_ORDER)
    {
        for(i = 0; (i < iSize-1) && (bFlag == true); i++)                   // Outer loop
        {
            bFlag = false;

            for(j = 0; j < iSize-1-i; j++)                                  // Inner loop
            {
                if(Arr[j] < Arr[j+1])
                {
                    temp = Arr[j];
                    Arr[j] = Arr[j+1];
                    Arr[j+1] = temp;

                    bFlag = true;
                }
            }

            cout << "\nData after Pass  : " << i + 1<< "\n";
            Display();
        }

    }

    cout << "Number of passes for bubble sort : "  << (i) << "\n";

    Sorted = true;
}

void ArrayX :: SelectionSort()
{
    int i = 0, j = 0, temp = 0;
    int min_index = 0;

    for(i = 0; i < iSize-1; i++)
    {

        min_index = i;
        
        for(j= i+1; j < iSize; j++)
        {
            if(Arr[j] < Arr[min_index])
            {
                min_index = j;
            }
        }

        temp = Arr[i];
        Arr[i] = Arr[min_index];
        Arr[min_index] = temp;
    }
}

int main()
{
    int iValue = 0;

    cout << "Enter the number of elements : \n";
    cin >> iValue;

    ArrayX aobj (iValue);

    aobj.Accept();

    cout << "Data before sorting\n";
    aobj.Display();

    aobj.SelectionSort();

    cout << "\nData after sorting\n";
    aobj.Display();

    return 0;
}