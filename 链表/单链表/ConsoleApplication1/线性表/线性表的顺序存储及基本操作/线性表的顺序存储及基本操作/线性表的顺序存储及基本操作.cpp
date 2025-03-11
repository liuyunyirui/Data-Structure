// 线性表的顺序存储及基本操作.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10 //定义最大长度

typedef struct
{
    int data[MaxSize]; //用静态的数组存放数据元素
    int length; //顺序表的当前长度
}SeqList;    //顺序表的类型定义

//顺序表的动态分配
typedef struct {
    int *data;  //指示动态分配数组的指针
    int max;  //顺序表的最大容量
    int length;  //顺序表的当前长度
}SqList;

void InitList1(SqList &L1)
{
    L1.data = (int*)malloc(MaxSize * sizeof(int));
    L1.length = 0;
    L1.max = MaxSize;
}

//增长动态数组的长度 len表示要扩大多少容量
void IncreaseSize(SqList &L1, int len)
{
    int *p = L1.data;
    L1.data = (int*)malloc((L1.max + len) * sizeof(int));
    for(int i = 0;i < L1.length;i++)
    {
        L1.data[i] = p[i];
    }
    L1.max = L1.max + len;
    free(p);
}

//初始化一个顺序表
void InitList(SeqList &L)
{
    for (int i = 0; i < MaxSize; i++)
    {
        L.data[i] = 0;
    }
    L.length = 0;
}

//在L的位序i插入元素e
bool ListInsert(SeqList& L, int i, int e)
{
    if (i<1 || i>L.length + 1)
    {
        return false;
    }
    if (L.length >= MaxSize)
    {
        return false;
    }
    for (int j = L.length; j >= i; j--)
    {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}

//在L的位序i删除元素，并返回被删除的元素
bool ListDelete(SeqList& L, int i, int& e)
{
    if (i<1 || i>L.length)
    {
        return false;
    }
    for (int j = i; j < L.length; j++)
    {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
}

//按位查找
int GetElem(SeqList L, int i)
{
    return L.data[i - 1];
}

//按值查找第一个等于e的元素，并返回位序
int LocateElem(SeqList L, int e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
        {
            return i+1;
        }
        return 0;
    }
}

int main()
{
    int e;
    SeqList L;
    SqList L1;
    InitList(L);
    for(int i = 0;i < MaxSize-1;i++)
    { 
        scanf_s("输入插入的元素：%d", &e);
        ListInsert(L, i, e);
    }
}


