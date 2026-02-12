#include<iostream>
using namespace std;

bool ChkPerfect(int iNo)
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
        ChkPerfect(iNo);
    }

    if(iSum == iNo)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int iValue = 0;
    bool bRet = 0;

    cout << "Enter Number : \n";
    cin >> iValue;

    bRet = ChkPerfect(iValue);

    if(bRet == true)
    {
        cout << "Is a Perfect number\n";
    }
    else
    {
        cout << "Is not a Perfect number\n";
    }

    return 0;
}