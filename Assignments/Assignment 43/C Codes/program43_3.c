// 3. Write a program which returns addition of all even element from singly linear linked list.

// Function Prototype:

// int AdditionEven(PNODE Head);

// Input linked list: |11|->|20|->|32|->|41|

// Output: 52

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

    InsertFirst(&head, 89);
    InsertFirst(&head, 6);
    InsertFirst(&head, 41);
    InsertFirst(&head, 17);
    InsertFirst(&head, 20);
    InsertFirst(&head, 11);

    Display(head);
    iRet = Count(head);
    printf("Count is : %d\n", iRet);

    iRet = AdditionEven(head);
    printf("Addition is : %d\n", iRet);

    return 0;
}