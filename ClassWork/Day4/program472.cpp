#include<iostream>
using namespace std;

class ArrayX
{
    public:
         int *Arr;
        int iSize;

        ArrayX(int no)
        {
            cout<<"Inside constructor\n";
            iSize = no;
            Arr = new int[iSize];
        }

        ~ArrayX()
        {
            cout<<"Inside destructor\n";
            delete [] Arr;
        }   
};

int main()
{
    // ArrayX aobj(10);

    // Allocate Memory
    ArrayX *aobj = new ArrayX(10);

    // Use Memory


    // Deallocate the memory
    delete aobj;

    return 0;
}