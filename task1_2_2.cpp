#include<iostream>
#define ElemType int
typedef struct CirLNode
{
	//���Ա��ѭ������洢�ṹ
	ElemType data;
	struct CirLNode*next;
}CirLNode,*CirLinkList;
void InitCirLink(CirLinkList&L)
{
	//ѭ�������ʼ��
	L=(CirLinkList)malloc(sizeof(CirLNode));
	L->next=L;
	L->data=NULL;
}
bool CirListInsert_L(CirLinkList &L,int i,ElemType e)
{
	//�ڴ�ͷ����ѭ������L�е�i��λ��֮ǰ����e
	CirLinkList p=L;
	int j=0;
	while(p&&j<i-1)//Ѱ�ҵ�i-1�����
	{
		p=p->next;
		++j;
	}
	if(!p||j>i-1)return false;//iС��1���ߴ��ڱ���1
	CirLinkList s=(CirLinkList)malloc(sizeof(CirLNode));//�����½ڵ�
	//����L��
	s->data=e;
	s->next=p->next;
	p->next=s;
	return true;
}
bool CirListDelete_L(CirLinkList&L,int i,ElemType &e)
{
	//�ڴ�ͷ����ѭ������L�У�ɾ����i��Ԫ�أ�����e������ֵ
	CirLinkList p=L;
	int j=0;
	while(p->next&&j<i-1)//pָ���i��Ԫ�ص�ǰ�����
	{
		p=p->next;
		++j;
	}
	if(!p->next||j>i-1)return false;//ɾ��λ�ò�����
	CirLinkList q=p->next;
	p->next=q->next;
	e=q->data;
	return true;
}
