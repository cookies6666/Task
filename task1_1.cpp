#include<iostream>
#define LIST_INIT_SIZE 100  //线性表存储空间的初始分配量
#define LISTINCREMENT 10	//线性表存储空间的分配增量
#define ElemType int
typedef struct
{
	ElemType * elem;//存储空间地址
	int length;//当前长度
	int listsize;//当前分配的存储空间容量
}SqList;
bool InitList_Sq(SqList &L)
{
	//构造一个空的线性表L
	L.elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(!L.elem)return false;//存储失败
	L.length=0;
	L.listsize=LIST_INIT_SIZE;
	return  true;
}
bool ListInert_Sq(SqList&L,int i,ElemType e)
{
	//在顺序线性表L中第i个位置之前插入新元素e
	//i的合法值为1<=i<=L.length+1
	if(i<1||i>L.length+1) return false;//i值不合法
	if(L.length>=L.listsize)//当前存储空间已满，增加分配
	{
		ElemType*newbase=(ElemType*)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
		if(!newbase)exit(OVERFLOW);//分配失败
		L.elem=newbase;//新基址
		L.listsize+=LISTINCREMENT;//增加存储容量
	}
	ElemType*q=&(L.elem[i-1]);//q为插入位置
	for(ElemType*p=&(L.elem[L.length-1]);p>=q;--p)//待入位置之后的元素右移
		*(p+1)=*p;
	*q=e;//插入e
	L.length++;//表长增1
	return true;
}
bool ListDelete_Sq(SqList &L,int i,ElemType&e)
{
	//在线性表L中删除第i个元素，并用e返回其值
	//i的合法性为1<=i<=L.length
	if(i<1||i>L.length) return false;
	ElemType*p=(ElemType*)L.elem[i-1];//p为被删除元素的位置
	e=*p;//被删除元素的值给e
	ElemType*q=L.elem+L.length-1;//q为表尾元素
	for(++p;p<=q;++p)*(p-1)=*p;//被删除元素之后的元素右移
	L.length--;//表长减一
	return true;
}
bool ListModify_Sq(SqList &L,int i,ElemType e)
{
	//在线性表L修改第i个元素的值为e
	//i的合法性为1<=i<=L.length
	if(i<1||i>L.length) return false;
	ElemType*p=(ElemType*)L.elem[i-1];//p为被修改元素的位置
	*p=e;
	return true;
}
bool MergeList_Sq(SqList La,SqList Lb,SqList&Lc)
{
	//La，Lb顺序表的元素按值有序排列
	//归并La和Lb得到新的顺序表Lc，Lc的元素有序排列（非递减排列）
	ElemType*Pa=La.elem,*Pb=Lb.elem,*Pc;
	Lc.listsize=Lc.length=La.length+Lb.length;//Lc的长度和容量
	Pc=Lc.elem=(ElemType*)malloc(Lc.listsize*sizeof(ElemType));//分配Lc的空间
	if(!Lc.elem) exit(false);//分配失败
	ElemType*Pa_last=La.elem+La.length-1,*Pb_last=Lb.elem+Lb.length-1;//Pa_last为La最后一个元素位置
	while(Pa<=Pa_last&&Pb<=Pb_last)//归并
	{
		if(*Pa<=*Pb)*Pc++=*Pa++;
		else *Pc++=*Pb++;
	}	
	while(Pa<=Pa_last)*Pc++=*Pa++;//插入剩余元素
	while(Pb<=Pa_last)*Pc++=*Pb++;
	return true;
}