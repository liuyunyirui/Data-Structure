#include<stdio.h>
#include<stdlib.h>

#define MVNum 100  //最大顶点数

typedef int VerTexType;
typedef int OtherInfo;

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
  int vexnum,arcnum;  //图的当前顶点数和边数
}ALGraph;

// 查找顶点在顶点数组中的位置
int LocateVex(ALGraph* G, VerTexType v) {
    for (int i = 0; i < G->vexnum; i++) {
        if (G->vertices[i].data == v) {
            return i;
        }
    }
    return -1;  // 未找到
}

//采用领接表表示法，创建无向图G
void CreateUDG(ALGraph *G){
  int i,j,k;
  scanf("%d %d",&(G->vexnum),&(G->arcnum));  //输入总顶点数，总边数
  for(i = 0; i < G->vexnum; i++){  //构造表头结点表
    scanf("%d",&(G->vertices[i].data));  //输入顶点值
    G->vertices[i].firstarc = NULL;  //初始化边指针为空
  }
  for(k = 0; k < G->arcnum; k++){
    int v1,v2;
    scanf("%d %d",&v1,&v2);  //输入一条边依附的两个顶点
    i = LocateVex(G,v1);
    j = LocateVex(G,v2);  //确定v1,v2在G中的位置，即顶点序号
    ArcNode *p1 = (ArcNode *)malloc(sizeof(ArcNode));  //生成一个新的边结点*p1
    p1->adjvex = j;  //该边所指向的顶点的位置为j
    p1->nextarc = G->vertices[i].firstarc; 
    G->vertices[i].firstarc = p1;  //将新结点*p1插入顶点v(i)的边表头部（使用的头插法）  
    ArcNode *p2 = (ArcNode *)malloc(sizeof(ArcNode));  //生成一个新的边结点*p2
    p2->adjvex = i;  //该边所指向的顶点的位置为j
    p2->nextarc = G->vertices[j].firstarc; 
    G->vertices[j].firstarc = p2;  //将新结点*p2插入顶点v(j)的边表头部（使用的头插法） 
  }
}

int main() {
    ALGraph G;
    CreateUDG(&G);
    
    // 测试输出
    printf("\n邻接表结构:\n");
    for (int i = 0; i < G.vexnum; i++) {
        printf("顶点%d: ", G.vertices[i].data);
        ArcNode* p = G.vertices[i].firstarc;
        while (p) {
            printf("->%d", G.vertices[p->adjvex].data);
            p = p->nextarc;
        }
        printf("\n");
    }
    
    return 0;
}
