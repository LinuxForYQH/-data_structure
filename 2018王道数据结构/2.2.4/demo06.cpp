//
// Created by hua on 17/4/25.
//

#include <iostream>


//线性表结构--数组表示
typedef struct{

    int elem[10]={1,2,3,4,5,6,7,8,8,9};
    int length;
    int listsize;

}SqList;

SqList sqList;

/**
 * 删除有序表中相同的元素，使得有序表内的元素均不同
 * @param sqList
 *
 */
void Del_d_inSqList(SqList &sqList){

    if(sqList.length<2) return;

    int p=0;
    int temp=sqList.elem[0];

    for(int i=1;i<sqList.length;i++){

        if(temp!=sqList.elem[i]){
            sqList.elem[++p]=sqList.elem[i];
            temp=sqList.elem[i];
        }
    }

    sqList.length=p+1;

}



int main() {

    sqList.length=10;
    sqList.listsize=10;

    Del_d_inSqList(sqList);

    for(int k=0;k<sqList.length;k++){

        printf("%d,", sqList.elem[k]);

    }



    return 0;
}