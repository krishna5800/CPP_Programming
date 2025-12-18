// 3. Write a program which returns addition of all element from singly linear linked list.

// Function Prototype :

// int Addition(PNODE Head);

// Input linked list: |10|->|20|->|30|->|40|->NULL

// Output: 100

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

    Display(head);

    // call functions for problem statements

    iRet = Addition(head);

    printf("Addition is : %d\n", iRet);
    
    return 0;
}