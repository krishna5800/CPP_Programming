// 3. Write a program which returns addition of all even element from singly linear linked list.

// Function Prototype:

// int AdditionEven(PNODE Head);

// Input linked list: |11|->|20|->|32|->|41|

// Output: 52

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

int AdditionEven(PNODE first)
{
    int iSum = 0;

    while(first != NULL)
    {
        if((first->data)%2 == 0)
        {
            iSum = iSum + (first->data);
        }

        first = first->next;
    }

    return iSum;
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

    iRet = AdditionEven(head);
    cout << "Addition is : " << iRet << "\n";

    return 0;
}