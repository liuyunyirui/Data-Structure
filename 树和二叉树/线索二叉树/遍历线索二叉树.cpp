#include<stdio.h>
#include<stdlib.h>
void InOrderTraverse_Thr(BiThrTree T){
  //T指向头结点，头结点的左链lchild指向根节点
  //中序遍历二叉树T的非递归算法，对每个数据元素直接输出
  p = T->lchild;
  while(p != T){
    while(p->Ltag == 0) p = p->lchild;
    printf("%d",p->data);
    while(p->RTag == 1 && p->rchild != T){
      p = p->rchild;
      printf("%d",p->data);
    }
    p = p->rchild;
  }
}
