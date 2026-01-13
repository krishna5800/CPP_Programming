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

    InitialiseSuperBlock();

    CreateDILB();

    InitialiseUAREA();

    printf("Marvellous CVFS : Auxillary data initialised successfully\n");
}

///////////////////////////////////////////////////////////////////////////////////////
//
//  Entrypoint Function of the project
//
///////////////////////////////////////////////////////////////////////////////////////

int main()
{
    StartAuxillaryDataInitialisation();

    return 0;
}