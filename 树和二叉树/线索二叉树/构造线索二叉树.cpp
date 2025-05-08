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

### 修正后的完整执行流程（中序遍历线索化）

| 步骤 | 当前节点 | 操作                                                                 | pre节点 | 线索设置结果                                                                 |
|------|----------|----------------------------------------------------------------------|---------|------------------------------------------------------------------------------|
| 1    | A        | 递归进入左子树B                                                     | NULL    |                                                                             |
| 2    | B        | 递归进入左子树（空）                                                | NULL    |                                                                             |
| 3    | B        | 处理左线索：B.lchild=NULL → LTag=1，lchild=pre(NULL)                | NULL    | B.LTag=1, B.lchild=NULL                                                     |
| 4    | B        | 更新pre=B                                                           | B       |                                                                             |
| 5    | B        | 递归进入右子树（空）                                                | B       |                                                                             |
| 6    | B        | 返回上层递归到A                                                     | B       |                                                                             |
| 7    | A        | 处理左子树完成，开始处理当前节点A                                   | B       |                                                                             |
| 8    | A        | 处理左线索：A.lchild=B（非空）→ LTag=0                              | B       | A.LTag=0                                                                    |
| 9    | A        | 处理前驱B的右线索：B.rchild=NULL → B.RTag=1，B.rchild=A             | B       | **B.RTag=1, B.rchild=A**                                                    |
| 10   | A        | 更新pre=A                                                           | A       |                                                                             |
| 11   | A        | 递归进入右子树C                                                     | A       |                                                                             |
| 12   | C        | 递归进入左子树（空）                                                | A       |                                                                             |
| 13   | C        | 处理左线索：C.lchild=NULL → LTag=1，lchild=pre(A)                   | A       | **C.LTag=1, C.lchild=A**（关键修正点）                                      |
| 14   | C        | 处理前驱A的右线索：A.rchild=C（非空）→ A.RTag=0                     | A       | A.RTag=0                                                                    |
| 15   | C        | 更新pre=C                                                           | C       |                                                                             |
| 16   | C        | 递归进入右子树（空）                                                | C       |                                                                             |
| 17   | C        | 返回上层递归到A                                                     | C       |                                                                             |
| 18   | A        | 递归完成，返回                                                      | C       |                                                                             |
| 19   | 全局     | 最终处理：C.rchild=NULL → C.RTag=1                                  | C       | **C.RTag=1, C.rchild=NULL**                                                 |

---

### 线索化结果验证
| 节点 | LTag | lchild | RTag | rchild |
|------|------|--------|------|--------|
| B    | 1    | NULL   | 1    | A      |
| A    | 0    | B      | 0    | C      |
| C    | 1    | A      | 1    | NULL   |

---
