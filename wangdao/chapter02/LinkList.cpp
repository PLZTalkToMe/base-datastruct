#include "comm.h"


/**
 * 头插法
 * @param L
 * @return
 */
LinkList List_HeadInsert(LinkList &L){
    LNode *s;
    int x;
    L = (LinkList) malloc(sizeof(LNode));
    L -> next = NULL;
    scanf("%d", &x);
    while(x != 9999){
        s = (LNode *) malloc(sizeof(LNode));
        s -> data = x;
        s ->next = L->next;
        L ->next = s;
        scanf("%d", x);
    }
    return L;
}


/**
 * 尾插法
 * @param L
 * @return
 */
LinkList List_TailInsert(LinkList &L){
    int x;
    L = (LinkList) malloc(sizeof(LNode));
    LNode *s, *r = L;
    scanf("%d", &x);
    while(x != 9999){
        s = (LNode *)malloc(sizeof(LNode));
        s -> data = x;
        // 将s加到尾指针后面
        r -> next = s;
        // 将r指向新的尾节点
        r = s;
    }
    r -> next = NULL;
    return L;
}


LNode* GetElem(LinkList L, int i){
    int j = 1;

    LNode* p = L -> next;

    if(i == 0){
        return L;
    }
    if(i < 0){
        return NULL;
    }

    while(p && j < i){
        p=p->next;
        j++;
    }
    return p;
}


/**
 * 定位文件的值
 * @param L
 * @param e
 * @return
 */
LNode* LocateElem(LinkList &L, ElemType e){
    LNode* p = L -> next;
    while(p->next && p->data != e){
        p = p ->next;
    }
    return p;
}





int main(){

}

