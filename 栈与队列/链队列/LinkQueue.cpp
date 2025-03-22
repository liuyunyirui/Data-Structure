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

//初始化(带头结点)
bool InitQueue(LinkQueue *Q){
  Q->front = Q->rear = (QNode*)malloc(sizeof(QNode));
  Q->front->next = Q->rear->next = NULL;
  return true;
}

//入队
bool EnQueue(LinkQueue *Q,int e){
  QNode *p = (QNode*)mallc(sizeof(QNode));
  p->data = e;
  p->next = NULL;
  Q->rear->next = p;
  Q->rear = p;
  return true;
}

//出队

int main(){
  LinkQueue Q;
  InitQueue(&Q);
} 


