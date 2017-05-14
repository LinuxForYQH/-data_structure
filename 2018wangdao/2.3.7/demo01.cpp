#include <iostream>

/**
 * 任务内容：
 * 设计一个递归算法，删除所有节点值为x的节点
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
 * 内容：递归删除节点值为x的节点
 *
 * 思路模型如下：
 *
 * 终止条件：不做其他处理  linkList->空
 *
 * 递归主体：删除节点      节点值等于X
 *          不做处理      节点值等于其他
 *
 *
 * 注意：指针传指针的时候，如果没有取别名那么指针指向的那一团都会临时赋值过去
 *
 * @param linkList 头节点
 * @param x 要删除的值
 * @return 返回完成删除后的头节点
 */
void DiguiShangchu(LinkList &linkList , int x){

    if(linkList==NULL){
        return ;
    }

    if(linkList->i==x){

        LinkList temp=linkList;

        linkList=linkList->next;

        free(temp);
        DiguiShangchu(linkList,x);
    }
    else
    {
        DiguiShangchu(linkList->next,x);

    }

}


int main() {

    LinkList linkList=CreateLinkList()->next;

    DiguiShangchu(linkList,2);

    while(linkList!=NULL){

        printf("%d,", linkList->i);

        linkList=linkList->next;

    }


    return 0;

}