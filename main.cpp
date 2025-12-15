
#include <iostream>
#include "functions.h"  // Тот же самый файл!

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
        int sum_i = sumOfDivisors(i);

        if (sum_i > i && sum_i <= b) {
            if (areFriendly(i, sum_i)) {  // Используем функцию из functions.h
                cout << "(" << i << ", " << sum_i << ")" << endl;
                found = true;
            }
        }
    }

    if (!found) {
        cout << "Дружественные числа не найдены" << endl;
    }

    return 0;
}