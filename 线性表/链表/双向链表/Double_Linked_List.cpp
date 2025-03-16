#include<stdio.h>
#include <iostream>
#include <stdlib.h>
//仅需涉及一个方向的指针，双向链表的操作与单链表相同
typedef struct DuLNode
{
  int data;
  struct DuLNode *prior;
  struct DuLNode *next;
}DuLNode,*DuLinkList;

//双向链表的插入(带头结点)
bool ListInsert_DuL(DuLinkList *L,int i,int e){
  DuLNode *p = *L;
  int j = 0;
  while(p-> next != NULL && j < i-1){
    p = p->next;
    j++;
  }
  if(p == NULL && j > i-1){
    return false;
  }
  DuLNode *s = (DuLNode*)malloc(sizeof(DuLNoe));
  s->next = p->next;
  s->prior = p;
  p->next->prior = s;
  p->next = s;
  s->data = e;
  return true;
}

//双向链表的删除（带头结点）
bool ListDelete_DuL(DuLinkList *L,int i){
  DuLNode *p = *L;
  int j = 0;
  whil->next != NULL && j < i-1){
    p = p->next;
    j++;
  }
  if(p == NULL && j > i-1){
    return false;
  }
  p->next = p->next->next;
  p->next->next->prior = p;
  free(p->next);
  return true;
}
