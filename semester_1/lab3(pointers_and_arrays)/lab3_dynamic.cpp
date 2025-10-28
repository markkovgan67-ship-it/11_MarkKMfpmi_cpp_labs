
// solve task with usage of
// dymanic arrays
 #include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Функция для вычисления модуля
int my_abs(int x) {
    if (x < 0) return -x;
    return x;
}

void processArray(int* massive, int n) {
    // Вывод исходного массива
    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << massive[i] << " ";
    }
    cout << endl;

    // 1. Минимальный по модулю элемент
    int min_abs = my_abs(massive[0]);
    int min_index = 0;
    for (int i = 1; i < n; i++) {
        int current_abs = my_abs(massive[i]);
        if (current_abs < min_abs) {
            min_abs = current_abs;
            min_index = i;
        }
    }
    cout << "Min absolute element: " << massive[min_index] << " at index " << min_index << endl;

    // 2. Сумма элементов до последнего нулевого элемента
    int last_zero_index = -1;
    for (int i = 0; i < n; i++) {
        if (massive[i] == 0) {
            last_zero_index = i;
        }
    }

    int sum_before_zero = 0;
    if (last_zero_index != -1) {
        for (int i = 0; i < last_zero_index; i++) {
            sum_before_zero += massive[i];
        }
        cout << "Sum before last zero: " << sum_before_zero << endl;
    } else {
        cout << "No zero elements found" << endl;
    }

    // 3. Преобразование массива - элементы кратные 3 сначала, потом остальные
    // ДИНАМИЧЕСКИЙ массив для результата
    int* new_massive = new int[n];

    int new_index = 0;

    // Сначала добавляем элементы, кратные 3
    for (int i = 0; i < n; i++) {
        if (massive[i] % 3 == 0 && massive[i] != 0) {
            new_massive[new_index] = massive[i];
            new_index++;
        }
    }

    // Затем добавляем все остальные элементы
    for (int i = 0; i < n; i++) {
        if (massive[i] % 3 != 0 || massive[i] == 0) {
            new_massive[new_index] = massive[i];
            new_index++;
        }
    }

    // Вывод преобразованного массива
    cout << "Transformed array (multiples of 3 first): ";
    for (int i = 0; i < n; i++) {
        cout << new_massive[i] << " ";
    }
    cout << endl;

    // ОСВОБОЖДЕНИЕ динамической памяти
    delete[] new_massive;
}

int main() {
    int n;
    int choice;

    // Выбор способа ввода
    cout << "Choose input method:" << endl;
    cout << "1 - Random generation" << endl;
    cout << "2 - Manual input" << endl;
    cout << "Your choice: ";
    cin >> choice;

    // Ввод размера массива
    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid size! Size should be greater than 0" << endl;
        return 1;
    }

    // ДИНАМИЧЕСКОЕ выделение памяти для основного массива
    int* massive = new int[n];

    if (choice == 1) {
        // Рандомное заполнение массива
        srand(time(0));
        for (int i = 0; i < n; i++) {
            massive[i] = rand() % 21 - 10; // числа от -10 до 10
        }
        
        // Вывод сгенерированного массива
        cout << "Generated array: ";
        for (int i = 0; i < n; i++) {
            cout << massive[i] << " ";
        }
        cout << endl;
    } else if (choice == 2) {
        // Ручной ввод
        cout << "Enter " << n << " elements:" << endl;
        for (int i = 0; i < n; i++) {
            cin >> massive[i];
        }
    } else {
        cout << "Invalid choice!" << endl;
        delete[] massive; // Освобождение памяти при ошибке
        return 1;
    }

    // Обработка массива
    processArray(massive, n);

    // ОСВОБОЖДЕНИЕ динамической памяти
    delete[] massive;

    return 0;
}   
