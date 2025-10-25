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
	return OK;//void Ϊʲô��return OK?
}

Status InitList(LinkList* L)
{
	*L = (LinkList)malloc(sizeof(Node));
	if (!(*L))
	{
		return ERROR;
	}
	(*L)->next = NULL;
	return OK;
}

Status ListEmpty(LinkList L)
{
	if (L->next == NULL)
		return FALSE;//???����дʲô��ΪNULL����˵����Ϊ���𣿣���
	return TURE;
}

//������Ǻ���
Status ClearList(LinkList* L)
{
	LinkList k, d;
	d = (*L)->next;
	while (d)
	{
		k = d->next;
		free(d);
		d = k;
	}
	return OK;
}

int ListLength(LinkList L)
{
	if (!L)
	{
		return 0;
	}
	int i = 1;//ע�⣬��ʽ���ڼ���ʱ���ӳ٣������������һ������������ͣ�£�Ҫ�ٹ�һ���ű��NUll���Ż�ֹͣ�����Ҫi=1
	LinkList q = L->next;
	while (q)
	{
		q = q->next;
		i++;
	}
	return i;
}

Status GetElem(LinkList L, int i, ElemType* e)
{
	LinkList q = L->next;
	int j = 1;//�����ﲻ���ӳ١�Ϊʲô����Ϊ�Ҳ�����NLULL��Ϊ��׼
	while (q || j < i)
	{
		q = q->next;
		j++;
	}
	*e = q->data;
	return OK;
	if (q || j > i)
		return ERROR;//���ﲻ�ԣ��ж�Ӧ��ǰ�棬������qΪ�գ���ô�ͱ����Ұָ��
}

int LocateElem(LinkList L, ElemType e)
{
	LinkList q = L->next;
	int j = 1;
	while (q)//����Ҳһ����Ҫ��NULL��Ϊ��־�Ļ���Ӧ��ȻjС1
	{
		if (q->data == e)
		{
			return j;
		}
		q = q->next;
		j++;
	}
	return ERROR;
}

Status InsertElem(LinkList* L, int i, ElemType e)
{
	LinkList q = (*L);
	int j = 1;
	while (q || j < i)
	{
		q = q->next;
		j++;
	}
	LinkList p = (LinkList)malloc(sizeof(Node));
	p->data = e;
	p->next = q->next;
	q->next = p;
	return OK;
	if (q || j > i)
	{
		return ERROR;//����Ҳ�ǣ�Ҫ��ֹҰָ��
	}
}

Status DeletElem(LinkList* L, int i, ElemType* e)
{
	LinkList q = (*L);
	int j = 1;
	while (q || j < i)//����Ӧ��Ϊq->next�������жϺ����ڵ��Ƿ�Ϊ��
	{
		q = q->next;
		j++;
	}
	LinkList d = q->next;
	q->next = d->next;
	free(d);
	return OK;
	if (q || j > i)//�жϷ�ǰ��,q��Ϊ!(q->next)
		return ERROR;
}

Status ListTraverse(LinkList L)
{
	LinkList q = L->next;
	while (q)
	{
		visit(q->data);
		q = q->next;
	}
	return OK;
}

void CreatListHead(LinkList* L, int i)
{
	InitList(L);
	LinkList q;
	int j = 0;
	srand(time(0));
	while (j < i)
	{
		q = (LinkList)malloc(sizeof(Node));
		q->next = NULL;
		q->data = rand() % 100 - 1;
		(*L)->next = q;
		j++;
	}
}

void CreateListTail(LinkList* L, int n)
{
	LinkList p, r;
	int i;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node)); 
	r = *L;                               
	for (i = 0; i < n; i++)
	{
		p = (Node*)malloc(sizeof(Node));
		p->data = rand() % 100 + 1; 
		r->next = p; 
		r = p; 
	}
	r->next = NULL;