// 4. Write a program which return second maximum element from singly linear linked list.

// Function Prototype

// int SecMaximum (PNODE Head);

// Input linked list: |110|->|230|->|320|->|240|

// Output: 240

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

int SecMaximum(PNODE first)
{
    int iMax1 = 0;
    int iMax2 = 0;

    // iMax1 = first->data;

    while(first != NULL)
    {
        if(iMax1 < first->data)
        {
            iMax2 = iMax1;
            iMax1 = first->data;
        }

        first = first->next;
    }

    return iMax2;
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

    iRet = SecMaximum(head);
    cout << "Second MAX is : " << iRet << "\n";

    return 0;
}