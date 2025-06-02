#include<stdio.h>
#include<stdlib.h>

#define MVNum 100  //最大顶点数
typedef struct ArcNode{  //边结点
  int adjvex;  //该边所指向的顶点的位置
  struct ArcNode *nextarc;  //指向下一条边的指针
  OtherInfo  info;  //和边相关的信息 
}ArcNode;

typedef struct VNode{  //顶点信息
  VerTexType data;  //顶点的值
  ArcNode *firstarc;  //指向第一条依附该顶点边的指针
}VNode,AdjList[MVNum];  //AdjList表示邻接表类型

typedef struct {  //邻接表
  AdjList vertices;
  int vexnum,arcnum;  //图的当前顶点数和变数
}ALGraph;
