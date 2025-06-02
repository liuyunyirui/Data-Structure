#include<stdio.h>
#include<stdlib.h>

#define MaxInt 32767  //表示极大值
#define MVNum 100  //最大顶点数
typedef char VerTexType;  //假设顶点的数据类型为字符型
typedef int ArcType;  //假设边的权值类型为整型
typedef struct{
  VerTexType vexs[MVNum];  //顶点表
  ArcType arcs[MVNum][MVNum];  //领接矩阵
  int vexnum,arcnm; //图的顶点数和边数
}AMGraph;

//采用领接矩阵表示法创建无向网
bool createUDN(AMGraph *G){
  scanf("%d",&(G->vexnum));  //输入总顶点数
  scanf("%d",&(G->arcnum));  //输入总边数
  for(int i = 0; i < G->vexnum; i++){
    scanf(" %c", &(G->vexs[i]));  //依次输入点的信息
  }
  for(int i = 0; i < G->vexnum; i++){
    for(int j = 0; j < G->vexnum; j++){
      G->arcs[i][j] = MaxInt;  //初始化领接矩阵，边的权值均置为极大值MaxInt
    }
  }
  for(int i = 0;i < G->arcnum; i++){  //构造领接矩阵
    int v1,v2,w; //顶点v1,v2和权值w
    scanf("%c %c %d",&v1,&v2,&w);  //输入一条边依附的顶点及权值
    i = LocateVex(G,v1);
    j = LocateVex(G,v2); //确定v1,v2在顶点表中的位置
    G->arcs[i][j] = w;  //边<v1,v2>的权值置为w
    G->arcs[j][i] = G.arcs[i][j];  //置<v1,v2>的对称边<v2,v1>的权值为w
  }
  return true;
}

int LocateVex(AMGraph *G, VerTexType v){
  for(int i = 0; i < G->vexnum; i++){
    if(G->vexs[i] == v){
      return i;
    }
  }
  return -1;  //未找到
}

/*
输入顶点数和边数: 4 5
输入4个顶点: A B C D
输入5条边(格式: 顶点1 顶点2 权值):
A B 2
A C 5
B C 1
B D 3
C D 4

邻接矩阵:
    A   B   C   D   
A | 0   2   5   INF 
B | 2   0   1   3   
C | 5   1   0   4   
D | INF 3   4   0
*/
