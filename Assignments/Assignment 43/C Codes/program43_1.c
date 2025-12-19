// 1. Write a program which displays all elements which are perfect from singly linear linked list.

// Function Prototype:

// int DisplayPerfect(PNODE Head);

// Input linked list: |11|->|28|->|17|->|41|->|6|->|89|

// Output:     6    28

#include<stdio.h>
#include<stdlib.h>

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

void DisplayPerfect(PNODE first)
{
    int iCnt = 0;
    int iSum = 0;

    while(first != NULL)
    {
        iSum = 0;

        for(iCnt = 1; iCnt <= (first->data)/2; iCnt++)
        {
            if((first->data)%iCnt == 0)
            {
                iSum = iSum + iCnt;
            }
        }

        if(iSum == (first->data))
        {
            printf("%d\t", first->data);
        }

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
    InsertFirst(&head, 6);

    Display(head);
    iRet = Count(head);
    printf("Count is : %d\n", iRet);

    printf("Perfect Numbers in LL are : \n");
    DisplayPerfect(head);

    return 0;
}