#include <stdio.h>

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

//状态标识 
typedef struct{
	
	char str[5];
	
}Status; 

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

//初始化标识状态 
void Init_Status(); 

//初始化线性表 
Status InitList_Sq(SqList l);

//线性表插入操作   l为线性表 ， i为插入位置 （i的前面） ，e为要插入的元素 
Status ListInset_Sq(SqList l , int i , ElemType e);


Status OK;              //标识状态成功   tip：变量的定义最好放在外面，免得不小心忘记回收了，放在外面保证只初始化一次 
Status FAIL;            //标识状态失败 
Status ERROR;            //标识状态出错 
int OVERFLOW=-1;        //异常中断 -1 
ElemType *newbase;       //用于临时判断 
ElemType *q;             //用于循环 
ElemType *p;             //用于循环 

int main() {
	
	Init_Status();

	int* a=10; 
	int b=a;
    printf("Hello, World!\n");
    
    
    return 0;
    
}


//初始化标识状态 
void Init_Status(){
	strcpy(OK.str, "OK");
	strcpy(FAIL.str, "FAIL"); 
	strcpy(ERROR.str, "ERROR"); 
}

//初始化线性表 
Status InitList_Sq(SqList l){
	
	//构造一个空的线性表 
	l.elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));  
	if(!l.elem) exit(OVERFLOW);    //分配内存失败
	
	l.length=0;                    //空表长度为 0
	l.listsize= LIST_INIT_SIZE;    //初始化容量 
    
	return OK;
};


//线性表插入操作   l为线性表 ， i为插入位置 （i的前面） ，e为要插入的元素 
Status ListInset_Sq(SqList l , int i , ElemType e){
	
	
	//①检查i的数值是否合法 ，0<i<l.length+1 
	//②查看l的已有长度是否超出+1的长度，即  l.length>=l.listsize ，如果超出则重新分配地址l.listsize+=LISTINCREMENT;
	//③把[i-1]后面的元素向后移一位
	//④插入元素， l.length++
	
	//①
	if(!(0<i<l.length+1)) return ERROR; 
	
	//②
	if(l.length>=l.listsize){
	
	  newbase=realloc(l.elem,(l.listsize+LISTINCREMENT)*sizeof(ElemType));
	  if(!newbase) exit(OVERFLOW); 
	  l.elem=newbase;
	  l.listsize+=LISTINCREMENT;
	}
	//③
	q=&l.elem[i-1] ;
	for(p=&l.elem[l.length-1];q<=p;--p){
		*(p+1)=*p;
	}
	//④
	*q=e;
	++l.length;
	
	return OK;
};
