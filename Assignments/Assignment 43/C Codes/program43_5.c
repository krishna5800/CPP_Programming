// 5. Write a program which display addition of digits of element from singly linear linked list.

// Function Prototype: int SumDigit(PNODE Head);

// Input linked list: |110|->|230|->|20|->|240|->|640|

// Output: 2 5 2 6 10

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
            iNo = iNo/10;
            iSum = iSum + iDigit;
        }

        printf("%d\t", iSum);

        first = first->next;
    }
}

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertFirst(&head, 111);
    InsertFirst(&head, 101);
    InsertFirst(&head, 51);
    InsertFirst(&head, 21);
    InsertFirst(&head, 11);
    InsertFirst(&head, 10);

    Display(head);
    iRet = Count(head);
    printf("Count is : %d\n", iRet);

    SumDigit(head);

    return 0;
}