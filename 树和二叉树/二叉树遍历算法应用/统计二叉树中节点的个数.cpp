//统计二叉树结点的个数
int NodeCount(BiTree T){
  if(T == NULL){
    return 0;
  } 
  else return NodeCount(T->lchild) + NodeCount(T->rchild)+1;
}
