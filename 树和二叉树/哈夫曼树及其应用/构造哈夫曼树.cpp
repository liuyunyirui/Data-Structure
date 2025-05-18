#include<stdio.h>
#include<stdlib.h>
typedef struct{
  int weight; //结点的权值
  int parent,lchild,rchild;  //双亲，左孩子，右孩子的下标
}HTNode,*HuffmanTree;

void Select(HuffmanTree HT,int k,int *s1,int *s2){
  int min1 = 1;
  int min2 = 1;
  for(int i = 1;i <= k;i++){
    if(HT[i].parent == 0){
      if(min1 == -1 || HT[i].weight < HT[min1].weight){
        min1 = i;
      }
    }
  }
  for(int i = 1;i <= k;i++){
    if(HT[i].parent == 0 && i != min1){
      if(min2 == -1 || HT[i].weight < HT[min2].weight){
        min2 = i;
      }
    }
  }
}

//n个叶子结点
bool CreateHuffmanTree(HuffmanTree *HT,int n){
  if(n <= 1) return false;
  m = 2 * n  - 1; //n个叶子结点的哈夫曼树共有2n－1个结点
  HT = (HTNode*)malloc(sizeof(HTNode)*(m+1)); //从1号单元开始用，所以需要m+1个单元，HT[m]表示根结点
  for(i = 1;i <= m;i++){ //将1～m号单元中的双亲，左孩子，右孩子的下标都初始化为0
    HT[i].parent = 0;
    HT[i].lchild = 0;
    HT[i].rchild = 0;
  }
  for(i = 1;i <= n;i++){
    scanf("%d",&(HT[i].weight));  //输入前n个单元中叶子结点的权值
  }
  /*---------------初始化结束----------------*/

  for(i = n + 1;i <= m;i++){ 
    //每两个结点构造一次，一共需要构造n-1次
    Select(*HT,i - 1,s1,s2); //在HT[k](1<=k<=i-1)中选择两个其双亲域为0且权值最小的结点，并返回它们在HT中的下标s1和s2
    HT[s1].parent = i;
    HT[s2].parent = i; //将s1和s2的双亲域由0改1
    HT[i].lchild = s1;
    HT[i].rchild = s2; //s1与s2分别作为i的左右孩子
    HT[i].weight = HT[s1].weight + HT[s2].weight; 双亲i的权值等于左右孩子权值的和
  }
}
