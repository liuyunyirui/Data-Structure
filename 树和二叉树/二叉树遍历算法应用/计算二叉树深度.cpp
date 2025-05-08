//计算二叉树深度
int Depth(BiTree T){
  if(T == NULL) return 0；
    else{
    m = Depth(T->lchild);
    n = Depth(T->rchild);
    if(m > n) return (m+1);
    else return (n+1);
    }
}
    A
   / \
  B   C
 / \
D   E
| 步骤 | 当前节点 | 调用栈内容（从底到顶）                     | 操作描述                                                                 |
|------|----------|------------------------------------------|--------------------------------------------------------------------------|
| 1    | A        | `Depth(A)`                               | 初始调用，压入 `Depth(A)`                                               |
| 2    | B        | `Depth(A)` → `Depth(B)`                  | 处理A的左子树，压入 `Depth(B)`                                           |
| 3    | D        | `Depth(A)` → `Depth(B)` → `Depth(D)`     | 处理B的左子树，压入 `Depth(D)`                                           |
| 4    | NULL(D左)| `Depth(A)` → `Depth(B)` → `Depth(D)`     | D的左子树为空，返回0                                                     |
| 5    | NULL(D右)| `Depth(A)` → `Depth(B)` → `Depth(D)`     | D的右子树为空，返回0                                                     |
| 6    | D        | `Depth(A)` → `Depth(B)`                  | D的深度为 `max(0,0)+1=1`，返回1，弹出 `Depth(D)`                         |
| 7    | E        | `Depth(A)` → `Depth(B)` → `Depth(E)`     | 处理B的右子树，压入 `Depth(E)`                                           |
| 8    | NULL(E左)| `Depth(A)` → `Depth(B)` → `Depth(E)`     | E的左子树为空，返回0                                                     |
| 9    | NULL(E右)| `Depth(A)` → `Depth(B)` → `Depth(E)`     | E的右子树为空，返回0                                                     |
| 10   | E        | `Depth(A)` → `Depth(B)`                  | E的深度为 `max(0,0)+1=1`，返回1，弹出 `Depth(E)`                         |
| 11   | B        | `Depth(A)`                               | B的深度为 `max(1,1)+1=2`，返回2，弹出 `Depth(B)`                         |
| 12   | C        | `Depth(A)` → `Depth(C)`                  | 处理A的右子树，压入 `Depth(C)`                                           |
| 13   | NULL(C左)| `Depth(A)` → `Depth(C)`                  | C的左子树为空，返回0                                                     |
| 14   | NULL(C右)| `Depth(A)` → `Depth(C)`                  | C的右子树为空，返回0                                                     |
| 15   | C        | `Depth(A)`                               | C的深度为 `max(0,0)+1=1`，返回1，弹出 `Depth(C)`                         |
| 16   | A        | 空栈                                     | A的深度为 `max(2,1)+1=3`，返回3，弹出 `Depth(A)`                         |

---
