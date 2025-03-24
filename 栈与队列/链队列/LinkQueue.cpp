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
  QNode *p = (QNode*)malloc(sizeof(QNode));
  if(p == NULL) return false;
  p->data = e;
  p->next = NULL;
  Q->rear->next = p;
  Q->rear = p;
  return true;
}

//出队
bool DeQueue(LinkQueue *Q,int *e){
  if(Q->front->next == NULL){
    return false;
  }
  QNode *p = Q->front->next;
  *e = p->data;
  Q->front->next = p->next;
  if(Q->rear == p){
    Q->rear = Q->front;
  }
  free(p);
  return true;
} 
 
//取队头元素
bool GetHead(LinkQueue *Q,int *e){
  if(Q->front->next != NULL){
    *e = Q->front->next->data;
    return true;
  }
  return false;
}

//销毁队列
void DestroyQueue(LinkQueue *Q){
  QNode *p = Q->front->next;
  while(p != NULL){
    QNode *temp = p;
    p = p->next;
    free(temp);
  }
  free(Q->front);
  Q->front = Q->rear = NULL;
}

int main(){
  LinkQueue Q;
  InitQueue(&Q);
} 


