#include "comm.h"

/**
 * ���ݹ顿ɾ����������e
 */
void e01(LinkList &L, ElemType e){
    LNode *p;
    if(L == NULL){
        return;
    }

    if(L -> data == e){
        p = L;
        L = L -> next;
        free(p);
        e01(L, e);
    }else{
        e01(L -> next, e);
    }
}



void e02(LinkList &L, ElemType e){
    LNode* dataNode = L -> next;
    while(dataNode->next){
        if(dataNode->next->data == e){
            LNode *p = dataNode->next;
            dataNode ->next = dataNode->next->next;
            free(p);
        }
        dataNode = dataNode -> next;
    }
}



/**
 * �������L
 * @param L
 * @param e
 */
void e03(LinkList &L){
    if(!L){
        return ;
    }
    e03(L);
    printf("%d \t", L->data);
}


/**
 * ɾ����Сֵ�ڵ�
 * ��ͷ���
 * @param L
 */
void e04(LinkList &L){
    LNode *prior = L, *next;
    ElemType min = L->next->data;
    while(prior){
        if(prior->data > min){
            prior = prior -> next;

        }
    }
}


int main(){

}