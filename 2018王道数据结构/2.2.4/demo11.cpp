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

typedef struct{

    int elem[20]={3,4,5,6,7,8,9,11,15};
    int length=10;
    int listsize=20;

}SqList_B;



SqList A;
SqList_B B;


/**
 * 给定A 和 B 两个有序表 ，A和B的长度相等 要求找出中位数
 * @param A  有序表
 * @param B  有序表
 * @return
 */
int find_mid(SqList &A,SqList_B &B){

    int low_a=0 , high_a=A.length-1 , mid_a;
    int low_b=0 , high_b=B.length-1 , mid_b;

    //思路：1️⃣  如果[mid_a]==[mid_b]  2️⃣  如果mid_a<mid_b 那么舍弃 mid_a前面的和mid_b后面的
    //     3️⃣  如果mid_a>mid_b 那么舍弃mid_a后面的和mid_b前面的
    //1.在循环处理过程中要注意如何保持A B 表等长
    //2.注意到最后剩下的两个中必定会有一个是中位数


    while (low_a<=high_a&&low_b<=high_b){

        mid_a=(low_a+high_a)/2;
        mid_b=(low_b+high_b)/2;


        if(A.elem[mid_a]==B.elem[mid_b]) break;


        if(A.elem[mid_a]>B.elem[mid_b]){


            if((low_a+high_a)%2==0) //当元素的个数为奇数的时候 去除A的右边保留中间点 去除B点左边保留中间点
            {
                high_a=mid_a;
                low_b=mid_b;
            }
            else   //当元素个数为偶数的时候  去除A的右边且不留中间点 去除B点左边且不留中间点
            {
                high_a=mid_a;
                low_b=mid_b+1;
            }
        }


        if(A.elem[mid_a]<B.elem[mid_b]){

            if((low_a+high_a)%2==0){

                high_b=mid_b;
                low_a=mid_a;

            }
            else
            {
                high_b=mid_b;
                low_a=mid_a+1;
            }
        }
    }


    return A.elem[mid_a]>B.elem[mid_b]?B.elem[mid_b] : A.elem[mid_a];





}



int main() {



    int i=find_mid(A,B);
    printf("%d,", i);



    return 0;
}