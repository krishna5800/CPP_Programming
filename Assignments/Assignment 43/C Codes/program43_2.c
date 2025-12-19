// 2. Write program which displays all elements which are prime from singly linear linked list.

// Function Prototype:

// int DisplayPrime(PNODE Head);

// Input linked list: |11|->|20|->|17|->|41|->|22|->|89|

// Output: 11 17 41 89

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

void DisplayPrime(PNODE first)
{
    int iCnt = 0;
    bool bAns = false;

    while(first != NULL)
    {
        bAns = false;

        for(iCnt = 2; iCnt < (first->data); iCnt++)
        {
            if((first->data)%iCnt == 0)
            {
                bAns = false;
                break;
            }

            bAns = true;
        }

        if(bAns == true)
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

    InsertFirst(&head, 89);
    InsertFirst(&head, 6);
    InsertFirst(&head, 41);
    InsertFirst(&head, 17);
    InsertFirst(&head, 20);
    InsertFirst(&head, 11);

    Display(head);
    iRet = Count(head);
    printf("Count is : %d\n", iRet);

    printf("Prime Numbers in LL are : \n");
    DisplayPrime(head);

    return 0;
}