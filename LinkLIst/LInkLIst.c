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

/*链表需要type定义，输出，初始化，判断是否为空，清空列表，查看列表长度，获取元素，定位
* 元素，插入元素，删除元素，遍历列表，头插法，尾插法*/

typedef struct Node
{
	ElemType data[MAXSIZE];
	struct Node* next;
}Node;
typedef Node* LinkList;

void visit(ElemType c)
{
	printf("%d", c);
	return OK;
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
		return FALSE;
	return TURE;
}

//这个不是很熟
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
	int i = 1;
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
	int j = 1;
	while (q || j < i)
	{
		q = q->next;
		j++;
	}
	*e = q->data;
	return OK;
	if (q || j > i)
		return ERROR;
}

int LocateElem(LinkList L, ElemType e)
{
	LinkList q = L->next;
	int j = 1;
	while (q)
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
		return ERROR;
	}
}

Status DeletElem(LinkList* L, int i, ElemType* e)
{
	LinkList q = (*L);
	int j = 1;
	while (q || j < i)
	{
		q = q->next;
		j++;
	}
	LinkList d = q->next;
	q->next = d->next;
	free(d);
	return OK;
	if (q || j > i)
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