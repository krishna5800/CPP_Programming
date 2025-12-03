#include<iostream>
using namespace std;

void Display()
{
    static int iCnt = 1;        // Memory is not allocated in stack frame of Display()
                                // But memory is allocated in static memory / static region
    if(iCnt <= 4)
    {
        cout << "Jay Ganesh...\n";
        iCnt++;
        Display();
    }
}

int main()
{
    Display();
    
    return 0;
}