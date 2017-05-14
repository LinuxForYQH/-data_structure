#include <iostream>


typedef struct LNode{

    int i=0;
    struct LNode *next;

} LNode , *LinkList;

//初始化链表
LinkList CreateLinkList(){

    LinkList linkList= (LinkList) malloc(sizeof(LNode));

    linkList->next=NULL;

    int num[]={0,1,2,3,4,5,6,7,8,9};

    LinkList temp=linkList;

    for(int i=0;i<10;i++){

        LinkList current= (LinkList) malloc(sizeof(LNode));
        current->next=NULL;
        current->i=num[i];

        temp->next=current;

        temp=current;

    }

    return linkList;
}


int main() {

    LinkList linkList=CreateLinkList()->next;

    while(linkList!=NULL){

        printf("%d,", linkList->i);

        linkList=linkList->next;

    }


    return 0;

}