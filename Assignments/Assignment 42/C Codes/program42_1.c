// 1. Write a program which search first occurrence of particular element from 
// singly linear linked list.
// Function should return position at which element is found.

// Function Prototype:

// int SearchFirstOcc(PNODE Head, int no);

// Input linked list: |10|->|20|->|30|->|40|->|50|->|30|->|70|-> NULL

// Input element: 30

// Output: 3

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

int SearchFirstOcc(PNODE first, int no)
{
    int iCount = 0 ;

    while((first) != NULL)
    {
        iCount++;

        if((first->data) == no)
        {
            return iCount;
            break;
        } 

        first = first->next;
    }
}

int main()
{
    PNODE head = NULL;
    int iValue = 0;
    int iRet = 0;

    InsertFirst(&head, 101);
    InsertFirst(&head, 51);
    InsertFirst(&head, 21);
    InsertFirst(&head, 11);

    Display(head);

    // call functions for problem statements

    printf("Enter number you want to search : \n");
    scanf("%d", &iValue);

    iRet = SearchFirstOcc(head, iValue);

    if(iRet == 0)
    {
        printf("Number is not in linked list");
    }
    else
    {
        printf("Number first occured at position : %d\n",iRet);
    }
    
    return 0;
}