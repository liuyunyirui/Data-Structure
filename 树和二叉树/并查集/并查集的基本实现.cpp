#include<stdio.h>
#include<stdlib.h>

//数组元素的下标代表元素名
//根结点的数值为结点总数的相反数
//根节点的双亲域为负数

#define SIZE 100
int UFsets[SIZE]; //集合元素数组(双亲指针数组)

//并查集的初始化
void Initial(int S[]){  //s即并查集
  for(int i = 0; i < SIZE; i++){  //刚开始时所有结点均为根结点，构成一个森林
    S[i] = -1;
  }
}

//在并查集S中查找并返回包含元素x的树的根
int Find(int S[],int x){
  while(S[x] >= 0){
    x = S[x];
  }
  return x;
}

//求两个不相交子集合的并集
bool Union(int S[],int Root1,int Root2){
  if(Root1 == Root2){  //要求Root1与Root2是不同的集合
    return false; 
  }
  S[Root2] = Root1;  //将根Root2连接到另一个根Root1下面
}

//改进的Union操作，改进方法就是比较两棵树的元素个数，将小树合并到大树上，避免集合树深度越来越大
bool Union1(int S[],int Root1,int Root2){
  if(Root1 == Root2){  //不能是同一集合
    return false;
  }
  if(S[Root2] > S[Root1]){  //Root2的结点更少
    S[Root1] = S[Root1] + S[Root2];  //计算出结点总数的相反数
    S[Root2] = Root1;  //小树合并到大树
  }
  else{  //Root1的结点数更少
    S[Root2] = S[Root1] + S[Root2];  //累加结点总数的相反数
    S[Root1] = Root2;  //小树合并到大树
  }
  return true;
}

//改进Find操作， 通过压缩路径减少树的深度
int Find1(int S[], int x){
  int root = x;
  while(S[root] >= 0){  //循环找到根  
    root = S[root];
  }
  while(x != root){  //压缩路径(让当前结点及其先祖结点直接指向根结点)
    int parent = S[x];  //保存当前结点的父结点
    S[x] = root;  //x直接挂到根节点的下面
    x = parent;  //处理原父结点
  }
  return root;
}

int main() {
    Initial(UFsets);
    
    // 合并操作
    Union(UFsets, 0, 1);   // 合并元素0和1的集合
    Union(UFsets, 2, 3);   // 合并元素2和3的集合
    Union(UFsets, 0, 2);   // 合并两个大集合
    
    // 查找测试
    printf("0的根: %d\n", Find(UFsets, 0)); // 应输出同一根
    printf("3的根: %d\n", Find(UFsets, 3)); // 应与0的根相同
    
    return 0;
}
