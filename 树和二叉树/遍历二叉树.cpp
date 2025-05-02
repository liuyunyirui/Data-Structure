#include<stdio.h>
#include<stdlib.h>  
#define MAXSIZE 100
typedef struct{
  BiTree *base;
  BiTree *top;
  int stacksize; //栈可用最大容量
}SqStack;

typedef struct BiTNode{
  int data;
  struct BiTNode *lchild,*rchild; 
}BiTNode,*BiTree;

//初始化一个顺序栈
bool InitStack(SqStack *S){
  S->base = (BiTree*)malloc(sizeof(BiTree) * MAXSIZE);
  if(S->base == NULL) return false;
  S->top = S->base;
  S->stacksize = MAXSIZE;
  return true;
}

//访问结点
void visit(BiTree T){
  printf("%d",T->data);
}

//先序遍历
void PreOrder(BiTree T){
  if(T != NULL){
    visit(T);
    PreOrder(T->lchild);
    PreOrder(T->rchild);
  }
}

//中序遍历
void InOrder(BiTree T){
  if(T != NULL){
    InOrder(T->lchild);
    visit(T);
    InOrder(T->rchild);
  }
}

//后序遍历
void PostOrder(BiTree T){
  if(T != NULL){
    PostOrder(T->lchild);
    PostOrder(T->rchild);
    visit(T);
  }
}

//销毁二叉树
void DestroyTree(BiTree T){
  if(T != NULL){
    DestroyTree(T->lchild);
    DestroyTree(T->rchild);
    free(T);
  }
}

bool StrackEmpty(SqStack *S){
  return (S->top == S->base);
}

bool Push(Sqstack *S,BiTree e){
  if(S->top - S->base == S->stacksize) return false;
  *(S->top) = e;
  S->top++;
  return true;
}

bool Pop(SqStack *S,BiTree *e){
  if(StackEmpty(S)) return false;
  S->top--;
  *e = *(S->top)；
  return true;
}

//先序遍历的非递归算法
void

//中序遍历的非递归算法
void InOrderNonRecursive(BiTree T){
  SqStack S;
  InitStack(&S);
  BiTree p = T;
  BiTree q;
  while(p || !StackEmpty(&S)){
    if(p != NULL){
      Push(&S,p);
      p = p->lchild;
    }
    else{
      Pop(&S,&q);
      printf("%d",q->data);
      p = q->rchild;
    }
  }
}

int main(){
  BiTree root = (BiTree)malloc(sizeof(BiTNode));
  root->data = 1;
  root->lchild = (BiTree)malloc(sizeof(BiTNode));
  root->rchild = (BiTree)malloc(sizeof(BiTNode));

  root->lchild->data = 2;
  root->lchild->lchild = NULL;
  root->lchild->rchild = NULL;

  root->rchild->data = 3;
  root->rchild->lchild = NULL;
  root->rchild->rchild = NULL;

  printf("先序遍历: ");
  PreOrder(root);  // 输出 1 2 3

  printf("\n中序遍历: ");
  InOrder(root);   // 输出 2 1 3

  printf("\n后序遍历: ");
  PostOrder(root); // 输出 2 3 1

  DestroyTree(root);
  return 0;
}
