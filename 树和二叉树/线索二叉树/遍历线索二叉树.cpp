#include<stdio.h>
#include<stdlib.h>

typedef struct BiThrNode {
    int data;
    struct BiThrNode *lchild, *rchild;
    PointerTag LTag, RTag;    // 左右指针标记
} BiThrNode, *BiThrTree;

void InOrderTraverse_Thr(BiThrTree T){
  //T指向头结点，头结点的左链lchild指向根节点
  //中序遍历二叉树T的非递归算法，对每个数据元素直接输出
  BiThrNode *p = T->lchild; //变量声明，并指向根结点
  while(p != T){ //空树或遍历结束时，p==T
    //找到最左结点
    while(p->LTag == 0){
      p = p->lchild; 
    } 
    printf("%d ",p->data); //访问其左子树为空的结点（树的最左结点）
    //右线索为1，右孩子为后继。如果p的右孩子为根结点，说明他是最后的结点
    while(p->RTag == 1 && p->rchild != T){ 
      p = p->rchild; 
      printf("%d ",p->data);
    }
    p = p->rchild;//变为后继结点继续往后访问
  }
}
/*
### 示例验证：
假设有如下线索二叉树结构：
```
      Head
       |
       1
     /   \
    2     3
   / \   /
  4   5 6
```
中序遍历结果为：4 → 2 → 5 → 1 → 6 → 3

**遍历过程**：
1. p从Head->lchild（结点1）开始
2. 找到最左结点4（LTag全为LINK）
3. 输出4
4. 结点4的RTag为THREAD，沿线索访问结点2
5. 输出2
6. 结点2的RTag为LINK，转向右子树5
7. 重复上述过程直到回到Head
*/
