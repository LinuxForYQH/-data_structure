//
// Created by hua on 17/4/25.
//

#include <iostream>


//线性表结构--数组表示
typedef struct{

    int elem[20]={1,2,3,4,5,6,7,8,9,10};
    int length;
    int listsize;

}SqList;

SqList A;
SqList B;
SqList C;

/**
 * 合并有序表A和有序表B到C
 * @param A
 * @param B
 * @param C
 */
bool Combine_A_B_To_C(SqList &A, SqList &B, SqList &C){


    //1.判断表A,B的长度是否超过c的总长度
    if(A.length+B.length>C.length) return false;

    //2.比较A和B中比较小的，加入C中
    int i=0; int j=0; int p=0;
    while (i<A.length&&j<B.length){

        if(A.elem[i]<B.elem[j]){
            C.elem[p++]=A.elem[i++];
        } else{

            C.elem[p++]=B.elem[j++];
        }
    }
    //3.1把A中剩下的加入C中
    while(i<A.length){
        C.elem[p++]=A.elem[i++];
    }
    //3.2把B中剩下的加入C中
    while (j<B.length){
        C.elem[p++]=B.elem[j++];
    }
    //4.确定C的长度
    C.length=p;

}



int main() {

    A.length=10;
    A.listsize=10;

    B.length=10;
    B.listsize=10;

    C.length=20;
    C.listsize=20;

    Combine_A_B_To_C(A,B,C);



    for(int k=0;k<C.length;k++){

        printf("%d,", C.elem[k]);

    }



    return 0;
}