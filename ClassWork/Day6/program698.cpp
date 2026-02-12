// Input : 5
// Output : 0   1   2   3   4

#include<iostream>
using namespace std;

void Display(int iNo)
{
    if(iNo > 0)
    {
        Display(--iNo);     //issue is due to this
        cout << iNo << "\t";
    }
    else
    {
        cout << "\n";
    }
}

int main()
{
    int iValue = 0;

    cout << "Enter Number : \n";
    cin >> iValue;

    Display(iValue);

    return 0;
}