#include<stdio.h>


//���Ա��ڵ�Ԫ�� 
typedef struct{
	
	int element; 
	
}ElemType; 

//���Ա�ṹ--�����ʾ 
typedef struct{
	
	ElemType *elem;
	int length;
	int listsize;
	
}SqList; 

/*
ɾ�����е���С��Ԫ�أ������һ���油 
*/
//e��Ϊһ���������� 
bool Del_Min(SqList &l,ElemType &e); 

/*
�Ե����е�Ԫ�� 
*/
bool Reverse(SqList &l);

/*
ɾ��������ΪX��Ԫ�أ�Ҫ��ʱ�� Ϊ O��n�� �ռ临�Ӷ� O(1) 
*/
bool Del_X(SqList &l,Elemtype &e);

/*
ɾ�� s--t ֮���Ԫ�أ�lΪ����� 
*/
bool Del_sTot_OrderList(SqList &l,int s,int t); 

/*
ɾ�� s--t ֮���Ԫ�أ�lΪ˳��� 
*/
bool Del_sTot(SqList &l,int s,int t); 

int main()
{
	
    return 0;
}

bool Del_Min(SqList &l,ElemType &e){
	
	if(l.length==0) return false;//�ж��Ƿ�Ϊ�գ�����ǵĻ�ֹͣ
	
	e=l.elem[0];                 //�ٶ�Ϊ��СֵΪ��
	
	int pos=0;                     //��¼��СԪ�ص�λ�� 
	
	//�ҳ���С��Ԫ�� 
	for(int i=1;i<l.length;i++){
		
		if(e.element>l.elem[i].element){
			
			e.element=l.elem[i].element;
			pos=i; 
		}
		
	}
	
	
	//�����һλԪ�ص��� 
	l.elem[pos]=l.elem[l.length];
	l.length--;
	
	return true; 
	
} 

bool Reverse(SqList &l){
	
	if(l.length==0) return false;
	
	ElemType temp;
	for(int i=0;i<(l.length/2);i++){
		temp=l.elem[i];
		l.elem[i]=l.elem[l.length-i-1];//ע��Ҫ��1 
		l.elem[l.length-i-1]=temp;
	}
	
}

bool Del_X(SqList &l,Elemtype &e){
	int k=0;//��ͬ��e��Ԫ�� 
	
	for(int i=0;i<l.length;++i){
		
		if(l.elem[i].element!=e.element){
			l.elem[k]=l.elem[i].element;
			++k;
		}
	}
	
	l.length=k;
	
}

bool Del_sTot(SqList &l,int s,int t){
	
	int k=0;//������Ҫ��ĸ��� 
	
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































