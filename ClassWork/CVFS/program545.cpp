///////////////////////////////////////////////////////////////////////////////////////
//
//  CUSTOMIZED VIRTUAL FILE SYSTEM PROJECT
//
///////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////
//
//  Header File Inclusion
//
///////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdbool.h>
#include<string.h>

///////////////////////////////////////////////////////////////////////////////////////
//
//  User Defined MACROS
//
///////////////////////////////////////////////////////////////////////////////////////

// Maximum file size that we allow in the project
#define MAXFILESIZE 50

// Maximum No of files that we allow to open in project
#define MAXOPENFILES 20

// Maximum iNodes we allow in project
#define MAXINODE 5

// Permissions
#define READ 1
#define WRITE 2
#define EXECUTE 4

// lseek() functions self defined
#define START 0
#define CURRENT 1
#define END 2

// To flag success
#define EXECUTE_SUCCESS 0

///////////////////////////////////////////////////////////////////////////////////////
//
//  User Defined Structures
//
///////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////
//
//  Structure Name :    BootBlock
//  Description :       Hold the information to boot the OS
//
///////////////////////////////////////////////////////////////////////////////////////

struct BootBlock
{
    char Information[100];
};

///////////////////////////////////////////////////////////////////////////////////////
//
//  Structure Name :    SuperBlock
//  Description :       Hold the information about the file system
//
///////////////////////////////////////////////////////////////////////////////////////

struct SuperBlock
{
    int TotalInodes;
    int FreeInodes;
};

///////////////////////////////////////////////////////////////////////////////////////
//
//  Structure Name :    Inode
//  Description :       Hold the information about the file
//
///////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
struct Inode
{
    char FileName[20];
    int InodeNumber;
    int FileSize;
    int ActualFileSize;
    int ReferenceCount;
    int Permission;
    char * Buffer;
    struct Inode * next;
};

typedef struct Inode INODE;
typedef struct Inode * PINODE;
typedef struct Inode * * PPINODE;

///////////////////////////////////////////////////////////////////////////////////////
//
//  Structure Name :    FileTable
//  Description :       Hold the information about the opened file
//
///////////////////////////////////////////////////////////////////////////////////////

struct FileTable
{
    int ReadOffset;
    int WriteOffset;
    int Mode;                               // mode like read, write and both
    PINODE ptrinode;
};

typedef struct FileTable FILETABLE;
typedef struct FileTable * PFILETABLE;

///////////////////////////////////////////////////////////////////////////////////////
//
//  Structure Name :    UAREA
//  Description :       Hold the information about the process file
//
///////////////////////////////////////////////////////////////////////////////////////

struct UAREA
{
    char ProcessName[20];                   // .exe name as it becomes process(dummy)
    PFILETABLE UFDT[MAXOPENFILES];          // user file descriptor table and it is an pointer array
};

///////////////////////////////////////////////////////////////////////////////////////
//
//  Global variables or objects used in project
//
///////////////////////////////////////////////////////////////////////////////////////

BootBlock bootobj;
SuperBlock superobj;
UAREA uareaobj;

PINODE head = NULL;

///////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InitialiseUAREA 
//  Description :   It is used to initialise UAREA members
//  Author :        Krishna Govindrav Hitnalikar
//  Date :          13/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////

void InitialiseUAREA()
{
    strcpy(uareaobj.ProcessName, "Myexe");

    int i = 0;

    for(i = 0; i < MAXOPENFILES; i++)
    {
        uareaobj.UFDT[i] = NULL;            // to avoide segmentation fault
    }

    printf("Marvellous CVFS : UAREA gets initialised successfully\n");
}

///////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InitialiseSuperBlock
//  Description :   It is used to initialise SuperBlock members
//  Author :        Krishna Govindrav Hitnalikar
//  Date :          13/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////

void InitialiseSuperBlock()
{
    superobj.TotalInodes = MAXINODE;
    superobj.FreeInodes = MAXINODE;

    printf("Marvellous CVFS : Super block gets initialised successfully\n");
}

