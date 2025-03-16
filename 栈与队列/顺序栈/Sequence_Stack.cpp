#include<stdio.h>
#define MAXSIZE 100
typedef struct{
  int *base; 
  int *top;
  int stacksize;
}SqStack;

//初始化
bool InitStack(SqStack *S){
  S.base = (Sqstack*)malloc(sizeof(SqStack) * MAXSIZE);
  if(S.base == NULL){
    return false;
  }
  S.top = S.base;
  S.Stacksize = MAXSIZE;
  return true;
}

//入栈
bool Push(SqStack *S,int e){
  if(S.top - S.base == S.stacksize) return false;
  *(S.top) = e;
  top++;
  return true;
}

//出栈
bool Pop(SqStack *S,int *e){
  if(S.top == S.base) return false; //栈空
  e = *(S.top);
  S.top--;
  return true;
}

//取栈顶元素
int GetTop(SqStack *S){
  if(S.top == S.base) return false;
  return *(S.top-1);
}
