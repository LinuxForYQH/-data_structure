#include<stdio.h>
#include<ctype.h>

#define STACK_INIT_SIZE 100 // �洢�ռ�ĳ�ʼ������
#define STACKINCREMENT 10 //�洢�ռ������ 

//״̬��ʶ 
typedef struct{
	
	char str[5];
	
}Status; 

//��ʼ����ʶ״̬ 
void Init_Status(); 


//INTջ�е�Ԫ�� 
typedef struct{
	
	int element; 
	
}IntElemType; 

//INTջ��ADT 
typedef struct{
	
	IntElemType *base;//��ջ����֮ǰ������֮��baseָ��Ϊnull��
	IntElemType *top;//ջ��ָ��
	int stacksize;//ջ���ܳ��� 
	
}IntStack; 


 //INT��ʼ��ջ
 Status InitStack_INT(IntStack *s);
 //INT��ȡջ��ͷԪ�� 
 Status GetTop_INT(IntStack s,IntElemType *e);
 //INT����eԪ�ص�ջ�� 
 Status Push_INT(IntStack *s,IntElemType e);
 //INT��ջ��Ϊ��ɾ��ջ��Ԫ�أ�����e���أ����򷵻�ERROR 
 Status Pop_INT(IntStack *s,IntElemType *e);



//CHARջ�е�Ԫ�� 
typedef struct{
	
	char element; 
	
}CharElemType; 

//CHARջ��ADT 
typedef struct{
	
	CharElemType *base;//��ջ����֮ǰ������֮��baseָ��Ϊnull��
	CharElemType *top;//ջ��ָ��
	int stacksize;//ջ���ܳ��� 
	
}CharStack; 

 //CHAR��ʼ��ջ
 Status InitStack_CHAR(CharStack *s);
 //CHAR��ȡջ��ͷԪ�� 
 Status GetTop_CHAR(CharStack s,CharElemType *e);
 //CHAR����eԪ�ص�ջ�� 
 Status Push_CHAR(CharStack *s,CharElemType e);
 //CHAR��ջ��Ϊ��ɾ��ջ��Ԫ�أ�����e���أ����򷵻�ERROR 
 Status Pop_CHAR(CharStack *s,CharElemType *e);



//����������������� > < = , a1 a2��ʾ������̳��ֵ������ ��a1<a2��ʾa1����������ȼ�����a2�Դ����� 
char Precede(char a1,char a2);
 
//�����������ֺ�һ�������ַ�������󷵻ؼ����ֵ 
int Operate(int a1,char thete,int a2);
  
//���ʽ��������� 
Status EvaluateExpression();
  
//�������봮������������
int In(char *c,IntElemType *OP);


  
Status OK;              //��ʶ״̬�ɹ�   tip�������Ķ�����÷������棬��ò�С�����ǻ����ˣ��������汣ֻ֤��ʼ��һ�� 
Status FAIL;            //��ʶ״̬ʧ�� 
Status ERROR;            //��ʶ״̬���� 
int OVERFLOW=-1;        //�쳣�ж� -1 

IntStack OPND; 
CharStack OPTR;


int main()
{

    EvaluateExpression();
    
    return 1;
}


//��ʼ����ʶ״̬ 
void Init_Status(){
	strcpy(OK.str, "OK");
	strcpy(FAIL.str, "FAIL"); 
	strcpy(ERROR.str, "ERROR"); 
}


 //INT��ʼ��ջ
Status InitStack_INT(IntStack *s) {
	
	(*s).base=(IntElemType *)malloc(STACK_INIT_SIZE*sizeof(IntElemType));
	if(!(*s).base) exit(OVERFLOW);
	(*s).top=(*s).base;
	(*s).stacksize=STACK_INIT_SIZE;
	return OK;
	
}

 //INT��ȡջ��ͷԪ�� 
 Status GetTop_INT(IntStack s,IntElemType *e){
 	
	//��ջ��Ϊ�գ�����e����S��ջ��Ԫ�ز�����OK����֮����ʾ���� ERROR
 	if(s.top==s.base) return ERROR;
	(*e)=*(s.top-1);
	
	return OK;
 	
 }

 //INT����eԪ�ص�ջ�� 
 Status Push_INT(IntStack *s,IntElemType e){
 	
 	//���ջ�Ƿ����������top��ֵ��top++ 
 	
	 if((*s).top-(*s).base>=(*s).stacksize){
	 	
	 	//tip   realloc�������·����ԭ����ָ����ܻ������Ҫ����ָ�� 
	 	(*s).base=(IntElemType *)realloc((*s).base,(STACKINCREMENT+(*s).stacksize)*sizeof(IntElemType));
	 	
	 	if(!(*s).base) exit(OVERFLOW);
	 	
	 	(*s).top=(*s).base+(*s).stacksize;
	 	
	 }
	 
	 *(*s).top++ =e; //tip X++=Y��X��ֵ����Լ� 
	 
	 return OK; 
 	
 }

 //INT��ջ��Ϊ��ɾ��ջ��Ԫ�أ�����e���أ����򷵻�ERROR 
 Status Pop_INT(IntStack *s,IntElemType *e){
 	
 	if((*s).top==(*s).base) return ERROR;
 	
 	(*e)=(*(--(*s).top));
 	
 	return OK;
 	
 }



