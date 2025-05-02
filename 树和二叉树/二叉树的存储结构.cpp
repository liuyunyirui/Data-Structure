#include <stdio.h>

// 顺序存储结构（数组实现）
#define MAXTSIZE 100     // 定义最大容量
typedef int SqBiTree[MAXTSIZE];  // 定义顺序存储的二叉树类型
SqBiTree bt;  // 声明一个全局顺序二叉树

// 链式存储结构（结点指针实现）
typedef struct BiTNode {
    int data;                   // 结点数据
    struct BiTNode *lchild;     // 左孩子指针
    struct BiTNode *rchild;     // 右孩子指针
} BiTNode, *BiTree;  // BiTNode 是结点类型，BiTree 是指向结点的指针类型

int main() {
    // 示例：初始化链式二叉树
    BiTree root = NULL;  // 定义一个空树
    return 0;
}
