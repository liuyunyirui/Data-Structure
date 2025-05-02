//先序遍历
void PreOrder(BiTree T){
  if(T != NULL){
    visit(T);
    PreOrder(T->lchild);
    PreOrder(T->rchild);
  }
}

//中序遍历
void InOrder(BiTree T){
  if(T != NULL){
    InOrder(T->lchild);
    visit(T);
    InOrder(T->rchild);
  }
}

//后序遍历
void PostOrder(BiTree T){
  if(T != NULL){
    PostOrder(T->lchild);
    PostOrder(T->rchile);
    visit(T);
  }
}
