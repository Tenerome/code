#include "stdio.h"
#include "string.h"
#define size 100

typedef struct
{
	char data[size];
	int len;
}String;

String a,b,c,d,e;
void scan(String &s,char arg[])//¼�룬&s ֱ���޸�
{
	int i;//������������Ϊѭ��֮��i����length
	for(i=0;arg[i]!='\0';i++)
		s.data[i]=arg[i];
	s.len=i;
}

void prin(String s)//���
{
	for(int i=0;i<s.len;i++)
		printf("%c",s.data[i]);
	printf("\n");
}

void encrypt()//����
{
int i;
for(i=0; i<c.len; i++)
	for(int j=0; j<a.len; j++)
			if(c.data[i]==a.data[j])
				d.data[i]=b.data[j];
d.len=i;
}


void unencry()//����
{
int i;
for(i=0; i<d.len; i++)
	  for(int j=0; j<b.len; j++)
		if(d.data[i]==b.data[j])
			e.data[i]=a.data[j];
e.len=i;
}

int main()
{
	scan(a,"abcdefghijklmnopqrstuvwxyz");
	scan(b,"ngzqtcobmuhelkpdawxfyivrsj");
	char st[size];
	printf("����������ı���\n");
	gets(st);
	scan(c,st);
	printf("�����ı���\n");
	encrypt();
	prin(d);
	printf("�����ı���\n");
	unencry();
	prin(e);
}