///////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : CreateDILB
//  Description :   It is used to create linked-list of Inodes
//  Author :        Krishna Govindrav Hitnalikar
//  Date :          13/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////

void CreateDILB()
{
    int i = 1;
    PINODE newn =  NULL;
    PINODE temp = head;

    for(i = 1; i <= MAXINODE; i++)
    {
        newn = (PINODE)malloc(sizeof(INODE));

        strcpy(newn->FileName, "\0");
        newn->InodeNumber = i;
        newn->FileSize = 0;
        newn->ActualFileSize = 0;
        newn->ReferenceCount = 0;
        newn->Permission = 0;
        newn->Buffer = NULL;
        newn->next = NULL;

        if(temp == NULL)                    // LL is empty
        {
            head = newn;
            temp = head;
        }
        else                                // LL contains atleast 1 node
        {
            temp->next = newn;
            temp = temp->next;
        }
    }

    printf("Marvellous CVFS : DILB gets created successfully\n");
}

///////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : StartAuxillaryDataInitialisation
//  Description :   It is used to call all such functions which are which 
//                  are used to initialise auxillary data
//  Author :        Krishna Govindrav Hitnalikar
//  Date :          13/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////

void StartAuxillaryDataInitialisation()
{
    strcpy(bootobj.Information, "Booting Process of Marvellous CVFS is done");

    printf("%s\n", bootobj.Information);

    printf("\n");

    InitialiseSuperBlock();

    CreateDILB();

    InitialiseUAREA();

    printf("Marvellous CVFS : Auxillary data initialised successfully\n");
}

///////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DisplayHelp
//  Description :   It is used to display help page 
//  Author :        Krishna Govindrav Hitnalikar
//  Date :          14/01/2026
//
///////////////////////////////////////////////////////////////////////////////////////

void DisplayHelp()
{
    printf("--------------------------------------------------------------\n");
    printf("----------------- Marvellous CVFS Help Page ------------------\n");
    printf("--------------------------------------------------------------\n");

    printf("man     : It is used to display manual page\n");
    printf("clear   : It is used to clear the terminal\n");
    printf("creat   : It is used to create new file\n");
    printf("write   : It is used to write the data into th file\n");
    printf("read    : It is used to read the data from the file\n");
    printf("stat    : It is used to display statistical information\n");
    printf("unlink  : It is used to delete the file\n");
    printf("exit    : It is used to terminate Marvellous CVFS\n");

    printf("--------------------------------------------------------------\n");
}

///////////////////////////////////////////////////////////////////////////////////////
//
//  Entrypoint Function of the project
//
///////////////////////////////////////////////////////////////////////////////////////

int main()
{
    char str[80] = {'\0'};
    char Command[5][20] = {{'\0'}};
    int iCount = 0;

    StartAuxillaryDataInitialisation();

    printf("\n");

    printf("--------------------------------------------------------------\n");
    printf("------------ Marvellous CVFS started successfully ------------\n");
    printf("--------------------------------------------------------------\n");

    // Infinite Listening Shell
    while(1)
    {
        fflush(stdin);

        strcpy(str, "");

        printf("\n Marvellous CVFS : > ");
        fgets(str, sizeof(str), stdin);

        iCount = sscanf(str, "%s %s %s %s %s", Command[0], Command[1], Command[2], Command[3], Command[4]);    // tokenization

        fflush(stdin);

        if(iCount == 1)
        {
            if(strcmp("exit", Command[0]) == 0)         // Imp
            {
                printf("Thank you for using Marvellous CVFS\n");
                printf("Deallocating all the allocated resources\n");

                break;
            }
            else if(strcmp("ls", Command[0]) == 0)
            {
                printf("Inside ls\n");
            }
            else if(strcmp("help", Command[0]) == 0)
            {
                DisplayHelp();
            }

        }// End of if 1 
        else if(iCount == 2)
        {

        }// End of else if 2
        else if(iCount == 3)
        {

        }// End of else if 3 
        else if(iCount == 4)
        {

        }// End of else if 4 
        else
        {
            printf("Command not found\n");
            printf("Please refer help option to get more information\n");
        }// End of else
    }// End of while

    return 0;
}// End of main