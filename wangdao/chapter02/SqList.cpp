#include "comm.h"


/**
 * 添加元素
 * @param L 给定的顺序表
 * @param i
 * @param e
 * @return
 */
bool ListInsert(SqList &L, int i, ElemType e) {
    if (i < 1 || i > L.length + 1) {
        return false;
    }
    if (L.length >= MaxSize) {
        return false;
    }

    for (int j = L.length; j > i; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}

/**
 * 删除顺序表中指定位置的元素
 * @param L 给定的顺序表
 * @param i 需要删除元素的位置
 * @param e 删除的元素
 * @return
 */
bool ListDelete(SqList &L, int i, ElemType &e) {
    if (i < 1 || i > L.length)
        return false;
    e = L.data[i - 1];
    for (int j = i; j < L.length; j++)
        L.data[j - 1] = L.data[j];
    L.length--;
    return true;
}

/**
 * 查找顺序表中是否有某个元素
 * @param L 给定顺序表
 * @param e 需要查找的元素
 * @return 返回元素的位置
 */
int LocateElem(SqList L, ElemType e) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e) {
            return i + 1;
        }
    }
    return 0;
}


void TravelSqList(SqList L) {
    for (int i = 0; i < L.length; ++i) {
        printf("%d  ", L.data[i]);
    }
    printf("\n");
}

/**
 * 初始化一个顺序表
 * @param L 需要初始化的顺序表
 * @param len 顺序表长度
 * @param randFlag 是否产生随机元素
 * @return
 */
bool CommInit(SqList &L, int len, bool randFlag){
    L.length = len;
    if(randFlag){
        srand((unsigned)time(NULL));
        for (int i = 0; i < L.length; ++i) {
            L.data[i] = rand();
        }
    }else{
        for (int i = 0; i < L.length; ++i) {
            L.data[i] = i;
        }
    }
    return true;
}


/**
 * 例题1：删除最小元素
 */
void e01() {
    SqList sqList;
    sqList.length = 10;
    for (int i = 0; i < sqList.length; ++i) {
        sqList.data[i] = rand();
    }
    TravelSqList(sqList);

    ElemType min = sqList.data[0];
    int idx = 0;
    for (int i = 0; i < sqList.length; i++) {
        if (sqList.data[i] < min) {
            min = sqList.data[i];
            idx = i;
        }
    }
    ListDelete(sqList, idx + 1, min);

    TravelSqList(sqList);
}


/**
 * 例题2：元素逆置
 */
void e02(SqList &L){
    int temp;
    for (int j = 0; j < L.length / 2; j++) {
        temp = L.data[j];
        L.data[j] = L.data[L.length - 1 - j];
        L.data[L.length - 1 - j] = temp;
    }
}

/**
 * 例题3：删除顺序表中所有指定的元素
 */
void e03(SqList &L, ElemType e){
    for (int i = 0; i < L.length; i++) {
        if(L.data[i] == e){
            L.data[i] = L.data[L.length -1];
            L.length --;
        }
    }
}

/**
 * 例题4：
 * @param L 有序表
 * @param s
 * @param t
 * @return
 */
bool e04(SqList &L, ElemType s, ElemType t){
    if(s >= t || L.length == 0){
        return false;
    }
    for (int i = L.length - 1; i >= 0; i--) {

    }
    return true;
}


bool e05(SqList &L, ElemType s, ElemType t){
    if(s >= t || L.length == 0){
        return false;
    }
    for (int i = L.length - 1; i >= 0; i--) {
        if(L.data[i] >= s && L.data[i] <= t){
            L.data[i] = L.data[L.length - 1];
            L.length --;
        }
    }
    return true;
}

/**
 * 删除有序表中重复的值
 * @return
 */
bool e06(SqList &L){
    int skip = 1;
    for (int i = 1; i < L.length ; i++) {
        if(L.data[i] == L.data[i - skip]){
            skip ++;
        }
        if(skip > 1){
            L.data[i - skip + 1] = L.data[i];
        }
    }
    L.length  = L.length - skip + 1;
    return true;
}

/**
 * 删除有序表中重复的值
 * @return
 */
bool e06_ans(SqList &L){
    if(L.length == 0){
        return false;
    }
    int i, j;
    for (i = 0, j = 1; j < L.length ; j++) {
        if (L.data[i] != L.data[j]) {
            L.data[++i] = L.data[j];
        }
    }
    L.length = i + 1;
    return true;
}

/**
 * 合并两个有序表
 * @param L1
 * @param L2
 * @return
 */
bool e07(SqList &L1, SqList &L2, SqList &L3){
    if(L1.length + L2.length > MaxSize){
        return false;
    }

    int i=0, j=0, k = 0;
    while(i < L1.length && j < L2.length){
        if(L1.data[i] < L2.data[j]){
            L3.data[k++] = L1.data[i++];
        }else{
            L3.data[k++] = L2.data[j++];
        }
    }
    while(i < L1.length){
        L3.data[k++] = L1.data[i++];
    }

    while(j < L2.length){
        L3.data[k++] = L2.data[j++];
    }

    L3.length = k;
    return true;
}

/**
 * 习题8：
 * 平移法（效率较低）
 * @param arr
 * @param m
 * @param n
 * @return
 */
bool e08(int arr[], int m, int n){
    // 先交换相同长度部分
    int len = m + n;
    int temp;
    printArray(arr, len);

    while(m > 0){
        temp = arr[0];
        for(int i = 0; i < len; i++){
            arr[i] = arr[i + 1];
        }
        arr[len -1] = temp;
        m --;
    }

    printArray(arr, len);
    return true;
}


void Reverse(int arr[], int begin, int end, int arraySize){
    int mid = (begin + end ) / 2;
    for(int i = 0; i <= mid - begin; i++){
        int temp = arr[begin + i];
        arr[begin + i] = arr[end - i];
        arr[end - i] = temp;
    }
}
/**
 * 例题8：
 * @param arr
 * @param m
 * @param n
 * @return
 */
bool e08_ans(int arr[], int m, int n){
    int len = m + n;
    printArray(arr, len);
    Reverse(arr, 0, len - 1, len);
    Reverse(arr, 0, n - 1, len);
    Reverse(arr, n, len - 1, len);
    printArray(arr, len);
    return true;
}



int e09(int arr[], int len, int x){
    int left = 0, right = len - 1;
    int mid = 0;
    while(left <= right){
        mid = (left + right) / 2;
        if(arr[mid] == x){
            return mid;
        }else if(arr[mid] > x){
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    return -1;
}



int main() {
    int a[11] = {0,1,2,3,4,5,6,7,8,9,10};
    int ans = e09(a, 11,4);
    printf("%d", ans);
    return 1;
}




