// 5. Write a program which return smallest element from singly linear linked list.

// Function Prototype :

// int Minimum(PNODE Head);

// Input linked list: |110|->|230|->|20|->|2401->|1640|->NULL

// Output: 20

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

int Minimum(PNODE first)
{
    int iMin = 0;

    if(first == NULL)
    {
        return -1;
    }

    iMin = first->data;

    while((first) != NULL)
    {
        if(iMin > (first->data))
        {
            iMin = (first->data);
        }
        first = first->next;
    }

    return iMin;
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

    iRet = Minimum(head);

    if(iRet == -1)
    {
        printf("Linked list is empty\n");
    }
    else
    {
        printf("Minimum is : %d\n", iRet);
    }
    
    return 0;
}