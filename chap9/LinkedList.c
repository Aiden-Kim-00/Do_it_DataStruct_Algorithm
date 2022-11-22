#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "LinkedList.h"

// list->head는 머리노드를 가리키는 포인터
// list->head->next 는 머리노드 다음 노드를 가리키는 포인터




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
    list->head=list->crnt=AllocNode();
    SetNode(list->head,x,ptr);  //파라미터(데이터를 넣을 Node, 넣을 데이터, 넣을 next주소)
}

void InserRear(List *list, const Member *x)
{
    if(list->head==NULL)
    {
        InsertFront(list,x);
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

void RemoveFront(List *list)
{
    if(list->head != NULL){
        Node *ptr = list->head->next;
        free(list->head);
        list->head = ptr;
    }
}

void RemoveRear(List *list){
    
}

void RemoveCurrent(List *list);

void Clear(List *list);

void PrintCurrent(const List *list);

void PrintLnCurrent(const List *list);

void Print(const List *list);

void Terminate(List *list);
