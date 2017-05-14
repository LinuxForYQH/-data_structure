//
// Created by hua on 17/4/25.
//

#include <iostream>


//线性表结构--数组表示
typedef struct{

    int elem[10]={1,2,3,4,5,6,7,8,9,10};
    int length;
    int listsize;

}SqList;

SqList sqList;


/**
 * 删除顺序表中的  s<x<t 的元素
 * @param sqList  顺序表
 * @param s   s
 * @param t   t
 */
bool Del_s_t_inOderList(SqList &sqList,int s,int t){


    //判断参数
    if(s>=t||sqList.length<=0)return false;

    //找到大于s元素的位置
    int k=0;
    for(;k<sqList.length;k++){
        if(sqList.elem[k]>s) break;
    }
    //如果没有那么停止
    if (k==sqList.length) return false;

    //找到小于t的元素
    int i=sqList.length-1;
    for(;i>k;i--){
        if(sqList.elem[i]<t) break;
    }

    //替换
    for(;i<sqList.length-1;i++){
        sqList.elem[k]=sqList.elem[i+1];
        k++;
    }
    sqList.length=k;

}




int main() {

    sqList.length=10;
    sqList.listsize=10;

    Del_s_t_inOderList(sqList,3,6);

    for(int k=0;k<sqList.length;k++){

        printf("%d,", sqList.elem[k]);

    }



    return 0;
}