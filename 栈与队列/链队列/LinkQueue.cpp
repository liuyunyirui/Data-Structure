#include<stdio.h>
#include<stdlib.h>
typedef struct QNode{
  int data;
  struct QNode *next;
}QNode,*QueuePtr;

typedef struct{
  QNode *front;
  QNode *rear;
}LinkQueue;

//初始化
bool InitQueue(LinkQueue *Q){
  Q->front = Q->rear = (*QNode)malloc(sizeof(QNode));
}



