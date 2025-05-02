#include<stdio.h>
//顺序存储结构
＃define MAXTSIZE 100
typedef int SqBiTree[MAXTSIZE];
SqBiTree bt;

//链式存储结构
typedef struct BiTNode{
  int data;
  struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

int main(){
  ...
}
