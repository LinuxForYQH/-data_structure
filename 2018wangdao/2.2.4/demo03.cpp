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
 * 删除顺序表中的元素，要求时间复杂度为（n）和空间复杂度（1）
 * @param sqList
 * @param i 要删除的元素
 */
void Del_x_inSqList(SqList &sqList, int i){


    int pos=0;

    for(int k=0;k<sqList.length;k++){

        if(sqList.elem[k]!=i){
            sqList.elem[pos]=sqList.elem[k];
            pos++;
        }
    }

    sqList.length=pos;

}



int main() {

    sqList.length=10;
    sqList.listsize=10;

    Del_x_inSqList(sqList,2);

    for(int k=0;k<sqList.length;k++){

        printf("%d,", sqList.elem[k]);

    }



    return 0;
}