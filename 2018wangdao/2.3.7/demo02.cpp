#include <iostream>

/**
 * 任务内容：
 * 设计一个带头节点的链表，删除节点值为x的元素，且释放空间
 */

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


/**
 * 一般有两种处理方式
 * 1.遍历链表找到该节点，修改指针的指向，删除节点释放空间
 * 2.头插建链表法
 *
 * 实现 方法 2
 *
 * @param linkList 带头节点
 * @param x
 */
void shangchu_x(LinkList &linkList,int x){

    LinkList head=(LinkList) malloc(sizeof(LNode));
    head->next=NULL;

    linkList=linkList->next;

    while(linkList!=NULL){

        if(linkList->i==x){

            LinkList tem=linkList;

            linkList=linkList->next;

            free(tem);

        } else{

            LinkList temp=linkList->next;
            linkList->next=head->next;
            head->next=linkList;
            linkList=temp;

        }
    }

    linkList=head;

}


int main() {

    LinkList linkList1;
    LinkList linkList=CreateLinkList();

    shangchu_x(linkList,3);

    while(linkList!=NULL){

        printf("%d,", linkList->i);

        linkList=linkList->next;

    }


    return 0;

}