//CHAR��ʼ��ջ
Status InitStack_CHAR(CharStack *s) {
	
	(*s).base=(CharElemType *)malloc(STACK_INIT_SIZE*sizeof(CharElemType));
	if(!(*s).base) exit(OVERFLOW);
	(*s).top=(*s).base;
	(*s).stacksize=STACK_INIT_SIZE;
	return OK;
	
}

 //CHAR��ȡջ��ͷԪ�� 
 Status GetTop_CHAR(CharStack s,CharElemType *e){
 	
 	
 	//��ջ��Ϊ�գ�����e����S��ջ��Ԫ�ز�����OK����֮����ʾ���� ERROR
 	if(s.top==s.base) return ERROR;
	(*e)=*(s.top-1);
	
	return OK;
 	
 }

 //CHAR����eԪ�ص�ջ�� 
 Status Push_CHAR(CharStack *s,CharElemType e){
 	
 	//���ջ�Ƿ����������top��ֵ��top++ 
 	
	 if((*s).top-(*s).base>=(*s).stacksize){
	 	
	 	//tip   realloc�������·����ԭ����ָ����ܻ������Ҫ����ָ�� 
	 	(*s).base=(CharElemType *)realloc((*s).base,(STACKINCREMENT+(*s).stacksize)*sizeof(CharElemType));
	 	
	 	if(!(*s).base) exit(OVERFLOW);
	 	
	 	(*s).top=(*s).base+(*s).stacksize;
	 	
	 }
	 
	 *(*s).top++ =e; //tip X++=Y��X��ֵ����Լ� 
	 
	 return OK; 
 	
 }

 //CHAR��ջ��Ϊ��ɾ��ջ��Ԫ�أ�����e���أ����򷵻�ERROR 
 Status Pop_CHAR(CharStack *s,CharElemType *e){
 	
 	if((*s).top==(*s).base) return ERROR;
 	
 	(*e)=(*(--(*s).top));
 	
 	return OK;
 	
 }




 //����������������� > < = , a1 a2��ʾ������̳��ֵ������ ��a1<a2��ʾa1����������ȼ�����a2�Դ����� 
 char Precede(char a1,char a2){
 
 char operator[]={'+','-','*','/','(',')','#'};
 
 //��̳��ֵ� a1 a2 �����ȼ���ϵ�� 
 //������������� > < = , a1 a2��ʾ������̳��ֵ������ ��a1<a2��ʾa1����������ȼ�����a2�Դ�����  
 // + - * / ( ) #  Ϊ��ĺ����� 
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

 //�����������ֺ�һ�������ַ�������󷵻ؼ����ֵ 
  int Operate(int a1,char thete,int a2){
  
  if(thete=='+') return a1+a2;
  
  if(thete=='-') return a1-a2;
  
  if(thete=='*') return a1*a2;
  
  if(thete=='/') return a1/a2;
  
  } 

//�������봮������������
int In(char *c,IntElemType *OP){
	
	if(!isdigit(*c)) return 0; //�������������ôֱ�ӵ������������� 
	
	ungetc((*c),stdin); // ��һ���ַ��˻�������
	
	int i=0;
	
	// ��ȡ�ַ�ֱ���������������߷������ַ�
    while(((*c) = getchar()) != EOF && isdigit((*c)))
    {
        i = 10 * i + (*c) - 48;  // תΪ����
    }
	
	ungetc((*c),stdin); // ��һ���������ַ��˻�������
	
	(*OP).element=i;
	return 1; 
}


//���ʽ��������� 
Status EvaluateExpression(){
	
	CharElemType began; began.element='#';//��ʼ�Ĳ����� 
	InitStack_CHAR(&OPTR);
	Push_CHAR(&OPTR,began);
	
	InitStack_INT(&OPND);
	char c=getchar( );
	
	CharElemType top;
	GetTop_CHAR(OPTR,&top);
	
	IntElemType OP;//�ַ����н������������� 
	
	//��ʱ����
	CharElemType temp; 
	IntElemType temp1;IntElemType temp2;
	int a1;int a2;char thete;
	
	
	while(c!='#'||top.element!='#'){
		
		if(In(&c,&OP)==1){
			Push_INT(&OPND,OP);//������ѹ��Intջ�� 
			c=getchar();
		}else{
			
			GetTop_CHAR(OPTR,&top);//��ȡ�ȽϵĽ�� 

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
					Push_INT(&OPND,temp1);//�Ѽ��������ѹ��Intջ�� 
					GetTop_CHAR(OPTR,&top);
				
			}
			
			
		}
		
		
		
	}
	
	
	GetTop_INT(OPND,&temp1);
	printf(" ���= %d", temp1.element);
	
	return OK;
	
};















