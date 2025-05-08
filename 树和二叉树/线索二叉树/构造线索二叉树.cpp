#include<stdio.h>
#include<stdlib.h>

//二叉树的二叉线索存储表示
typedef struct BiThrNode{
  int data;
  struct BiThrNode *lchild,*rchild;
  int LTag,RTag;
}BiThrNode,*BiThrTree;

BiThrTree pre = NULL;//指向刚刚访问的结点

//对树中任意一个以结点p为根的子树中序线索化
void InThreading(BiThrTree p){
  if(p){//p结点当然不能为空
    InThreading(p->lchild); //递归左子树

    //处理当前结点前驱
    if(!p->lchild){ //p的左子树为空
      p->LTag = 1;
      p->lchild = pre;//左孩子指向前驱
    }
    else p->LTag = 0;

    //处理前一个结点(pre)的后继
    if(pre != NULL){
      if(!pre->rchild){ //pre的右孩子为空
        pre->RTag = 1; 
        pre->rchild = p;
      }
      else pre->RTag = 0;
    }
    pre = p; //更新前驱指针
    
    InThreading(p->rchild); //递归右子树
  }
}

// 封装函数（解决初始pre为空的问题）
void CreateInThread(BiThrTree T) {
    if (T != NULL) {
        InThreading(T);
        // 处理最后一个节点的右线索
        if (pre->rchild == NULL) {
            pre->RTag = 1;
        }
    }
}

### 执行流程示例（树结构：A(B,C)）
```
      A
     / \
    B   C
```

| 步骤 | 当前节点 | pre节点 | 操作                                 |
|------|----------|---------|--------------------------------------|
| 1    | B        | NULL    | B的左线索设为NULL(LTag=1)            |
| 2    | B        | B       | 更新pre=B                            |
| 3    | A        | B       | B的右线索指向A(RTag=1)               |
| 4    | A        | A       | A的左线索保持LTag=0（有真实左孩子）  |
| 5    | C        | A       | A的右线索设为C(RTag=1)               |
| 6    | C        | C       | C的右线索标记为1（无真实右孩子）     |

---

### 线索化结果验证
| 节点 | LTag | lchild | RTag | rchild |
|------|------|--------|------|--------|
| B    | 1    | NULL   | 1    | A      |
| A    | 0    | B      | 0    | C      |
| C    | 1    | A      | 1    | NULL   |

---
