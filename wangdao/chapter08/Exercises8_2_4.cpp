#include <cstdio>
#include <cstdlib>

void InsertSort1(int A[], int len){
   int i, j;
    for (i = 2; i <= len; ++i) {
        if(A[i] < A[i - 1]){
            A[0] = A[i];
            for (int j = i -1; A[j] > A[0]; j--) {
                A[j + 1] = A[j];
            }
            A[j+1] = A[0];
        }
    }
}


int main(){
    int A[] = {0, 4 , 5, 1 , 2 , 6 , 3 };
    // 第0号位置为哨兵，不输出
    for (int i = 1; i <= 7; ++i) {
        printf("%d \t", A[i]);
    }
    printf("\n");


//    InsertSort(A, 9);
    InsertSort1(A, 7);
    for (int i = 1; i <= 7; ++i) {
        printf("%d \t", A[i]);
    }

}