//
// Created by hua on 17/4/25.
//

#include <iostream>


//线性表结构--数组表示
typedef struct{

    int elem[10]={1,2,3,4,5,0,9,8,7,6};
    int length;
    int listsize;

}SqList;

SqList sqList;


/**
 * 找到数组中最小的元素用最后一位替换
 * @param sqList 线性结构
 * @param i 反回删除的值
 * @return
 */
bool Del_Min(SqList &sqList,int &i){

    if(sqList.length<=0) return false;

    int m=sqList.elem[0];//假设第一个为最小元素
    int p=0;

    //找到最小元素
    for(int k=0;k<sqList.length;k++){

        if(sqList.elem[k]<m) {
            m=sqList.elem[k];
            p=k;
        }
    }

    sqList.elem[p]=sqList.elem[sqList.length-1];
    sqList.length--;

    i=m;

}





int main() {

    sqList.length=10;
    sqList.listsize=10;

    int i;

    Del_Min(sqList,i);

    for(int k=0;k<10;k++){

        printf("%d,", sqList.elem[k]);

    }

    return 0;
}