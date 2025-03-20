#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct{
  int *data;
  int front;
  int rear;
}SqQueue;

//初始化
bool InitQueue(SqQueue *Q){
  Q->data = (int*)malloc(sizeof(int)*MAXSIZE);
  if(Q->data == NULL) return false;
  Q->front = Q->rear = 0;
  return true;
}

//求队列长度
int QueueLength(SqQueue Q){
  return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

//入队
bool EnQueue(SqQueue *Q,int e){
  if((Q->rear + 1) % MAXSIZE == Q->front) return false;
  Q->data[Q->rear] = e;
  Q->rear = (Q->rear + 1) % MAXSIZE;
  return true;
}

//出队
bool DeQueue(SqQueue *Q,int *e){
  if(Q->front == Q->rear) return false;
  *e =  Q->data[Q->front];
  Q->front = (Q->front + 1) % MAXSIZE;
  return true;
}

//取队头元素
int GetHead(SqQueue Q){
  if(Q.front == Q.rear) return -1;
  return Q.data[Q.front];
}

//销毁队列
void DestroyQueue(SqQueue *Q) {
      free(Q->data);  // 释放动态数组
      Q->data = NULL; // 指针置空
      Q->front = Q->rear = 0;
  }

int main(){
  SqQueue Q;
  InitQueue(&Q);
  return 0;
}

