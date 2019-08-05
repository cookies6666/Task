#include<iostream>
#define ElemType int
typedef struct LNode
{
	//线性表的单链表存储结构
	ElemType data;
	struct LNode*next;
}LNode,*LinkList;
bool ListInsert_L(LinkList &L,int i,ElemType e)
{
	//在带头结点的单链线性表L中第i个位置之前插入e
	LinkList p=L;
	int j=0;
	while(p&&j<i-1)//寻找第i-1个结点
	{
		p=p->next;
		++j;
	}
	if(!p||j>i-1)return false;//i小于1或者大于表长加1
	LinkList s=(LinkList)malloc(sizeof(LNode));//生成新节点
	//插入L中
	s->data=e;
	s->next=p->next;
	p->next=s;
	return true;
}
bool ListDelete_L(LinkList&L,int i,ElemType &e)
{
	//在带头结点的单链表L中，删除第i个元素，并由e返回其值
	LinkList p=L;
	int j=0;
	while(p->next&&j<i-1)//p指向第i个元素的前驱结点
	{
		p=p->next;
		++j;
	}
	if(!p->next||j>i-1)return false;//删除位置不合理
	LinkList q=p->next;
	p->next=q->next;
	e=q->data;
	return true;
}
bool MergerList_L(LinkList La,LinkList Lb,LinkList &Lc)
{
	//将非递减排列的La和Lb合并成非递减排列的Lc
	LinkList pa=La->next,pb=Lb->next;
	LinkList pc=Lc=La;//用La的头结点作为Lc的头结点
	while(pa&&pb)
	{
		if(pa->data<=pb->data)
		{
			pc->next=pa;
			pc=pa->next;
			pa=pa->next;
		}else
		{
			pc->next=pb;
			pc=pb->next;
			pb=pb->next;
		}
	}
	pc->next=pa?pa:pb;//插入剩余段
	return true;
}
bool ReserveList_L(LinkList &L)
{
	//单链表的反置
	if(!L&&!L->next)return false;
	LinkList p=L->next,q=p->next,s;
	while(q)//改变结点之间的指向
	{
		s=q->next;
		q->next=p;
		p=q;
		q=s;
	}
	L->next=p;
	return true;
}
LinkList GetMidList_L(LinkList L)
{
	//求单链表的中间元素
	LinkList p=L,q=L;
	//p一次走两步，q一次走一步
	while(p)
	{
		if(p->next!=NULL)
		{
			p=p->next->next;
		}else
		{
			break;	
		}
		q=q->next;
	}
	return q;
}