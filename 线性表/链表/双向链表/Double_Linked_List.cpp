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

//双向链表的插入
bool ListInsert_DuL(DuLinkList *L,int i,int e){
  
}
