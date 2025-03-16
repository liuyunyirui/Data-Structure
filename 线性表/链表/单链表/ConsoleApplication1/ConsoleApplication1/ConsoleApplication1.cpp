// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include<stdio.h>
#include <iostream>

//单链表的定义
typedef struct LNode {
    int data;
    struct LNode *next;
}LNode,*LinkList;

//初始化一个不带头结点的单链表
bool InitList(LinkList &L) {
    L = NULL;
    return true;
}

//初始化一个带头结点的单链表
bool InitList1(LinkList& L) {
    L = (LNode*)malloc(sizeof(LNode));
    if (L == NULL) {  //分配空间失败
        return false; 
    }
    L->next = NULL;
    return true;
}

//判断一个不带头结点的的单链表是否为空
bool Empty(LinkList &L) {
    if (L == NULL) {
        return true;
    }
    else {
        return false;
    }
}

//判断一个带头结点的的单链表是否为空
bool Empty(LinkList &L) {
    if (L->next == NULL) {
        return true;
    }
    else {
        return false;
    }
}

//带头结点单链表取值
bool GetElem(LinkList L,int i,int &e)
{
    p = L->next; 
    j = 1;
    while(p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    if(p == NULL && j > i)
    {
        return false;
    }
    e = p->data;
    return true;
}

//带头结点的查找
LNode* LocateElem(LinkList L,int e)
{
    p = L->next;//不带头结点删除这一行
    while(p != NULL && p->data != e){
        p = p->next;
    }
    return p;
}

//在第i个位置插入元素e（带头结点）
bool ListInsert(LinkList& L,int i,int e) {
    if (i < 1) {
        return false;
    }
    LNode* p;
    int j = 0;
    p = L;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == NULL) {
        return false;
    }
    LNode* s = (LNode*)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

//在第i个位置插入元素e（不带头结点）
bool ListInsert1(LinkList& L,int i,int e)
{
    if (i < 1) {
        return false;
    }
    if (i == 1) {
        LNode* s = (LNode*)malloc(sizeof(LNode));
        s->data = e;
        s->next = L;
        L = s; //头指针指向新结点
        return true;
    }
    LNode* p;
    int j = 1;
    p = L;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == NULL) {
        return false;
    }
    LNode* s = (LNode*)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

//带头结点的删除单链表的第i个结点
bool ListDelete(LinkList &L,int i){
    LNode* p,q;
    p = L->next;//不带头结点删除这一行
    j = 1;
    while(p != NULL && j < i-1){
        p = p->next;
        j++;
    }
    if(p == NULL && j > i-1){
        return false;
    }
    
}

//后插操作：在p结点之后插入元素e

int main()
{
    LinkList L;
}

