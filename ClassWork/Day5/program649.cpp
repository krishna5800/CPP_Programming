#include<iostream>
using namespace std;

void Display()
{
    int i = 1;   // Issue

    if(i <= 4)
    {
        cout << i << "\n";
        i++;
        Display();
    }
}

int main()
{
    Display();
    
    return 0;
}