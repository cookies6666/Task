#include<iostream>
#define ElemType int
typedef struct DuLNode
{
	//���Ա��˫������洢�ṹ
	ElemType data;
	struct DuLNode *prior;
	struct DuLNode *next;
}DuLNode,*DuLinkList;
DuLinkList GetElem_DuL(DuLinkList L,int i)
{
	//���˫�����е�i��Ԫ�صĵ�ַ
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
	//�ڴ�ͷ����˫��ѭ������L�е�i��λ��֮ǰ����Ԫ��e
	//i�ĺϷ���Ϊ1<=i<=��+1;
	DuLinkList p,s;
	if(!(p=GetElem_DuL(L,i)))//��L��ȷ������λ��
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
	//ɾ����ͷ����˫��ѭ�����Ա�L�ĵ�i��Ԫ�أ�1<=i<=��
	DuLinkList p;
	if(!(p=GetElem_DuL(L,i)))//��L��ȷ����i��Ԫ�ص�λ��ָ��Ϊp
		return false;
	e=p->data;
	p->prior->next=p->next;
	p->next->prior=p->prior;
	free(p);
	return true;
}
