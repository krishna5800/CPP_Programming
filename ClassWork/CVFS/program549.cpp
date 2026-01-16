#include<stdio.h>
#include<stdlib.h>

// CONDITIONAL PREPROCESSING
int main()
{
    #ifdef _WIN32
        system("dir");
    #else
        system("ls");
    #endif

    return 0;
}