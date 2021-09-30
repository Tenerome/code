#include<stdio.h>
#include<stdlib.h>
#define MaxVertices 100 //�������100������
#define MaxWeight 32767 //���ڽ�ʱΪ32767�������ʱ�� "��"
#define MAXV 10
#define INF 32767
typedef struct{ //����Ȩ���ڽӾ���ĵĶ���
    char Vertices[MaxVertices];  //������Ϣ������
    int Edge[MaxVertices][MaxVertices]; //�ߵ�Ȩ��Ϣ������
    int numV; //��ǰ�Ķ�����
    int numE; //��ǰ�ı���
}AdjMatrix;

void CreateGraph(AdjMatrix *G) //ͼ�����ɺ���
{ 
    int n,e,vi,vj,w,i,j;
    printf("������ͼ�Ķ������ͱ������Կո�ָ�����");
    scanf("%d%d",&n,&e);
    G->numV=n;G->numE=e;
    for(i=0;i<n;i++) //ͼ�ĳ�ʼ��
        for(j=0;j<n;j++)
            { 
            if(i==j)
                G->Edge[i][j]=0;
            else 
                G->Edge[i][j]=32767;
            }
		printf("������������ֵ(����):");
    for(i=0;i<n;i++)
		 
        for(i=0;i<G->numV;i++) //���������������
        
		{ 
         
      // G->adjlist[i].vertex=getchar(); 
        scanf(" %c",&G->Vertices[i]);
        }
    printf("\n");
    printf("������ߵ���Ϣi,j,w(�Կո�ָ�):");
    for(i=0;i<G->numE;i++)
		
    { 
        
        scanf("%d%d%d",&vi,&vj,&w); 
        //��Ϊ����Ȩֵ��ͼ����w����1
        //��Ϊ��Ȩֵ��ͼ����w�����ӦȨֵ

        G->Edge[vi-1][vj-1]=w;//��
        G->Edge[vj-1][vi-1]=w;//��
        //����ͼ�߱��Գ��ԵĹ��ɣ������٢�ʵ��
        //����ͼ�����д����ʣ����ֻ��Ҫ��
    }
}
void DispGraph(AdjMatrix G) //����ڽӾ������Ϣ
{ 
    int i,j;
    printf("\n����������Ϣ�����ͣ�:\n");
    for(i=0;i<G.numV;i++)
        printf("%8c",G.Vertices[i]);

    printf("\n����ڽӾ���:\n");
    printf("\t");
    for(i=0;i<G.numV;i++)
        printf("%8c",G.Vertices[i]);

    for(i=0;i<G.numV;i++)
    { 
        printf("\n%8d",i+1);
        for(j=0;j<G.numV;j++)
        { 
        if(G.Edge[i][j]==32767) 
        //����֮��������ʱȨֵΪĬ�ϵ�32767�������ʱΪ�˷������ "��"
            printf("%8s", "��");
        else
            printf("%8d",G.Edge[i][j]);
        }
        printf("\n");   
    }
}
void Ppath(int path[][MaxVertices],int i,int j)
{
    int k;
    k=path[i][j];
    if (k==-1)
    {
        return;
    }

    Ppath(path,i,k);
    printf("%d->",k);
    Ppath(path,k,j);
}

void Dispath(int A[][MaxVertices],int path[][MaxVertices],int n)
{
    int i,j;
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            if (A[i][j]==INF)
            {
                if (i!=j)
                {
                    printf("��%d��%dû��·��\n",i,j);
                }
            }
            else
            {
                printf(" ��%d��%d�����·������Ϊ��%d ",i,j,A[0][8]);
                printf("·����%d->",i);

                Ppath(path,i,j);//����i,j֮�仹�������м̽�㣬��ѭ�����ôκ���
                printf("%d\n",j);
            }
        }
    }
}
void Floyd(AdjMatrix *G)
{
    int A[MaxVertices][MaxVertices],path[MaxVertices][MaxVertices];
    int i,j,k;
    //��ʼ��
    for (i=0;i<G->numV;i++)
    {
        for (j=0;j<G->numV;j++)
        {
            A[i][j]=G->Edge[i][j];
            path[i][j]=-1;
        }
    }
//����ѭ����floyd�㷨����
    for (k=0;k<G->numV;k++)
    {
        for (i=0;i<G->numV;i++)
        {
            for (j=0;j<G->numV;j++)
            {
                if (A[i][j]>A[i][k]+A[k][j])
                {
                    A[i][j]=A[i][k]+A[k][j];
                    path[i][j]=k;
                }
            }
        }
    }
    Dispath(A,path,G->numV);//�������
}


int main()
{ 
    AdjMatrix G;
    
    CreateGraph(&G);
    Floyd(&G);
    DispGraph(G);
}