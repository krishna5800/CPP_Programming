// 4. Write a program which return second maximum element from singly linear linked list.

// Function Prototype

// int SecMaximum (PNODE Head);

// Input linked list: |110|->|230|->|320|->|240|

// Output: 240

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node 
{
    int data;

    struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

//call by value 

void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("| %d | -> ", first->data);
        first = first->next;
    }

    printf("NULL\n");
}

int Count(PNODE first)
{
    int iCount = 0;

    while(first->next != NULL)
    {
        iCount++;
        first = first->next;
    }

    return iCount;
}

// call by address

void InsertFirst(PPNODE first, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if((*first) == NULL)                // LL is empty
    {
        (*first) = newn;
    }
    else                                // LL has atlest one element
    {
        newn->next = (*first);
        (*first) = newn;
    }
}

int SecMaximum(PNODE first)
{
    int iMax = 0;
    int iMax1 = 0;

    while(first != NULL)
    {
        if(iMax < (first->data))
        {
            iMax1 = iMax;
            iMax = first->data;
        }

        first = first->next;
    }

    return iMax1;
}

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertFirst(&head, 89);
    InsertFirst(&head, 6);
    InsertFirst(&head, 41);
    InsertFirst(&head, 17);
    InsertFirst(&head, 20);
    InsertFirst(&head, 80);
    InsertFirst(&head, 11);

    Display(head);
    iRet = Count(head);
    printf("Count is : %d\n", iRet);

    iRet = SecMaximum(head);
    printf("Second Max is : %d\n", iRet);

    return 0;
}