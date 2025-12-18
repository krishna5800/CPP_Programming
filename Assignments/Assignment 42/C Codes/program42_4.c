// 4. Write a program which return largest element from singly linear linked list.

// Function Prototype:

// int Maximum(PNODE Head);

// Input linked list: |110|->|230|->|320|->|240|->NULL

// Output: 320

#include<stdio.h>
#include<stdlib.h>

#define TRUE 0
#define FALSE 1

typedef int BOOL; 

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
        printf("| %d | ->", first->data);
        first = first->next;
    }

    printf("NULL \n");
}

void InsertFirst(PPNODE first, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if((*first) == NULL)        // LL is empty 
    {
        (*first) = newn;
    }
    else                        // LL has atlest 1 node
    {
        newn->next = (*first);
        (*first) = newn;
    }
}

int Maximum(PNODE first)
{
    int iMax = 0;

    if(first == NULL)
    {
        return ;
    }

    iMax = first->data;

    while((first) != NULL)
    {
        if(iMax < (first->data))
        {
            iMax = (first->data);
        }
        first = first->next;
    }

    return iMax;
}

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertFirst(&head, 101);
    InsertFirst(&head, 51);
    InsertFirst(&head, 21);
    InsertFirst(&head, 11);

    Display(head);

    // call functions for problem statements

    iRet = Maximum(head);

    printf("Maximum is : %d\n", iRet);
    
    return 0;
}