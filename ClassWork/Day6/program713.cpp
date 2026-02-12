#include<iostream>
using namespace std;

int SumFactore(int iNo)
{
    static int iCnt = 1;
    static int iSum = 0;

    if(iCnt <= iNo/2)
    {
        if(iNo % iCnt == 0)
        {
            iSum = iSum + iCnt;
        }
        iCnt++;
        SumFactore(iNo);
    }

    return iSum;
}

int main()
{
    int iValue = 0;
    int iRet = 0;

    cout << "Enter Number : \n";
    cin >> iValue;

    iRet = SumFactore(iValue);

    cout << "Summation is : " << iRet << "\n";

    return 0;
}