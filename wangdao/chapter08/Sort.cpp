#include <cstdio>

/**
 * 插入排序
 * @param A 待排序数组
 * @param n
 *  49 , 38, 65, 97 ,76, 13, 27, 49
 */
void InsertSort(int A[], int n){
    int i, j;
    for (i = 2; i <= n; i++) {
        if(A[i] < A[i-1]){
            A[0] = A[i];
            for (j = i - 1; A[0] < A[j]; j--) {
                A[j + 1] = A[j];
            }
            A[j+1] = A[0];
        }
    }
}



/**
 * 折半插入
 * @param A
 * @param len
 */
void HalfCheckInsertSort(int A[], int len){
    int i, j, low, high, mid;
    for (i = 2;  i <= len; i++) {
        A[0] = A[i];
        low = 1;
        high = i - 1;

        // 折半查找需要插入的位置
        // low和high会慢接近
        while(low < high){
            mid = (low + high) / 2;
            if(A[0] < A[mid]){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        // 最后high+1就是需要插入的位置
        // 把需要插入位置之后的所有元素往后移，空出需要插入的位置
        for (j = i - 1; j >= high + 1; --j) {
            A[j+1] = A[j];
        }

        // 需要插入的数在0位置，赋值到high+1位置
        A[high + 1] = A[0];
    }
}



/**
 * 希尔排序
 * @param A
 * @param len
 */
void ShellSort(int A[], int len){
    int dk, i, j;
    for (dk = len / 2; dk >= 1 ; dk /= 2) {
        // 以dk为步长，从后开始向前比较
        for (i = dk + 1; i <= len ; ++i) {
            // 如果后面的<前面的
            if (A[i] < A[i - dk]){
                // 把后面的值暂存到0位置
                A[0] = A[i];
                // 开始向后挪
                // 只要j>0或者0号位置小于当前的值，当前值就一直向后挪
                for (j = i - dk; j > 0 && A[0] < A[j]; j -= dk) {
                    A[j + dk] = A[j];
                }
                A[j + dk] = A[0];
            }
        }
    }
}


/**
 * 冒泡排序
 * @param A
 * @param len
 */
void BubbleSort(int A[], int len){
    int i, j, temp;
    bool flag;
    for (i = 0; i < len - 1; ++i) {
        flag = false;
        for (j = len - 1; j > i; j --) {
            // 把最小的向前挪，前i个是有序的
            if(A[j - 1] > A[j]){
                temp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = temp;
                flag = true;
            }
        }
        if(flag == false){
            return;
        }
    }
}


int Partition(int A[], int low, int high){
    int pivot = A[low];
    while(low < high){
        while(low < high && A[high] >= pivot){
            -- high;
        }
        A[low] = A[high];
        while(low < high && A[low] <= pivot){
            ++ low;
        }
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}

void QuickSort(int A[], int low, int high){
    int pivotPos;
    if(high > low){
        pivotPos = Partition(A, low, high);
        QuickSort(A, low, pivotPos - 1);
        QuickSort(A, pivotPos + 1, high);
    }
}






int main(){
    int A[] = {0, 49, 38, 65, 97 ,76, 13, 27, 49};
    // 第0号位置为哨兵，不输出
    for (int i = 0; i < 9; ++i) {
        printf("%d \t", A[i]);
    }
    printf("\n");


//    InsertSort(A, 9);
    QuickSort(A, 0, 8);
    for (int i = 0; i < 9; ++i) {
        printf("%d \t", A[i]);
    }




}
