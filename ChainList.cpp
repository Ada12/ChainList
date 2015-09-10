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
	free(temp);
	return NULL;
}

LNode* FindNumByContent(LinkList &L, int key)
{
	int flag = 0;
	while(L->next != NULL)
	{
		L = L->next;
		if(L->data == key)
		{
			return L;
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
	LNode *lex;
	lex = L;
	while(lex->next != NULL)
	{
		lex = lex->next;
		if(flag == pos)
		{
			n->next = lex->next;
			lex->next = n;
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
	free(second);
	return 1;
}

//LinkList CreateList2(LinkList &L)
//{
//	
//}

int _tmain(int argc, _TCHAR* argv[])
{
	LinkList ll;
	ll = CreateList1(ll);
	LNode *ln;
	ln = (LNode*)malloc(sizeof(LNode));
	ln->data = 1000;
//	InsertData(ll, 2, ln);
	DeleteData(ll, 2);
//	LNode *a = FindNumByIndex(ll,1);
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
	
//	int result = FindNumByIndex(ll, 1);
//	cout << result;
	return 0;
}

