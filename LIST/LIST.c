#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

//����״̬
typedef int Status;
#define ERROR 0   //ע�⣬define���治�ü�';',����ᱨ��
#define OK 1
#define TRUE 1
#define FALSE 0

//�����б�ṹ 
#define MAXSIZE 20
typedef int ElemType;
typedef struct
{
	ElemType data[MAXSIZE];
	int length;
}SqList;

//�������Ա�Ԫ�ز鿴
Status visit(ElemType e)
{
	printf("%d", e);
	return OK;
}

//�������Ա��ʼ��
Status InitList(SqList* L)
{
	L->length = 0;
	return OK;
}

//�ж����Ա��Ƿ�Ϊ��
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

//������Ա�
Status ClearList(SqList* L)
{
	L->length = 0;
	return OK;
}

//��ȡ���Ա�ĳ���
int ListLength(SqList L)
{
	return L.length;
}

//��ȡ���Ա��е�ĳһ��Ԫ��
Status GetElem(SqList L, int i, ElemType* e)
{
	//�ж�i�Ƿ�Ϲ�:�������ȣ�Ϊ���������Ա�����
	if (i > L.length || i < 0 || L.length == 0)//��һλ�����Ǵ�0��ʼ������Ӧ��i<1
	{
		return ERROR;
	}
	//���û����͸�ֵ��e
	else
	{
		//����Ĭ���û������˳���1��ʼ
		*e = L.data[i - 1];
		return OK;
	}
}

//��λĳ��Ԫ��
Status LocateElem(SqList L, ElemType e)
{
	//���ж����Ա�治���ڣ�
	if (L.length == 0)
	{
		return ERROR;
	}
	//���ھͱ���
	int i = 0;
	for (i = 0; i < L.length; i++)
	{
		//��ͬ�����i
		if (L.data[i] == e)
		{
			return i + 1;//�˴�Ӧ��Ҫ����ѭ��
		}
	}
	return ERROR;
}

//����Ԫ��,Ĭ���û������i��1��ʼ
Status InsertElem(SqList* L, ElemType e, int i)
{
	//���жϺϲ��Ϸ�������λ�ó�����Χ��iΪ��,���Ա���Ա
	if ( i > L->length+1 || i < 0||L->length==MAXSIZE)//����Ҳһ����i<1
	{
		return ERROR;
	}
	//����Ϸ������ڳ�λ��
	//ע�⣺�����ʱ��ǰ��������ᵼ�º�������ݱ�ǰ������ݸ��ǣ��������ݴ�����˴Ӻ���ǰ����
	int j = L->length;
	while (j >= i)//����Ҳ�ǣ�main��������iĬ�ϴ�һ����������Ӧ�ô���I-1
	{
		L->data[j + 1] = L->data[j];
		j--;
	}
	//�ڳ�λ��֮���������,�������Ա��ȼ�һ
	L->data[i - 1] = e;
	L->length++;
	return OK;
}

//ɾ��Ԫ�أ�Ĭ��i��1��ʼ
Status DeleteElem(SqList* L, int i,ElemType *e)
{
	//�ж��Ƿ�Ϸ���λ�ò��������Ա�Ϊ��
	if (i<0 || i>L->length || L->length == 0)
	{
		return ERROR;
	}
	//����ɾ����ֵ����e
	*e = L->data[i - 1];
	//����Ԫ��ֱ���ú����Ԫ�ظ��ǣ�Ȼ�󳤶ȼ�һ
	while (i <= L->length)
	{
		L->data[i - 1] = L->data[i];

	}
	L->length--;
	return OK;
}

//���Ա����
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

//�������Ա��ں�Ϊһ����
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
	printf("��ʼ�����L����Ϊ��%d\n", L.length);

	for (i = 0; i <= 10; i++)
	{
		InsertElem(&L, i, i);
	}
	printf("����ʮ��Ԫ�غ����Ա��Ϊ��");
	ListTraverse(L);
	printf("\n");
	i = ListLength(L);
	printf("��ʱ���Ա�ĳ���Ϊ��%d", i);
	printf("\n");
	j=LocateElem(L, 4);
	printf("4�ǵ�%d��\n", j);
	InsertElem(&L, 11, 11);
	printf("����11���Ϊ��");
	ListTraverse(L);
	printf("\n");
	i=ListLength(L);
	printf("����11���ʱ���Ա�ĳ���Ϊ��%d", i);
	printf("\n");
	DeleteElem(&L, 5,&j);
	printf("ɾ����5������Ա��Ϊ��");
	ListTraverse(L);
	printf("��ɾ���ĵ�����Ϊ��%d",j);
	GetElem(L, 6, &i);
	printf("��6λΪ��%d", i);

	i = ListEmpty(L);
	printf("�ж����Ա��Ƿ�Ϊ�գ�%d",i);
	ClearList(&L);
	i = ListEmpty(L);
	printf("�����Ա���պ�%d", i);


	return 0;
}