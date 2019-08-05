#include<iostream>
#define ElemType int
typedef struct DuLNode
{
	//线性表的双向链表存储结构
	ElemType data;
	struct DuLNode *prior;
	struct DuLNode *next;
}DuLNode,*DuLinkList;
DuLinkList GetElem_DuL(DuLinkList L,int i)
{
	//获得双链表中第i个元素的地址
	if(L->next==L||i<1)return false;
	DuLinkList p=L->next;
	int j=0;
	for(;p!=L&&j<i;j++)
	{
		p=p->next;
	}
	if(j==i)
		return p;
	else 
		return false;

}
bool LinstInsert_DuL(DuLinkList &L,int i,ElemType e)
{
	//在带头结点的双链循环链表L中第i个位置之前插入元素e
	//i的合法性为1<=i<=表长+1;
	DuLinkList p,s;
	if(!(p=GetElem_DuL(L,i)))//在L中确定插入位置
		return false;
	if(!(s=(DuLinkList)malloc(sizeof(DuLNode))))return false;
	s->data=e;
	s->prior=p->prior;
	p->prior->next=s;
	s->next=p;
	p->prior=s;
	return true;
}
bool ListDelete_DuL(DuLinkList &L,int i,ElemType &e)
{
	//删除带头结点的双链循环线性表L的第i个元素，1<=i<=表长
	DuLinkList p;
	if(!(p=GetElem_DuL(L,i)))//在L中确定第i个元素的位置指针为p
		return false;
	e=p->data;
	p->prior->next=p->next;
	p->next->prior=p->prior;
	free(p);
	return true;
}
