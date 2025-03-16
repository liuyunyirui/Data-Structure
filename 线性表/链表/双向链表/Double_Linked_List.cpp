#include <stdio.h>
#include <stdlib.h>
//仅需涉及一个方向的指针，双向链表的操作与单链表相同
typedef struct DuLNode{
  int data;
  struct DuLNode *prior;
  struct DuLNode *next;
}DuLNode,*DuLinkList;

//双向链表的插入(带头结点)
bool ListInsert_DuL(DuLinkList *L,int i,int e){
  if(i < 1) return false;
  DuLNode *p = *L;
  int j = 0;
  while(p != NULL && j < i-1){
    p = p->next;
    j++;
  }
  if(p == NULL){
    return false;
  }
  DuLNode *s = (DuLNode*)malloc(sizeof(DuLNode));
  s->next = p->next;
  s->prior = p;
  if(p->next != NULL){
    p->next->prior = s;
  }
  p->next = s;
  s->data = e;
  return true;
}

//双向链表的删除（带头结点）
bool ListDelete_DuL(DuLinkList *L,int i){
  if(i < 1) return false;
  DuLNode *current = *L;
  int j = 0;
  while(current != NULL && j < i-1){
    current = current->next;
    j++;
  }
  if(current == NULL || current->next == NULL){
    return false;
  }
  DuLNode *target = current->next;
  current->next = target->next;
  if(target->next != NULL){
    target->next->prior = current; 
  }
  free(target);
  return true;
}
