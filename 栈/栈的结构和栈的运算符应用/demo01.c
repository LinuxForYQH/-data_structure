#include<stdio.h>
#include<ctype.h>

#define STACK_INIT_SIZE 100 // 存储空间的初始化变量
#define STACKINCREMENT 10 //存储空间的增量 

//状态标识 
typedef struct{
	
	char str[5];
	
}Status; 

//初始化标识状态 
void Init_Status(); 


//INT栈中的元素 
typedef struct{
	
	int element; 
	
}IntElemType; 

//INT栈的ADT 
typedef struct{
	
	IntElemType *base;//在栈构造之前和销毁之后，base指针为null；
	IntElemType *top;//栈顶指针
	int stacksize;//栈的总长度 
	
}IntStack; 


 //INT初始化栈
 Status InitStack_INT(IntStack *s);
 //INT获取栈的头元素 
 Status GetTop_INT(IntStack s,IntElemType *e);
 //INT插入e元素到栈顶 
 Status Push_INT(IntStack *s,IntElemType e);
 //INT若栈不为空删除栈顶元素，并用e返回；否则返回ERROR 
 Status Pop_INT(IntStack *s,IntElemType *e);



//CHAR栈中的元素 
typedef struct{
	
	char element; 
	
}CharElemType; 

//CHAR栈的ADT 
typedef struct{
	
	CharElemType *base;//在栈构造之前和销毁之后，base指针为null；
	CharElemType *top;//栈顶指针
	int stacksize;//栈的总长度 
	
}CharStack; 

 //CHAR初始化栈
 Status InitStack_CHAR(CharStack *s);
 //CHAR获取栈的头元素 
 Status GetTop_CHAR(CharStack s,CharElemType *e);
 //CHAR插入e元素到栈顶 
 Status Push_CHAR(CharStack *s,CharElemType e);
 //CHAR若栈不为空删除栈顶元素，并用e返回；否则返回ERROR 
 Status Pop_CHAR(CharStack *s,CharElemType *e);



//输入两个运算符生成 > < = , a1 a2表示两个相继出现的运算符 ，a1<a2表示a1的运算符优先级大于a2以此类推 
char Precede(char a1,char a2);
 
//输入两个数字和一个运算字符，计算后返回计算的值 
int Operate(int a1,char thete,int a2);
  
//表达式的运算过程 
Status EvaluateExpression();
  
//解析输入串中连续的数字
int In(char *c,IntElemType *OP);


  
Status OK;              //标识状态成功   tip：变量的定义最好放在外面，免得不小心忘记回收了，放在外面保证只初始化一次 
Status FAIL;            //标识状态失败 
Status ERROR;            //标识状态出错 
int OVERFLOW=-1;        //异常中断 -1 

IntStack OPND; 
CharStack OPTR;


int main()
{

    EvaluateExpression();
    
    return 1;
}


//初始化标识状态 
void Init_Status(){
	strcpy(OK.str, "OK");
	strcpy(FAIL.str, "FAIL"); 
	strcpy(ERROR.str, "ERROR"); 
}


 //INT初始化栈
Status InitStack_INT(IntStack *s) {
	
	(*s).base=(IntElemType *)malloc(STACK_INIT_SIZE*sizeof(IntElemType));
	if(!(*s).base) exit(OVERFLOW);
	(*s).top=(*s).base;
	(*s).stacksize=STACK_INIT_SIZE;
	return OK;
	
}

 //INT获取栈的头元素 
 Status GetTop_INT(IntStack s,IntElemType *e){
 	
	//若栈不为空，则用e返回S的栈顶元素并返回OK，反之则提示出错 ERROR
 	if(s.top==s.base) return ERROR;
	(*e)=*(s.top-1);
	
	return OK;
 	
 }

 //INT插入e元素到栈顶 
 Status Push_INT(IntStack *s,IntElemType e){
 	
 	//检查栈是否有溢出，给top赋值，top++ 
 	
	 if((*s).top-(*s).base>=(*s).stacksize){
	 	
	 	//tip   realloc函数重新分配后原来的指针可能会变所以要重新指向 
	 	(*s).base=(IntElemType *)realloc((*s).base,(STACKINCREMENT+(*s).stacksize)*sizeof(IntElemType));
	 	
	 	if(!(*s).base) exit(OVERFLOW);
	 	
	 	(*s).top=(*s).base+(*s).stacksize;
	 	
	 }
	 
	 *(*s).top++ =e; //tip X++=Y在X赋值后才自加 
	 
	 return OK; 
 	
 }

 //INT若栈不为空删除栈顶元素，并用e返回；否则返回ERROR 
 Status Pop_INT(IntStack *s,IntElemType *e){
 	
 	if((*s).top==(*s).base) return ERROR;
 	
 	(*e)=(*(--(*s).top));
 	
 	return OK;
 	
 }



