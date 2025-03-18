#include<stdio.h>
#include<stdlid.h>
typedef struct{
  int data;
  struct StackNode *next; 
}StackNode,*LinkStack;

//初始化
bool InitStack(LinkStack *S){
  S = NULL;
  return true;
}

//入栈
bool Push(LinkStack *S)

int main(){
  StackNode S;
  InitStack(&S);
}
