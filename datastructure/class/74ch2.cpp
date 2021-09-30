#include<stdio.h>
#include<malloc.h>
#define Maxsize 100
typedef char ElemType;
typedef struct
{ ElemType data[Maxsize];
 int top;//ջ��ָ��
}SqStack;
void InitStack(SqStack *&s)//��ʼ��ջs
{
 s=(SqStack*)malloc(sizeof(SqStack));
 s->top=-1;//ջ��ָ���ʼֵΪ-1
}
void DestroyStack(SqStack *&s)//����ջs
{
 free(s);
}
bool StackEmpty(SqStack *s)//�ж�ջs�Ƿ�Ϊ��
{
 return(s->top==-1);
}
bool Puch(SqStack *&s,ElemType e)//��ջ
{
 if(s->top==Maxsize-1)//ջ�������
  return false;
 else
  s->top++;//ջ��ָ���һ
  s->data[s->top]=e;//��Ԫ��e�ŵ�ջ��ָ�봦
 return true;
}
bool Pop(SqStack *&s,ElemType &e)//��ջ
{
 if(s->top==-1)//ջΪ��ʱ������
  return false;
 else
  e=s->data[s->top];
 s->top--;
 return true;
}
bool GetTop(SqStack *&s,ElemType &e)//ȡջ��Ԫ��
{
 if(s->top==-1)//ջΪ�յ����
  return false;
 else
  e=s->data[s->top];
 return true;
}
int main()
{
 char a,b,c,d,m;
 ElemType e;
 SqStack *s;
 InitStack(s);
 printf("��ʼ��ջ�ɹ�s\n");
 printf("�ж�\n");
 printf("ջΪ%s\n",(StackEmpty(s)?"��":"�ǿ�"));
 printf("����Ԫ��a-e\n");
 scanf("%c %c %c %c %c%*c",&a,&b,&c,&d,&m);
 Puch(s,a);
 Puch(s,b);
 Puch(s,c);
 Puch(s,d);
 Puch(s,m);
 printf("�ж�\n");
 printf("ջΪ%s\n",(StackEmpty(s)?"��":"�ǿ�"));
 printf("��ջ��");
 while(!StackEmpty(s))
  {
   Pop(s,e);
   printf("%c",e);
  }
 printf("\n");
 printf("�ж�\n");
 printf("ջΪ%s\n",(StackEmpty (s)?"��":"�ǿ�"));
 printf("�ͷ�ջ\n") ;
 DestroyStack(s);
 return 0;
}