//CHAR初始化栈
Status InitStack_CHAR(CharStack *s) {
	
	(*s).base=(CharElemType *)malloc(STACK_INIT_SIZE*sizeof(CharElemType));
	if(!(*s).base) exit(OVERFLOW);
	(*s).top=(*s).base;
	(*s).stacksize=STACK_INIT_SIZE;
	return OK;
	
}

 //CHAR获取栈的头元素 
 Status GetTop_CHAR(CharStack s,CharElemType *e){
 	
 	
 	//若栈不为空，则用e返回S的栈顶元素并返回OK，反之则提示出错 ERROR
 	if(s.top==s.base) return ERROR;
	(*e)=*(s.top-1);
	
	return OK;
 	
 }

 //CHAR插入e元素到栈顶 
 Status Push_CHAR(CharStack *s,CharElemType e){
 	
 	//检查栈是否有溢出，给top赋值，top++ 
 	
	 if((*s).top-(*s).base>=(*s).stacksize){
	 	
	 	//tip   realloc函数重新分配后原来的指针可能会变所以要重新指向 
	 	(*s).base=(CharElemType *)realloc((*s).base,(STACKINCREMENT+(*s).stacksize)*sizeof(CharElemType));
	 	
	 	if(!(*s).base) exit(OVERFLOW);
	 	
	 	(*s).top=(*s).base+(*s).stacksize;
	 	
	 }
	 
	 *(*s).top++ =e; //tip X++=Y在X赋值后才自加 
	 
	 return OK; 
 	
 }

 //CHAR若栈不为空删除栈顶元素，并用e返回；否则返回ERROR 
 Status Pop_CHAR(CharStack *s,CharElemType *e){
 	
 	if((*s).top==(*s).base) return ERROR;
 	
 	(*e)=(*(--(*s).top));
 	
 	return OK;
 	
 }




 //输入两个运算符生成 > < = , a1 a2表示两个相继出现的运算符 ，a1<a2表示a1的运算符优先级大于a2以此类推 
 char Precede(char a1,char a2){
 
 char operator[]={'+','-','*','/','(',')','#'};
 
 //相继出现的 a1 a2 的优先级关系表 
 //两个运算符生成 > < = , a1 a2表示两个相继出现的运算符 ，a1<a2表示a1的运算符优先级大于a2以此类推  
 // + - * / ( ) #  为表的横竖列 
 char precede_table[7][7]={
 	 {'>','>','<','<','<','>','>'},
	 {'>','>','<','<','<','>','>'},
	 {'>','>','>','>','<','>','>'},
	 {'>','>','>','>','<','>','>'},
	 {'<','<','<','<','<','=',' '},
	 {'>','>','>','>',' ','>','>'},
	 {'<','<','<','<','<',' ','='}
 };
 
 int b1;int b2;
 
 for(b1=0;b1<6;b1++){
 	if(operator[b1]==a1) break;
 }
  for(b2=0;b2<6;b2++){
 	if(operator[b2]==a2) break;
 }
 
 return precede_table[b1][b2];
 
 } 

 //输入两个数字和一个运算字符，计算后返回计算的值 
  int Operate(int a1,char thete,int a2){
  
  if(thete=='+') return a1+a2;
  
  if(thete=='-') return a1-a2;
  
  if(thete=='*') return a1*a2;
  
  if(thete=='/') return a1/a2;
  
  } 

//解析输入串中连续的数字
int In(char *c,IntElemType *OP){
	
	if(!isdigit(*c)) return 0; //如果不是数字那么直接调到操作符处理 
	
	ungetc((*c),stdin); // 把一个字符退回输入流
	
	int i=0;
	
	// 读取字符直到遇到结束符或者非数字字符
    while(((*c) = getchar()) != EOF && isdigit((*c)))
    {
        i = 10 * i + (*c) - 48;  // 转为整数
    }
	
	ungetc((*c),stdin); // 把一个非数字字符退回输入流
	
	(*OP).element=i;
	return 1; 
}


//表达式的运算过程 
Status EvaluateExpression(){
	
	CharElemType began; began.element='#';//开始的操作符 
	InitStack_CHAR(&OPTR);
	Push_CHAR(&OPTR,began);
	
	InitStack_INT(&OPND);
	char c=getchar( );
	
	CharElemType top;
	GetTop_CHAR(OPTR,&top);
	
	IntElemType OP;//字符串中解析出来的数字 
	
	//临时变量
	CharElemType temp; 
	IntElemType temp1;IntElemType temp2;
	int a1;int a2;char thete;
	
	
	while(c!='#'||top.element!='#'){
		
		if(In(&c,&OP)==1){
			Push_INT(&OPND,OP);//把数字压入Int栈中 
			c=getchar();
		}else{
			
			GetTop_CHAR(OPTR,&top);//获取比较的结果 

			switch (Precede(top.element,c)) {
				
				case'<':
					temp.element=c; 
					Push_CHAR(&OPTR,temp);
					GetTop_CHAR(OPTR,&top);
					c=getchar();
					break;
				case'=':
					Pop_CHAR(&OPTR,&temp);
					GetTop_CHAR(OPTR,&top);
					c=getchar();
					break;
				case'>':
					Pop_CHAR(&OPTR,&temp);
					Pop_INT(&OPND,&temp1);Pop_INT(&OPND,&temp2);
					thete=temp.element;
					a1=temp1.element;a2=temp2.element;
					temp1.element=Operate(a1,thete,a2);
					Push_INT(&OPND,temp1);//把计算的数字压入Int栈中 
					GetTop_CHAR(OPTR,&top);
				
			}
			
			
		}
		
		
		
	}
	
	
	GetTop_INT(OPND,&temp1);
	printf(" 结果= %d", temp1.element);
	
	return OK;
	
};















