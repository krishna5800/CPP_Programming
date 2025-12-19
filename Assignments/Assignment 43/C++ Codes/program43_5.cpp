// 5. Write a program which display addition of digits of element from singly linear linked list.

// Function Prototype: int SumDigit(PNODE Head);

// Input linked list: |110|->|230|->|20|->|240|->|640|

// Output: 2 5 2 6 10

#include<iostream>
using namespace std;

struct node
{
    int data;

    struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

// call by value

void Display(PNODE first)
{
    while(first != NULL)
    {
        cout << "| " << first->data << " | " << "-> "; 
        first = first->next;
    }

    cout << "NULL\n";
}

int Count(PNODE first)
{
    int iConut = 0;
    while(first != NULL)
    {
        iConut++;
        first = first->next;
    }

    return iConut;
}

// call by address

void InsertFirst(PPNODE first, int no)
{
    PNODE newn = NULL;

    newn = new NODE;

    newn->data = no;
    newn->next = NULL;

    if((*first) == NULL)                // LL is empty
    {
        (*first) = newn;
    }
    else                                // LL has atleast 1 node
    {
        newn->next = (*first);
        (*first) = newn;
    }
}

void SumDigit(PNODE first)
{
    int iDigit = 0;
    int iNo = 0;
    int iSum = 0;

    while(first != NULL)
    {
        iNo = first->data;
        iSum = 0;

        while(iNo != 0)
        {
            iDigit = iNo%10;
            iSum = iSum + iDigit;
            iNo = iNo/10;
        }

        cout << iSum << "\t";
        first = first->next;
    }
}

int main()
{
    PNODE head = NULL;
    int iRet = 0;


    InsertFirst(&head, 101);
    InsertFirst(&head, 51);
    InsertFirst(&head, 28);
    InsertFirst(&head, 21);
    InsertFirst(&head, 11);
    InsertFirst(&head, 10);
    InsertFirst(&head, 6);

    Display(head);
    iRet = Count(head);
    cout << "Count is : " << iRet << "\n";

    SumDigit(head);

    return 0;
}