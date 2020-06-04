#include <cstdio>

/**
 * ��������
 * @param A ����������
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
 * �۰����
 * @param A
 * @param len
 */
void HalfCheckInsertSort(int A[], int len){
    int i, j, low, high, mid;
    for (i = 2;  i <= len; i++) {
        A[0] = A[i];
        low = 1;
        high = i - 1;

        // �۰������Ҫ�����λ��
        // low��high�����ӽ�
        while(low < high){
            mid = (low + high) / 2;
            if(A[0] < A[mid]){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        // ���high+1������Ҫ�����λ��
        // ����Ҫ����λ��֮�������Ԫ�������ƣ��ճ���Ҫ�����λ��
        for (j = i - 1; j >= high + 1; --j) {
            A[j+1] = A[j];
        }

        // ��Ҫ���������0λ�ã���ֵ��high+1λ��
        A[high + 1] = A[0];
    }
}



/**
 * ϣ������
 * @param A
 * @param len
 */
void ShellSort(int A[], int len){
    int dk, i, j;
    for (dk = len / 2; dk >= 1 ; dk /= 2) {
        // ��dkΪ�������Ӻ�ʼ��ǰ�Ƚ�
        for (i = dk + 1; i <= len ; ++i) {
            // ��������<ǰ���
            if (A[i] < A[i - dk]){
                // �Ѻ����ֵ�ݴ浽0λ��
                A[0] = A[i];
                // ��ʼ���Ų
                // ֻҪj>0����0��λ��С�ڵ�ǰ��ֵ����ǰֵ��һֱ���Ų
                for (j = i - dk; j > 0 && A[0] < A[j]; j -= dk) {
                    A[j + dk] = A[j];
                }
                A[j + dk] = A[0];
            }
        }
    }
}


/**
 * ð������
 * @param A
 * @param len
 */
void BubbleSort(int A[], int len){
    int i, j, temp;
    bool flag;
    for (i = 0; i < len - 1; ++i) {
        flag = false;
        for (j = len - 1; j > i; j --) {
            // ����С����ǰŲ��ǰi���������
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
    // ��0��λ��Ϊ�ڱ��������
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
