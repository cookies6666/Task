#include<iostream>
#define ElemType int
typedef struct LNode
{
	//���Ա�ĵ�����洢�ṹ
	ElemType data;
	struct LNode*next;
}LNode,*LinkList;
bool ListInsert_L(LinkList &L,int i,ElemType e)
{
	//�ڴ�ͷ���ĵ������Ա�L�е�i��λ��֮ǰ����e
	LinkList p=L;
	int j=0;
	while(p&&j<i-1)//Ѱ�ҵ�i-1�����
	{
		p=p->next;
		++j;
	}
	if(!p||j>i-1)return false;//iС��1���ߴ��ڱ���1
	LinkList s=(LinkList)malloc(sizeof(LNode));//�����½ڵ�
	//����L��
	s->data=e;
	s->next=p->next;
	p->next=s;
	return true;
}
bool ListDelete_L(LinkList&L,int i,ElemType &e)
{
	//�ڴ�ͷ���ĵ�����L�У�ɾ����i��Ԫ�أ�����e������ֵ
	LinkList p=L;
	int j=0;
	while(p->next&&j<i-1)//pָ���i��Ԫ�ص�ǰ�����
	{
		p=p->next;
		++j;
	}
	if(!p->next||j>i-1)return false;//ɾ��λ�ò�����
	LinkList q=p->next;
	p->next=q->next;
	e=q->data;
	return true;
}
bool MergerList_L(LinkList La,LinkList Lb,LinkList &Lc)
{
	//���ǵݼ����е�La��Lb�ϲ��ɷǵݼ����е�Lc
	LinkList pa=La->next,pb=Lb->next;
	LinkList pc=Lc=La;//��La��ͷ�����ΪLc��ͷ���
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
	pc->next=pa?pa:pb;//����ʣ���
	return true;
}
bool ReserveList_L(LinkList &L)
{
	//������ķ���
	if(!L&&!L->next)return false;
	LinkList p=L->next,q=p->next,s;
	while(q)//�ı���֮���ָ��
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
	//��������м�Ԫ��
	LinkList p=L,q=L;
	//pһ����������qһ����һ��
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