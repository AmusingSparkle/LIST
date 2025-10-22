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
//今天真的好累，满课，我能感觉到我的思维明显跟不上，今天先学Java吧，再这里耗下去也没有用