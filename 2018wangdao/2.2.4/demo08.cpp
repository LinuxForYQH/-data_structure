//
// Created by hua on 17/4/25.
//

#include <iostream>


int A[]={1,2,3,4,5,0,9,8,7,6};



/**
 * 对调数组的位置
 * @param A 数组
 * @param right 右标志起始 lenght-1
 * @param left  左标志起始 0
 * @param size  总长度
 */
void Reverse(int A[],int left,int right,int size){

    if(right<left||size<=0)return;

    int mid=(right+left)/2;

    for(int i=0;mid-left>=i;i++){

        int temp=A[right-i];
        A[right-i]=A[left+i];
        A[left+i]=temp;

    }

}

/**
 * 把数组分成m n 两份 把数组改成  n  m 位置顺序
 */

void Exchange(int A[],int m,int n,int size){

    Reverse(A,0,m-1,size);
    Reverse(A,m,m+n-1,size);
    Reverse(A,0,m+n-1,size);

}

int main() {


    Exchange(A,5,5,10);

    for(int i=0;i<10;i++){

        printf("%d,", A[i]);

    }

    return 0;

}
