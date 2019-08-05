#include<iostream>
#define ElemType int
typedef struct CirLNode
{
	//线性表的循环链表存储结构
	ElemType data;
	struct CirLNode*next;
}CirLNode,*CirLinkList;
void InitCirLink(CirLinkList&L)
{
	//循环链表初始化
	L=(CirLinkList)malloc(sizeof(CirLNode));
	L->next=L;
	L->data=NULL;
}
bool CirListInsert_L(CirLinkList &L,int i,ElemType e)
{
	//在带头结点的循环链表L中第i个位置之前插入e
	CirLinkList p=L;
	int j=0;
	while(p&&j<i-1)//寻找第i-1个结点
	{
		p=p->next;
		++j;
	}
	if(!p||j>i-1)return false;//i小于1或者大于表长加1
	CirLinkList s=(CirLinkList)malloc(sizeof(CirLNode));//生成新节点
	//插入L中
	s->data=e;
	s->next=p->next;
	p->next=s;
	return true;
}
bool CirListDelete_L(CirLinkList&L,int i,ElemType &e)
{
	//在带头结点的循环链表L中，删除第i个元素，并由e返回其值
	CirLinkList p=L;
	int j=0;
	while(p->next&&j<i-1)//p指向第i个元素的前驱结点
	{
		p=p->next;
		++j;
	}
	if(!p->next||j>i-1)return false;//删除位置不合理
	CirLinkList q=p->next;
	p->next=q->next;
	e=q->data;
	return true;
}
