#include <stdio.h>
#include <malloc.h>

#define INF     32767               //定义∞
#define MAXV    100                 //最大顶点个数

typedef char InfoType;
/*-------------------------以下定义邻接矩阵类型---------------------------*/
typedef struct
{
    int no;                         //顶点编号
    InfoType info;                  //顶点信息
}VertexType;                        //顶点类型

typedef struct
{
    int edges[MAXV][MAXV];          //邻接矩阵数组(用一个二维数组存放顶点间关系(边或弧)的数据)
    int n;                          //顶点数
    int e;                          //边数
    VertexType vexs[MAXV];          //存放顶点信息(用一个一维数组存放图中所有顶点数据)
}MatGraph;                          //完整的图邻接矩阵类型

//邻接表表示法-将每个顶点的邻接点串成一个单链表
/*-----------以下定义邻接表类型--------------*/
typedef struct ArcNode
{
    int adjvex;                     //该边的邻接点编号
    struct ArcNode *nextarc;        //指向下一条边的指针
    int weight;                     //该边的相关信息,如权值(用整型表示)
}ArcNode;                           //边结点类型

typedef struct VNode
{
    InfoType info;                  //顶点其他信息
    int cnt;                        //存放顶点入度,仅用于拓扑排序
    ArcNode *firstarc;              //指向第一条边
}VNode;                             //邻接表结点类型

typedef struct
{
    VNode adjlist[MAXV];            //邻接表头结点数组
    int n;                          //图中顶点数
    int e;                          //图中边数
}AdjGraph;                          //完整的图邻接表类型

/*-------------------------邻接矩阵的基本运算算法---------------------------*/
/*------------由边数组A、顶点数n和边数e创建图的邻接矩阵g--------------------*/
void CreateMat(MatGraph &g, int A[MAXV][MAXV], int n, int e)
{
    int i, j;

    g.n = n;
    g.e = e;
    for(i = 0; i < g.n; i++)
        for(j = 0; j < g.n; j++)
            g.edges[i][j] = A[i][j];
}


void DispMat(MatGraph g)//输出邻接矩阵
{
    int i, j;

    for(i = 0; i < g.n; i++)
    {
        for(j = 0; j < g.n; j++)
        {
            if(g.edges[i][j] != INF)
                printf("%4d", g.edges[i][j]);
            else
                printf("%4s", "∞");
        }
        printf("\n");
    }
}

void CreateAdj(AdjGraph *&G, int A[MAXV][MAXV], int n, int e)//创建邻接表
{
    int i, j;
    ArcNode *p;

    G = (AdjGraph *)malloc(sizeof(AdjGraph));
    for(i = 0; i < n; i++)                              //给邻接表中所有头结点的指针域置初值NULL
    {
        G->adjlist[i].firstarc = NULL;
    }

    for(i = 0; i < n; i++)                              //检查邻接矩阵中的每个元素
    {
        for(j = n - 1; j >= 0; j--)
        {
            if(A[i][j] != 0 && A[i][j] != INF)          //存在一条边
            {
                p = (ArcNode *)malloc(sizeof(ArcNode)); //创建一个结点p
                p->adjvex = j;                          //邻接点编号
                p->weight = A[i][j];                    //边的权重
                p->nextarc = G->adjlist[i].firstarc;    //采用头插法插入结点p
                G->adjlist[i].firstarc = p;
            }
        }
    }
    G->n = n;
    G->e = e;
}


void DispAdj(AdjGraph *G)//输出邻接表
{
    ArcNode *p;

    for(int i = 0; i < G->n; i++)
    {
        p = G->adjlist[i].firstarc;
        printf("顶点%d: ", i);
        while(p != NULL)
        {
            printf("%3d[%d]->", p->adjvex, p->weight);  //邻接点编号[权重]
            p = p->nextarc;
        }
        printf("∧\n");
    }
}


void DestroyAdj(AdjGraph *&G)//销毁邻接表
{
    ArcNode *pre, *p;

    for(int i = 0; i < G->n; i++)
    {
        pre = G->adjlist[i].firstarc;                   //pre指向第i个单链表的首结点
        if(pre != NULL)
        {
            p = pre->nextarc;
            while(p != NULL)                            //释放第i个单链表的所有边结点
            {
                free(pre);
                pre = p;
                p = p->nextarc;
            }
            free(pre);
        }
    }
    free(G);                                            //释放头结点数组
}

int main(void)
{
    MatGraph g;
    AdjGraph *G;
    int n = 6;                                  //图中的顶点数
    int e = 10;                                 //图中的边数
    int A[MAXV][MAXV] = {
        {0, 5, INF, 7, INF, INF}, {INF, 0, 4, INF, INF, INF},
        {8, INF, 0, INF, INF, 9}, {INF, INF, 5, 0, INF, 6},
        {INF, INF, INF, 5, 0, INF}, {3, INF, INF, INF, 1, 0}
    };

    CreateMat(g, A, n, e);
    printf("邻接矩阵:\n");
    DispMat(g);

    CreateAdj(G, A, n, e);
    printf("邻接表:\n");
    DispAdj(G);
    printf("\n");
    printf("销毁\n");
    DestroyAdj(G);

    return 0;
}
