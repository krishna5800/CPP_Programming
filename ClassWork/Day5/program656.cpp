// Input :  4
// Output : 4 3 2 1

#include<iostream>
using namespace std;

void Display(int iNo)
{
    if(iNo > 0)
    {
        cout << iNo << "\t";
        iNo--;
        Display(iNo);
    }
}

int main()
{
    Display(4);
    
    return 0;
}