#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "LinkedList.h"

static Node *AllocNode(void)
{
    return calloc(1,sizeof(Node));
}

static void SetNode(Node *n, const Member *x, const Node *next)
{
    n->data = *x;
    n->next = next;
}

void Initialize(List *list)
{
    list->head = NULL;
    list->crnt = NULL;
}

Node *search(List *list, const Member *x, int compare(const Member *x, const Member *y))
{
    Node *ptr = list->head;
    while(&ptr!= NULL){
        if(compare(&ptr->data,x)==0){
            list->crnt=ptr;
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
}

void InsertFront(List *list, const Member *x)
{
    Node *ptr = list->head;
    list->head = list->crnt = AllocNode();
    SetNode(list->head,x,ptr);
}

void InserRear(List *list, const Member *x)
{
    if(list->head==NULL)
    {
        InsertFront(list->head,x);
    }
    else{
        Node *ptr = list->head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = list->crnt = AllocNode();
        SetNode(ptr->next,x,NULL);
    }
}

void RemoveFront(List *list);

void RemoveRear(List *list);

void RemoveCurrent(List *list);

void Clear(List *list);

void PrintCurrent(const List *list);

void PrintLnCurrent(const List *list);

void Print(cosnt List *list);

void Terminate(List *list);

#endif