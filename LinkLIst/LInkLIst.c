#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define OK 1
#define ERROR 0
#define TURE 1
#define FALSE 0

#define MAXSIZE 20

typedef int Status;
typedef int ElemType;

/*������Ҫtype���壬�������ʼ�����ж��Ƿ�Ϊ�գ�����б��鿴�б��ȣ���ȡԪ�أ���λ
* Ԫ�أ�����Ԫ�أ�ɾ��Ԫ�أ������б�ͷ�巨��β�巨*/

typedef struct Node
{
	ElemType data[MAXSIZE];
	struct Node* next;
}Node;
typedef Node* LinkList;

void visit(ElemType c)
{
	printf("%d", c);
}

Status InitList(LinkList* L)
{
	*L = (LinkList)malloc(sizeof(Node));
	if (*L)
	{
		return ERROR;
	}
	(*L)->next = NULL;
	return OK;
}
//������ĺ��ۣ����Σ����ܸо����ҵ�˼ά���Ը����ϣ�������ѧJava�ɣ����������ȥҲû����