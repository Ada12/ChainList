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
	cout << "Output: ";
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

