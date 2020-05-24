#include <iostream>

using namespace std;

/**
 * 找出数组中重复的数字
 */
bool question3(int array[], int len) {
    int temp;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; ++j) {
            cout << array[j] << " " ;
        }
        cout << endl;
        if (i + 1 != array[i]) {
            if (array[array[i]] == array[i]) {
                return true;
            } else {
                temp = array[i];
                array[i] = array[array[i]];
                array[array[i]] = temp;
            }
        }
    }
    return false;
}


int main() {
    int a[] = {1, 2, 3, 5, 5};
    cout << boolalpha << question3(a, 5) << endl;
    return 0;
}
