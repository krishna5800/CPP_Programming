// 3. Write a program which returns addition of all element from singly linear linked list.

// Function Prototype :

// int Addition(PNODE Head);

// Input linked list: |10|->|20|->|30|->|40|->NULL

// Output: 100

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

int Addition(PNODE first)
{
    int iSum = 0;

    while((first) != NULL)
    {
        iSum = iSum + (first->data);
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
    InsertFirst(&head, 21);
    InsertFirst(&head, 11);
    InsertFirst(&head, 10);

    Display(head);
    iRet = Count(head);
    cout << "Count is : " << iRet << "\n";

    iRet = Addition(head);

    cout << "Addition is : " << iRet << "\n";

    return 0;
}