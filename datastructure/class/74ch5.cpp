#include<iostream>
#include<stdio.h>
#include<malloc.h>
#define MaxSize 100
#define MaxWidth 40
typedef char ElemType;
typedef struct node
{
    ElemType data;//����Ԫ��
    struct node *lchild;//ָ������
    struct node *rchild;//ָ���Һ���
}BTNode;
BTNode *create1(char *pre,char *in,int n)//�����������������й��������
{
    BTNode *s;
    char *p;
    int k;
    if(n<=0)return NULL;
    s=(BTNode *)malloc(sizeof(BTNode));//�������������*s
    s->data=*pre;
    for(p=in;p<in+n;p++)//�������������ҵ���*pre��λ��k
        if(*p==*pre)
            break;
        k=p-in;
        s->lchild=create1(pre+1,in,k);
        s->rchild=create1(pre+k+1,p+1,n-k-1);
        return s;
}
BTNode *create2(char *post,char *in,int n,int m)//������ͺ���������й��������
{
    BTNode *s;
    char *p,*q,*maxp;
    int maxpost,maxin,k;
    if(n<=0)return NULL;
    maxpost=-1;
    for(p=in;p<in+n;p++)//��in��ȫ���ַ�����post���ұߵ��Ǹ��ַ�
        for(q=post;q<post+m;q++)//��in����maxpָ������ַ�����maxin��־����in�е��±�
            if(*p==*q)
            {
                k=q-post;
                if(k>maxpost)
                {
                    maxpost=k;
                    maxp=p;
                    maxin=p-in;
                }
            }
    s=(BTNode *)malloc(sizeof(BTNode));//�������������*s
    s->data=post[maxpost];
    s->lchild=create2(post,in,maxin,m);
    s->rchild=create2(post,maxp+1,n-maxin-1,m);
    return s;
}
void prin(BTNode *b)//�����ű�ʾ�����������
{
    if(b!=NULL)
    {
        printf(" %c",b->data);
        if(b->lchild!=NULL||b->rchild!=NULL)
        {
            printf("(");
            prin(b->lchild);//�ݹ鴦��������
            if(b->rchild!=NULL)printf(",");
            prin(b->rchild);//�ݹ鴦��������
            printf(")");
        }
    }
}
void prin1(BTNode *b)//�԰����ʾ�����һ�Ŷ�����
{
    BTNode *St[MaxSize],*p;
    int level[MaxSize][2],top=-1,n,i,width=4;
    char type;
    if(b!=NULL)
    {
        top++;
        St[top]=b;//�������ջ
        level[top][0]=width;
        level[top][1]=2;//2��ʾ�Ǹ�
        while(top>-1)
        {
            p=St[top];//�˗C��������ʾ�ý��ֵ
            n=level[top][0];
            switch(level[top][1])
            {
            case 0:type='L';break;//����֮�����(L)
            case 1:type='R';break;//�ҽ��֮�����(R)
            case 2:type='B';break;//�����֮�����(B)
            }
            for(i=1;i<=n;i++)//����nΪ��ʾ�����ַ����Ҷ�����ʾ
                printf(" ");
            printf("%c(%c)",p->data,type);
            printf("\n");
            top--;
            if(p->rchild!=NULL)
            {
                top++;//���������������ջ
                St[top]=p->rchild;
                level[top][0]=n+width;//��ʾ������width
                level[top][1]=1;//1��ʾ��������
            }
            if(p->lchild!=NULL)
            {
                top++;//���������������ջ
                St[top]=p->lchild;
                level[top][0]=n+width;//��ʾ������width
                level[top][1]=0;//0��ʾ��������
            }
        }
    }
}
int main()
{
    BTNode *b;
    ElemType pre[]="ABDEHJKLMNCFGI";
    ElemType in[]="DBJHLKMNEAFCGI";
    ElemType post[]="DJLNMKHEBFIGCA";
    b=create1(pre,in,14);
    printf(" ��������:%s\n",pre);
    printf(" ��������:%s\n",in);
    printf(" ����һ�Ŷ�����b:\n");
    printf(" ���ű�ʾ��:");prin(b);printf("\n");
    printf(" ��������:%s\n",pre);
    printf(" ��������:%s\n",in);
    printf(" ����һ�Ŷ�����b:\n");
    printf(" �����ʾ��:\n");prin1(b);printf("\n");
}
