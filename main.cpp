#include <iostream>
using namespace std;

int main() {
    int a = 0, b = 0;

    cout << "Введите начало отрезка (a): ";
    cin >> a;
    cout << "Введите конец отрезка (b): ";
    cin >> b;

    cout << "Дружественные числа на отрезке [" << a << ", " << b << "]:" << endl;

    bool found = false;  

    for (int i = a; i <= b; i++) {
        int sum_i = 0;
        for (int j = 1; j < i; j++) {
            if (i % j == 0) {
                sum_i += j;
            }
        }

        if (sum_i > i && sum_i <= b) {
            int sum_j = 0;
            for (int k = 1; k < sum_i; k++) {
                if (sum_i % k == 0) {
                    sum_j += k;
                }
            }

            if (sum_j == i) {
                cout << "(" << i << ", " << sum_i << ")" << endl;
                found = true;
            }
        }
    }

    if (!found) {
        cout << "Friendly number dont found" << endl;
    }

    return 0;

}
