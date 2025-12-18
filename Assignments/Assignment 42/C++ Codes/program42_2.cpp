// 2. Write a program which search last occurrence of particular element from 
// singly linear linked list.
// Function should return position at which element is found.

// Function Prototype:

// int SearchLastOcc( PNODE Head, int no);

// Input linked list: |10|->|20|->|30|->|40|->|50|->|30|->|70|->NULL

// Input element: 30

// Output: 6

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

void Display(PNODE first)
{
    while((first) != NULL)
    {
        cout << "| " << first->data << " | " << " -> ";
        first = first->next;
    }

    cout << "NULL \n";
}

int Count(PNODE first)
{
    int iCount = 0;

    while((first) != NULL)
    {
        iCount++;
        first = first->next;
    }

    return iCount;
}

void InsertFirst(PPNODE first, int no)
{
    PNODE newn = NULL;

    newn = new NODE;

    newn->data = no;
    newn->next = NULL;

    if((*first) == NULL)      // LL is empty
    {
        *first = newn;
    }
    else                    // LL has atlest 1 node
    {
        newn->next = (*first);
        (*first) = newn;
    }
}

int SearchLastOcc(PNODE first, int no)
{
    int iCount = 0;
    int iVerify = 0;

    while((first->next) != NULL)
    {
        iCount++;
        if((first->data) == no)
        {
            iVerify = iCount;
        }

        first = first->next;
    }

    return iVerify;
}

int main()
{
    PNODE head = NULL;
    int iRet = 0;
    int iValue = 0;

    InsertFirst(&head, 101);
    InsertFirst(&head, 51);
    InsertFirst(&head, 21);
    InsertFirst(&head, 51);
    InsertFirst(&head, 11);
    InsertFirst(&head, 51);
    InsertFirst(&head, 10);

    Display(head);
    iRet = Count(head);
    cout << "Count is : " << iRet << "\n";

    cout << "Enter number : \n";
    cin >> iValue;

    iRet = SearchLastOcc(head, iValue);

    if(iRet == 0)
    {
        cout << "Number is not in linked list\n";
    }
    else
    {
        cout << "Number last occured at position :" << iRet << "\n";
    }

    return 0;
}