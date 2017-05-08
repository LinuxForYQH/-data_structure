//
// Created by hua on 17/4/25.
//

#include <iostream>


//线性表结构--数组表示
typedef struct{

    int elem[20]={1,2,3,4,5,6,7,8,9,10};
    int length=10;
    int listsize=20;

}SqList;

SqList A;


/**
 * 找到和i值相等的元素，如果找到在则在该位置上后面一个元素更换值，
 * 如果找不到，依然在某个位置插入使得链表为有序
 * @param A  有序表
 * @param i
 * @return
 */
bool SearchExchangeInsert(SqList &A,int i){

    //1.※二分查找在找不到的时候[low==high]再来一次，这个时候[high]和[low]对应的值一定是大于i
    //接下来再继续一次循环，导致high减一

    int high=A.length , low=0 , mid ;

    while(low<=high){

        mid=(high+low)/2;
        if(A.elem[mid]==i) break;

        if(A.elem[mid]>i){
            high=mid-1;
        } else{
            low=mid+1;
        }

    }

    //2.判断是否找到，或者是否找到在最后一位
    if(A.elem[mid]==i&&mid!=(A.length-1)){

        A.elem[mid+1]=i;

    }

    //3.如果没有找到开始插入，由1可知此时的[high]是小于i，[high+1]是大于i
    //在进行插入式先判断一下是否有溢出，没有就开始移动元素开始插入
    if(low>high){

        if(A.length+1>A.listsize) return false;

        for(int k=A.length-1;k>high;k--){
            A.elem[k+1]=A.elem[k];
        }

        A.elem[mid]=i;
    }


}



int main() {


    SearchExchangeInsert(A,4);



    for(int k=0;k<A.length;k++){

        printf("%d,", A.elem[k]);

    }



    return 0;
}