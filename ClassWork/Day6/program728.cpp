#include<iostream>
#include<stdio.h>

using namespace std;

void strdisplay(char * str)
{
    if(*str != '\0')
    {
        str++;  
        strdisplay(str);
        cout << *str << "\n";
    }
}

int main()
{
    char Arr[50] = {'\0'};

    printf("Enter String : \n");
    scanf("%[^'\n]s", Arr);

    strdisplay(Arr);

    return 0;
}