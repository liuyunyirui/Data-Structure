#include<stdio.h>
#include<stdlid.h>
typedef struct{
  int data;
  struct StackNode *next; 
}StackNode,*LinkStack;//*LinkStack是一个结构指针

//初始化
bool InitStack(LinkStack *S){//
  S = NULL;
  return true;
}

//入栈
bool Push(LinkStack *S,int e){
  StackNode *p = (int*)malloc(sizeof(int));
  p->data = e;
  p->next = *S;
  S = p;
  return true; 
}

//出栈
bool Pop(LinkStack *S,int *e){
  if(S == NULL) return false;
  StackNode *p = S;
  *e = S->data;
  S = S->next;
  free(p);
  return true;
}

//取栈顶元素
int GetTop(LinkStack S){
  if(S != NULL){
    return S->data;
  }
}

// 销毁链栈
void DestroyStack(LinkStack* S) {
    StackNode* current = *S;
    while (current != NULL) {
        StackNode* temp = current;
        current = current->next;
        free(temp);
    }
    *S = NULL;  // 头指针置空
}

int main(){
  LinkStack S;
  InitStack(&S);
}
