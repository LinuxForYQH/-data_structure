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
    int line=0;//行数    
    char tmp[100];    
    int i=0;    
    while(~scanf("%c",&ch))    
    {    
        if(ch==' '||ch=='\t')//为空格或是tab    
            continue;    
        //回车    
        else if(ch=='\n')    
            line++;    
        //是否是界符    
        else if(ch=='('||ch==')'||ch=='{'||ch=='}'||ch==','||ch==';')    
            printf("(boundary,%c)\n",ch);    
    
        else if(isDigit(ch))//如果是数字    
        {    
            while(isDigit(ch))    
            {    
                tmp[i++]=ch;    
                scanf("%c",&ch);    
            }    
            tmp[i]='\0';//加上结束符    
            i=0;    
            printf("(integer,%s)\n",tmp);    
            ungetc(ch,stdin);//将字符退回到输入流中    
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
            if(isKeyword(tmp))  //关键字    
                printf("(keyword,%s)\n",tmp);    
            else            //自定义标识符    
                printf("(identifier,%s)\n",tmp);    
            ungetc(ch,stdin);    
        }    
    
        //是否是运算符    
        else    
        {    
            char c=ch;    
            // if(ch=='='||ch=='<'||ch=='>'||ch=='!')    
            // {    
            scanf("%c",&ch);    
            if(ch=='=')     //判断是否是两个字节操作符    
                printf("(operator,%c=)\n",ch);    
            // }    
            // else    
            // {    
            else        //单个字节操作符    
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
