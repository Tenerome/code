#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SizeMax 10
typedef char ElemType;
typedef struct
{
    ElemType data[SizeMax];
    int length;
 } SqList;
void InitList(SqList *&L)
 {
	L=(SqList *)malloc(sizeof(SqList));
	L->length=0;
}
void Insert(SqList *&L,ElemType s)
 {
	L->data[L->length]=s;
	L->length++;
}
void Print(SqList *&L)
{
	int i;
	printf("���˳���Ϊ��\n");
	for(i=0;i<L->length-1;i++)
	printf("%c ",L->data[i]);
	printf("%c\n",L->data[L->length-1]);
 }
void PrintLength(SqList *&L)
{
    printf("˳���ĳ���Ϊ��");
	printf("%d\n",L->length);
 }
bool SqNull(SqList *&L)
{
	if(L->length)return 1; return 0;
}
void PrintData(SqList *&L,int n)
{
    printf("�������Ԫ��Ϊ��");
	printf("%c\n",L->data[n-1]);
}
bool Find(SqList *&L,char a)
{
	int i;
	for(i=0;i<L->length;i++)
		if(L->data[i]==a)
		return i+1;
 }
void Insertinto(SqList *&L,int n,char f)
{
	int j;
	n--;
	for(j=L->length;j>n;j--)
		L->data[j]=L->data[j-1];
		L->data[n]=f; L->length++;
}
void Delete(SqList *&L,int n)
{
	int j;
	n--;
	for(j=n;j<L->length;j++)
	L->data[j]=L->data[j+1];
	L->length--;
}
int main()
{
	SqList *L;
	InitList(L); //��ʼ��˳���
	ElemType a,b,c,d,e;
	printf("����a-e\n");
	scanf("%c %c %c %c %c%*c",&a,&b,&c,&d,&e);
	Insert(L,a);
	Insert(L,b);
	Insert(L,c);
	Insert(L,d);
	Insert(L,e); //ʹ��β�巨����Ԫ��a,b,c,d,e
	Print(L); //���˳���
	PrintLength(L); //���˳�����
	if(SqNull(L))
		printf("˳���Ϊ��\n");
	else
		printf("˳���Ϊ��\n"); //�ж�˳����Ƿ�Ϊ��
	PrintData(L,3); //���������Ԫ��
	printf("Ԫ��a��λ�ã�%d\n",Find(L,a)); //���Ԫ��a��λ��
	printf("����Ԫ��f\n");
	ElemType f;
	scanf("%c",&f);
	Insertinto(L,4,f); //��f���뵽���ĸ�λ��
	Print(L); //���˳���
	Delete(L,3); //ɾ��������Ԫ��
	printf("ɾ��������Ԫ�غ�");
	Print(L); //���˳���
	free(L); //�ͷ��ڴ�
	return 0;
 }
