#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "LinkedList.h"

// list->head는 머리노드를 가리키는 포인터
// list->head->next 는 머리노드 다음 노드를 가리키는 포인터
// list->crnt는 현재 선택한 노드





static Node *AllocNode(void)
{
    return calloc(1,sizeof(Node));
}

static void SetNode(Node *n, const Member *x, Node *next)
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
    if(list->head != NULL){ 
        if((list->head->next)==NULL){   //Node 가 1개인 경우
            RemoveFront(list);
        }
        else{
            Node *ptr = list->head;     //temp역할을 하는 ptr 생성
            Node *pre = ptr;            //ptr을 가리키는 꼬리노드의 하나 이전 노드 pre
            while(ptr->next != NULL){
                pre = ptr;
                ptr = ptr->next;
            }
            pre->next = NULL;           //ptr을 가리키는 pre의 next를 비워주기
            free(ptr);
            list->crnt = pre;
        }
    }
}

void RemoveCurrent(List *list){
    if(list->crnt == list->head){
        RemoveFront(list);
    }
    else{
        Node *ptr = list->head;
        while(ptr->next != list->crnt){
            ptr = ptr->next;
        }
        ptr->next = list->crnt->next;
        free(list->crnt);
        list->crnt = ptr;
    }
}

void Clear(List *list){         //앞에서부터 지우기
    while(list->head != NULL){
        RemoveFront(list);
    }
    list->crnt = NULL;
}

void PrintCurrent(const List *list){
    if(list->crnt == NULL)
    {
        printf("You didn't choose a node\n");
    }
    else{
        PrintMember(&list->crnt->data);
    }
}

void PrintLnCurrent(const List *list){
    PrintCurrent(list);
    putchar('\n');
}

void Print(const List *list){
    if(list->head == NULL){
        puts("There is no Node");
    }
    else{
        Node *ptr = list->head;
        puts("[View all]");
        while(ptr != NULL){
            PrintLnMember(&ptr->data);
            ptr = ptr->next;
        }
    }
}

void Terminate(List *list){
    Clear(list);
}
