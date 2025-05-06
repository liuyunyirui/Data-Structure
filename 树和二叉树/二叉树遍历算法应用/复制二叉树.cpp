//复制二叉树
void Copy(BiTree T,BiTree *NewT){
  if(T == NULL){
    *NewT = NULL;
  }
  else{
    *NewT = (BiTNode*)malloc(sizeof(BiTNode));
    (*NewT)->data = T->data;
    Copy(T->lchild,&((*NewT)->lchild));
    Copy(T->rchild,&((*NewT)->rchild));
  }
}
