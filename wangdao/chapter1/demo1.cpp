#include <iostream>

using namespace std;


int fibonacci_rec(int idx) {
    if (idx == 0) {
        return 1;
    } else if (idx == 1) {
        return 2;
    } else if(idx < 0){
        cout << "wrong idx" << endl;
    }
    return fibonacci_rec(idx - 1) + fibonacci_rec(idx - 2);
}



int fibonacci_loop(int idx) {
    // todo ѭ�����쳲���������
}


/**
 * P12 ˼ά��չ
 * @return
 */
int main() {
    cout << fibonacci_rec(5) << endl;
}


