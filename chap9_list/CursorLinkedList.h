#ifndef __CursorLinkedList
#define __CursorLinkedList

#include "Member.h"

#define Null -1

typedef int Index;

typedef struct __node
{
    Member data;
    Index next;   
    Index Dnext;

    /* data */
} Node;

typedef struct {
    Node *n;
    Index head;
    Index max;
    Index deleted;
    Index crnt;
} List;


void Initialize(List *list, int size);

Node *search(List *list, const Member *x, int compare(const Member *x, const Member *y));

void InsertFront(List *list, const Member *x);

void InserRear(List *list, const Member *x);

void RemoveFront(List *list);

void RemoveRear(List *list);

void RemoveCurrent(List *list);

void Clear(List *list);

void PrintCurrent(const List *list);

void PrintLnCurrent(const List *list);

void Print(const List *list);

void Terminate(List *list);

#endif