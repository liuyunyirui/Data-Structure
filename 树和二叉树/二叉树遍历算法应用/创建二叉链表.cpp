#include<stdio.h>
#include<stdlib.h>

// 链式存储结构（结点指针实现）
typedef struct BiTNode {
    char data;                   // 结点数据
    struct BiTNode *lchild;     // 左孩子指针
    struct BiTNode *rchild;     // 右孩子指针
} BiTNode, *BiTree;  // BiTNode 是结点类型，BiTree 是指向结点的指针类型


//按照先序遍历的顺序建立二叉链表
void PreCreateBiTree(BiTree *T){
  char ch;
  scanf(" %c",&ch);
  if(ch == '#') {
    *T = NULL; //ch如果是“＃”，表明二叉树为空树
  }
  else{
    *T = (BiTNode*)malloc(sizeof(BiTNode));
    (*T)->data = ch;
    PreCreateBiTree(&((*T)->lchild));
    PreCreateBiTree(&((*T)->rchild));
  }

//按照中序遍历的顺序建立二叉链表
void MidCreateBiTree(BiTree *T){
  char ch;
  scanf(" %c",&ch);
  if(ch == '#') {
    *T = NULL; //ch如果是“＃”，表明二叉树为空树
  }
  else{
    *T = (BiTNode*)malloc(sizeof(BiTNode));
    MidCreateBiTree(&((*T)->lchild));
    (*T)->data = ch;
    MidCreateBiTree(&((*T)->rchild));
  } 
}

//按照后序遍历的顺序建立二叉链表
void BehindCreateBiTree(BiTree *T){
  char ch;
  scanf(" %c",&ch);
  if(ch == '#') {
    *T = NULL; //ch如果是“＃”，表明二叉树为空树
  }
  else{
    *T = (BiTNode*)malloc(sizeof(BiTNode));
    BehindCreateBiTree(&((*T)->lchild));
    BehindCreateBiTree(&((*T)->rchild));
    (*T)->data = ch;
  }
}

int main() {
    BiTree T = NULL;
    printf("请选择创建方式（1-前序 2-中序 3-后序）: ");
    int choice;
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            PreCreateBiTree(&T);
            break;
        case 2:
            MidCreateBiTree(&T);
            break;
        case 3:
            BehindCreateBiTree(&T);
            break;
        default:
            printf("无效选择！\n");
            return 1;
    }
    
    // 此处可添加遍历或释放内存的代码
    return 0;
}
