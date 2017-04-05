#include <stdio.h>

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

//״̬��ʶ 
typedef struct{
	
	char str[5];
	
}Status; 

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

//��ʼ����ʶ״̬ 
void Init_Status(); 

//��ʼ�����Ա� 
Status InitList_Sq(SqList l);

//���Ա�������   lΪ���Ա� �� iΪ����λ�� ��i��ǰ�棩 ��eΪҪ�����Ԫ�� 
Status ListInset_Sq(SqList l , int i , ElemType e);


Status OK;              //��ʶ״̬�ɹ�   tip�������Ķ�����÷������棬��ò�С�����ǻ����ˣ��������汣ֻ֤��ʼ��һ�� 
Status FAIL;            //��ʶ״̬ʧ�� 
Status ERROR;            //��ʶ״̬���� 
int OVERFLOW=-1;        //�쳣�ж� -1 
ElemType *newbase;       //������ʱ�ж� 
ElemType *q;             //����ѭ�� 
ElemType *p;             //����ѭ�� 

int main() {
	
	Init_Status();

	int* a=10; 
	int b=a;
    printf("Hello, World!\n");
    
    
    return 0;
    
}


//��ʼ����ʶ״̬ 
void Init_Status(){
	strcpy(OK.str, "OK");
	strcpy(FAIL.str, "FAIL"); 
	strcpy(ERROR.str, "ERROR"); 
}

//��ʼ�����Ա� 
Status InitList_Sq(SqList l){
	
	//����һ���յ����Ա� 
	l.elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));  
	if(!l.elem) exit(OVERFLOW);    //�����ڴ�ʧ��
	
	l.length=0;                    //�ձ���Ϊ 0
	l.listsize= LIST_INIT_SIZE;    //��ʼ������ 
    
	return OK;
};


//���Ա�������   lΪ���Ա� �� iΪ����λ�� ��i��ǰ�棩 ��eΪҪ�����Ԫ�� 
Status ListInset_Sq(SqList l , int i , ElemType e){
	
	
	//�ټ��i����ֵ�Ƿ�Ϸ� ��0<i<l.length+1 
	//�ڲ鿴l�����г����Ƿ񳬳�+1�ĳ��ȣ���  l.length>=l.listsize ��������������·����ַl.listsize+=LISTINCREMENT;
	//�۰�[i-1]�����Ԫ�������һλ
	//�ܲ���Ԫ�أ� l.length++
	
	//��
	if(!(0<i<l.length+1)) return ERROR; 
	
	//��
	if(l.length>=l.listsize){
	
	  newbase=realloc(l.elem,(l.listsize+LISTINCREMENT)*sizeof(ElemType));
	  if(!newbase) exit(OVERFLOW); 
	  l.elem=newbase;
	  l.listsize+=LISTINCREMENT;
	}
	//��
	q=&l.elem[i-1] ;
	for(p=&l.elem[l.length-1];q<=p;--p){
		*(p+1)=*p;
	}
	//��
	*q=e;
	++l.length;
	
	return OK;
};
