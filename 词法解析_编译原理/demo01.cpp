#include<stdio.h>    
#include<string.h>   
/*

Example Input

main() 
{
    int a, b;
    if(a == 10)
    {
        a = b;
    }
}


*/ 
int isDigit(char ch)    
{    
    if(ch>='0'&&ch<='9')    
        return 1;    
    else return 0;    
}    
    
int isLitter(char ch)    
{    
    if(ch>='a'&&ch<='z'||ch>='A'&&ch<='Z')    
        return 1;    
    else return 0;    
}    
    
int isKeyword(char tmp[])    
{    
    if(!strcmp(tmp,"main")|| !strcmp(tmp,"if") || !strcmp(tmp,"else") || !strcmp(tmp,"for") || !strcmp(tmp,"while") || !strcmp(tmp,"int"))    
        return 1;    
    else return 0;    
}    
void get()    
{    
    char ch;    
    int line=0;//����    
    char tmp[100];    
    int i=0;    
    while(~scanf("%c",&ch))    
    {    
        if(ch==' '||ch=='\t')//Ϊ�ո����tab    
            continue;    
        //�س�    
        else if(ch=='\n')    
            line++;    
        //�Ƿ��ǽ��    
        else if(ch=='('||ch==')'||ch=='{'||ch=='}'||ch==','||ch==';')    
            printf("(boundary,%c)\n",ch);    
    
        else if(isDigit(ch))//���������    
        {    
            while(isDigit(ch))    
            {    
                tmp[i++]=ch;    
                scanf("%c",&ch);    
            }    
            tmp[i]='\0';//���Ͻ�����    
            i=0;    
            printf("(integer,%s)\n",tmp);    
            ungetc(ch,stdin);//���ַ��˻ص���������    
        }    
        else if(isLitter(ch)||ch=='_')    
        {    
            while(isLitter(ch)||isDigit(ch)||ch=='_')    
            {    
                tmp[i++]=ch;    
                scanf("%c",&ch);    
            }    
            tmp[i]='\0';    
            i=0;    
            if(isKeyword(tmp))  //�ؼ���    
                printf("(keyword,%s)\n",tmp);    
            else            //�Զ����ʶ��    
                printf("(identifier,%s)\n",tmp);    
            ungetc(ch,stdin);    
        }    
    
        //�Ƿ��������    
        else    
        {    
            char c=ch;    
            // if(ch=='='||ch=='<'||ch=='>'||ch=='!')    
            // {    
            scanf("%c",&ch);    
            if(ch=='=')     //�ж��Ƿ��������ֽڲ�����    
                printf("(operator,%c=)\n",ch);    
            // }    
            // else    
            // {    
            else        //�����ֽڲ�����    
            {    
                printf("(operator,%c)\n",c);    
                ungetc(ch,stdin);    
            }    
        }    
    
    }    
}    
int main()    
{    
    get();    
}  
