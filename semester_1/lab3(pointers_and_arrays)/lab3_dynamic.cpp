
// solve task with usage of
// dymanic arrays

#include <iostream>
#include <cstdlib>
#include <ctime>

// Функция для вычисления модуля
int my_abs(int x) {
    return (x < 0) ? -x : x;
}

void processArray(int massive[], int n) {
    // Вывод исходного массива
    std::cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        std::cout << massive[i] << " ";
    }
    std::cout << std::endl;

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
    std::cout << "Min absolute element: " << massive[min_index] << " at index " << min_index << std::endl;

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
        std::cout << "Sum before last zero: " << sum_before_zero << std::endl;
    }
    else {
        std::cout << "No zero elements found" << std::endl;
    }

    // 3. Преобразование массива - элементы кратные 3 сначала, потом остальные
    // ДИНАМИЧЕСКИЙ массив для результата
    int* new_massive = new int[n];

    int new_index = 0;

    // Сначала добавляем элементы, кратные 3 (по значению)
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
    std::cout << "Transformed array    
