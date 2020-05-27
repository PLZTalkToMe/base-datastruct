//
// Created by Administrator on 2020/5/24.
//

#ifndef BASE_DATASTRUCT_COMM_H
#define BASE_DATASTRUCT_COMM_H

#endif //BASE_DATASTRUCT_COMM_H

#define MaxSize 50
typedef int ElemType;

/////////////////////  structure  ///////////////////////////////////
typedef struct {
    ElemType data[MaxSize];
    int length;
}SqList;



typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;




//////////////////  method   /////////////////////////////
void printArray(ElemType arr[], int len){
    for (int j = 0; j < len; j++) {
        printf("%d ", arr[j]);
    }
    printf("\n");
}