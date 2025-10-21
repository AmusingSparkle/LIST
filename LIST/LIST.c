#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

//定义状态
typedef int Status;
#define ERROR 0   //注意，define后面不用加';',否则会报错
#define OK 1
#define TRUE 1
#define FALSE 0

//定义列表结构 
#define MAXSIZE 20
typedef int ElemType;
typedef struct
{
	ElemType data[MAXSIZE];
	int length;
}SqList;

//定义线性表元素查看
Status visit(ElemType e)
{
	printf("%d", e);
	return OK;
}

//定义线性表初始化
Status InitList(SqList* L)
{
	L->length = 0;
	return OK;
}

//判断线性表是否为空
Status ListEmpty(SqList L)
{
	if (L.length)
	{
		return FALSE;
	}
		
	else
	{
		return TRUE;
	}
		
}

//清空线性表
Status ClearList(SqList* L)
{
	L->length = 0;
	return OK;
}

//获取线性表的长度
int ListLength(SqList L)
{
	return L.length;
}

//获取线性表中的某一项元素
Status GetElem(SqList L, int i, ElemType* e)
{
	//判断i是否合规:超出长度，为负数，线性表不存在
	if (i > L.length || i < 0 || L.length == 0)//第一位数组是从0开始，所以应该i<1
	{
		return ERROR;
	}
	//如果没问题就赋值给e
	else
	{
		//这里默认用户输入的顺序从1开始
		*e = L.data[i - 1];
		return OK;
	}
}

//定位某项元素
Status LocateElem(SqList L, ElemType e)
{
	//先判断线性表存不存在；
	if (L.length == 0)
	{
		return ERROR;
	}
	//存在就遍历
	int i = 0;
	for (i = 0; i < L.length; i++)
	{
		//相同就输出i
		if (L.data[i] == e)
		{
			return i + 1;//此处应该要跳出循环
		}
	}
	return ERROR;
}

//插入元素,默认用户输入的i从1开始
Status InsertElem(SqList* L, ElemType e, int i)
{
	//先判断合不合法：插入位置超出范围，i为零,线性表满员
	if ( i > L->length+1 || i < 0||L->length==MAXSIZE)//这里也一样，i<1
	{
		return ERROR;
	}
	//如果合法，先腾出位置
	//注意：如果此时从前往后遍历会导致后面的数据被前面的数据覆盖，引起数据错误，因此从后往前遍历
	int j = L->length;
	while (j >= i)//这里也是，main传上来的i默认大一，所以这里应该大于I-1
	{
		L->data[j + 1] = L->data[j];
		j--;
	}
	//腾出位置之后插入数据,最终线性表长度加一
	L->data[i - 1] = e;
	L->length++;
	return OK;
}

//删除元素，默认i从1开始
Status DeleteElem(SqList* L, int i,ElemType *e)
{
	//判断是否合法：位置不合理，线性表为空
	if (i<0 || i>L->length || L->length == 0)
	{
		return ERROR;
	}
	//将被删掉的值赋给e
	*e = L->data[i - 1];
	//将该元素直接用后面的元素覆盖，然后长度减一
	while (i <= L->length)
	{
		L->data[i - 1] = L->data[i];

	}
	L->length--;
	return OK;
}

//线性表遍历
Status ListTraverse(SqList L)
{
	if (L.length == 0)
	{
		return ERROR;
	}
	else
	{
		int i = 0;
		for (i = 0; i < L.length-1; i++)
		{
			visit(L.data[i]);
		}
		return OK;
	}
}

//两个线性表融合为一个表
void UnionList(SqList* La, SqList Lb)
{
	ElemType e;
	int lenb = ListLength(Lb);
	int lena = ListLength(*La);
	int i = 0;
	for (i = 0; i < lenb; i++)
	{
		GetElem(Lb, i, &e);
		if (!LocateElem(*La, e))
		{
			InsertElem(La, e, lena++);
		}
	}
}

int main()
{
	SqList L;
	int i,j;
	i = InitList(&L);
	printf("初始化后的L长度为：%d\n", L.length);

	for (i = 0; i <= 10; i++)
	{
		InsertElem(&L, i, i);
	}
	printf("插入十个元素后，线性表变为：");
	ListTraverse(L);
	printf("\n");
	i = ListLength(L);
	printf("此时线性表的长度为：%d", i);
	printf("\n");
	j=LocateElem(L, 4);
	printf("4是第%d个\n", j);
	InsertElem(&L, 11, 11);
	printf("插入11后变为：");
	ListTraverse(L);
	printf("\n");
	i=ListLength(L);
	printf("插入11后此时线性表的长度为：%d", i);
	printf("\n");
	DeleteElem(&L, 5,&j);
	printf("删除第5项后，线性表变为：");
	ListTraverse(L);
	printf("被删除的第五项为：%d",j);
	GetElem(L, 6, &i);
	printf("第6位为：%d", i);

	i = ListEmpty(L);
	printf("判断线性表是否为空：%d",i);
	ClearList(&L);
	i = ListEmpty(L);
	printf("当线性表清空后：%d", i);


	return 0;
}