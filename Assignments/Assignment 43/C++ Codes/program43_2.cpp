// 2. Write program which displays all elements which are prime from singly linear linked list.

// Function Prototype:

// int DisplayPrime(PNODE Head);

// Input linked list: |11|->|20|->|17|->|41|->|22|->|89|

// Output: 11 17 41 89

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

// call by value

void Display(PNODE first)
{
    while(first != NULL)
    {
        cout << "| " << first->data << " | " << "-> "; 
        first = first->next;
    }

    cout << "NULL\n";
}

int Count(PNODE first)
{
    int iConut = 0;
    while(first != NULL)
    {
        iConut++;
        first = first->next;
    }

    return iConut;
}

// call by address

void InsertFirst(PPNODE first, int no)
{
    PNODE newn = NULL;

    newn = new NODE;

    newn->data = no;
    newn->next = NULL;

    if((*first) == NULL)                // LL is empty
    {
        (*first) = newn;
    }
    else                                // LL has atleast 1 node
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
            cout << first->data << "\t";
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
    InsertFirst(&head, 10);
    InsertFirst(&head, 6);

    Display(head);
    iRet = Count(head);
    cout << "Count is : " << iRet << "\n";

    cout << "Perfect numbers from LL : \n";
    DisplayPrime(head);

    return 0;
}