// ChainList.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode, *LinkList;

//定义两个结构体变量
using namespace std;

//利用头插法建立链表
LinkList CreateList1(LinkList &L)
{
	LNode *s;
	int x;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	cin >> x;
	while(x != -1)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		cin >> x;
	}
	return L;
}

LinkList CreateList2(LinkList &L)
{
	LNode *s;
	int x;
	L = (LinkList)malloc(sizeof(LNode));
	LNode *temp = L;
	cin >> x;
	while(x != -1)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		temp->next = s;
		temp = s;
		cin >> x;
	}
	temp->next = NULL;
	return L;
}

LNode* FindNumByIndex(LinkList &L, int index)
{
	int flag = 0;
	LNode *temp = L;
	while(temp->next != NULL)
	{
		temp = temp->next;
		if(flag == index)
		{
			return temp;
		}
		else
		{
			flag ++;
		}
	}
	return NULL;
}

LNode* FindNumByContent(LinkList &L, int key)
{
	int flag = 0;
	LNode *temp;
	temp = L;
	while(temp->next != NULL)
	{
		temp = temp->next;
		if(temp->data == key)
		{
			return temp;
		}
		else
		{
			key ++;
		}
	}
	return NULL;
}

int InsertData(LinkList &L, int pos, LNode *n)
{
	int flag = 0;
	LNode *temp;
	temp = L;
	while(temp->next != NULL)
	{
		temp = temp->next;
		if(flag == pos)
		{
			n->next = temp->next;
			temp->next = n;
			return 1;
		}
		else
		{
			flag ++;
		}
	}
	return -1;
}
int DeleteData(LinkList &L, int pos)
{
	LNode *first = FindNumByIndex(L, pos-1);
	LNode *second = first->next;
	first->next = second->next;
//	free(second);
	return 1;
}

int CalculateLength(LinkList &L)
{
	LNode *temp;
	temp = L;
	int length = 0;
	while(temp->next != NULL)
	{
		temp = temp->next;
		length ++;
	}
	return length;
}

void DeleteGivenValue(LinkList &L, int x)
{
	LNode *front = L;
	LNode *behind = L->next;
	while(behind->next != NULL)
	{
		if(behind->data == x)
		{
			front->next = behind->next;
			behind = behind->next;
		}
		else
		{
			front = front->next;
			behind = behind->next;
		}
	}
}

void ReversePrint(LinkList &L)
{
	if(L->next != NULL)
	{
		ReversePrint(L->next);
	}
	cout << L->data;
}

int DeleteMin(LinkList &L)
{
	LNode *front = L;
	LNode *behind = L->next;
	int min = behind->data;
	while(behind->next != NULL)
	{
		if(behind->next->data < min)
		{
			min = behind->next->data;
			front = behind;
			behind = behind ->next;
		}
		else
		{
			behind = behind ->next;
		}
	}
	if(front->next->next == NULL)
	{
		front->next = NULL;
	}
	else
	{
		LNode *a = front->next->next;
		front->next = a;
	}
	return min;
}

void ReverseM1(LinkList &L)
{
	LinkList r;
	LNode *temp = L->next;
	L->next = NULL;
	while (temp != NULL)
	{
		r = temp->next;
		temp->next = L->next;
		L->next = temp;
		temp = r;
	}
}

void ReverseM2(LinkList &L)
{
	LNode *pre;
	LNode *p = L->next;
	LNode *r = p->next;
	p->next = NULL;
	while(r != NULL)
	{
		pre = p;
		p = r;
		r = r->next;
		p->next= pre;
	}
	L->next = p;
}

int _tmain(int argc, _TCHAR* argv[])
{
	LinkList ll;
	ll = CreateList2(ll);
//	LNode *ln;
//	ln = (LNode*)malloc(sizeof(LNode));
//	ln->data = 1000;
//	InsertData(ll, 2, ln);
//	DeleteData(ll, 2);
//	LNode *a = FindNumByIndex(ll,1);
//	int length = CalculateLength(ll);
//	DeleteGivenValue(ll, 1);
//	ReversePrint(ll->next);
//	int min = DeleteMin(ll);
	ReverseM2(ll);
	cout << "Output: ";
//	cout << min;
	cout << endl;
//	cout << a->data;
	
	LNode *temp;
	temp = ll;
	while(temp->next != NULL)
	{
		temp = temp->next;
		cout << temp->data;
		cout << endl;
	}
//	cout << length;
//	int result = FindNumByIndex(ll, 1);
//	cout << result;
	return 0;
}

