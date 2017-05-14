#include<stdio.h>


//线性表内的元素 
typedef struct{
	
	int element; 
	
}ElemType; 

//线性表结构--数组表示 
typedef struct{
	
	ElemType *elem;
	int length;
	int listsize;
	
}SqList; 

/*
删除表中的最小的元素，由最后一个替补 
*/
//e作为一个别名返回 
bool Del_Min(SqList &l,ElemType &e); 

/*
对调表中的元素 
*/
bool Reverse(SqList &l);

/*
删除表所有为X的元素，要求时间 为 O（n） 空间复杂度 O(1) 
*/
bool Del_X(SqList &l,Elemtype &e);

/*
删除 s--t 之间的元素，l为有序表 
*/
bool Del_sTot_OrderList(SqList &l,int s,int t); 

/*
删除 s--t 之间的元素，l为顺序表 
*/
bool Del_sTot(SqList &l,int s,int t); 

int main()
{
	
    return 0;
}

bool Del_Min(SqList &l,ElemType &e){
	
	if(l.length==0) return false;//判断是否为空，如果是的话停止
	
	e=l.elem[0];                 //假定为最小值为零
	
	int pos=0;                     //记录最小元素的位置 
	
	//找出最小的元素 
	for(int i=1;i<l.length;i++){
		
		if(e.element>l.elem[i].element){
			
			e.element=l.elem[i].element;
			pos=i; 
		}
		
	}
	
	
	//和最后一位元素调换 
	l.elem[pos]=l.elem[l.length];
	l.length--;
	
	return true; 
	
} 

bool Reverse(SqList &l){
	
	if(l.length==0) return false;
	
	ElemType temp;
	for(int i=0;i<(l.length/2);i++){
		temp=l.elem[i];
		l.elem[i]=l.elem[l.length-i-1];//注意要减1 
		l.elem[l.length-i-1]=temp;
	}
	
}

bool Del_X(SqList &l,Elemtype &e){
	int k=0;//不同于e的元素 
	
	for(int i=0;i<l.length;++i){
		
		if(l.elem[i].element!=e.element){
			l.elem[k]=l.elem[i].element;
			++k;
		}
	}
	
	l.length=k;
	
}

bool Del_sTot(SqList &l,int s,int t){
	
	int k=0;//不符合要求的个数 
	
	if(l.length==0||s>=t) return false;
	
	for(int i;i<l.length;++i){
		
		if(s>l.elem[i]||l.elem[i]>t){
			
			l.elem[k]=l.elem[i];
			k++;
		}	
	}
	l.length=k;
}

bool Del_sTot_OrderList(SqList &l,int s,int t){
	
	if(l.length==0||s>=t) return false;
	
	for(int i=0;i<l.length&&l.elem[i]>s;++i);
	
	if(i==l.length) return false;
	
	for(int j=l.length-1;j>0&&l.elem[j]<t;--j);
	
	for(;l.length-1>j;i++,j++){
	l.elem[i]=l.elem[j];
	
	}
	
	l.length=i;
	
}































