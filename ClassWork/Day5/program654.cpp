// Input :  4
// Output : 4 3 2 1

#include<iostream>
using namespace std;

void Display(int iNo)
{
    int i = 0;

    i = iNo;

    while(i > 0)
    {
        cout << i << "\t";
        i--;
    }
}

int main()
{
    Display(4);
    
    return 0;
}