#include<iostream>
#define LIST_INIT_SIZE 100  //���Ա�洢�ռ�ĳ�ʼ������
#define LISTINCREMENT 10	//���Ա�洢�ռ�ķ�������
#define ElemType int
typedef struct
{
	ElemType * elem;//�洢�ռ��ַ
	int length;//��ǰ����
	int listsize;//��ǰ����Ĵ洢�ռ�����
}SqList;
bool InitList_Sq(SqList &L)
{
	//����һ���յ����Ա�L
	L.elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(!L.elem)return false;//�洢ʧ��
	L.length=0;
	L.listsize=LIST_INIT_SIZE;
	return  true;
}
bool ListInert_Sq(SqList&L,int i,ElemType e)
{
	//��˳�����Ա�L�е�i��λ��֮ǰ������Ԫ��e
	//i�ĺϷ�ֵΪ1<=i<=L.length+1
	if(i<1||i>L.length+1) return false;//iֵ���Ϸ�
	if(L.length>=L.listsize)//��ǰ�洢�ռ����������ӷ���
	{
		ElemType*newbase=(ElemType*)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
		if(!newbase)exit(OVERFLOW);//����ʧ��
		L.elem=newbase;//�»�ַ
		L.listsize+=LISTINCREMENT;//���Ӵ洢����
	}
	ElemType*q=&(L.elem[i-1]);//qΪ����λ��
	for(ElemType*p=&(L.elem[L.length-1]);p>=q;--p)//����λ��֮���Ԫ������
		*(p+1)=*p;
	*q=e;//����e
	L.length++;//����1
	return true;
}
bool ListDelete_Sq(SqList &L,int i,ElemType&e)
{
	//�����Ա�L��ɾ����i��Ԫ�أ�����e������ֵ
	//i�ĺϷ���Ϊ1<=i<=L.length
	if(i<1||i>L.length) return false;
	ElemType*p=(ElemType*)L.elem[i-1];//pΪ��ɾ��Ԫ�ص�λ��
	e=*p;//��ɾ��Ԫ�ص�ֵ��e
	ElemType*q=L.elem+L.length-1;//qΪ��βԪ��
	for(++p;p<=q;++p)*(p-1)=*p;//��ɾ��Ԫ��֮���Ԫ������
	L.length--;//����һ
	return true;
}
bool ListModify_Sq(SqList &L,int i,ElemType e)
{
	//�����Ա�L�޸ĵ�i��Ԫ�ص�ֵΪe
	//i�ĺϷ���Ϊ1<=i<=L.length
	if(i<1||i>L.length) return false;
	ElemType*p=(ElemType*)L.elem[i-1];//pΪ���޸�Ԫ�ص�λ��
	*p=e;
	return true;
}
bool MergeList_Sq(SqList La,SqList Lb,SqList&Lc)
{
	//La��Lb˳����Ԫ�ذ�ֵ��������
	//�鲢La��Lb�õ��µ�˳���Lc��Lc��Ԫ���������У��ǵݼ����У�
	ElemType*Pa=La.elem,*Pb=Lb.elem,*Pc;
	Lc.listsize=Lc.length=La.length+Lb.length;//Lc�ĳ��Ⱥ�����
	Pc=Lc.elem=(ElemType*)malloc(Lc.listsize*sizeof(ElemType));//����Lc�Ŀռ�
	if(!Lc.elem) exit(false);//����ʧ��
	ElemType*Pa_last=La.elem+La.length-1,*Pb_last=Lb.elem+Lb.length-1;//Pa_lastΪLa���һ��Ԫ��λ��
	while(Pa<=Pa_last&&Pb<=Pb_last)//�鲢
	{
		if(*Pa<=*Pb)*Pc++=*Pa++;
		else *Pc++=*Pb++;
	}	
	while(Pa<=Pa_last)*Pc++=*Pa++;//����ʣ��Ԫ��
	while(Pb<=Pa_last)*Pc++=*Pb++;
	return true;
}