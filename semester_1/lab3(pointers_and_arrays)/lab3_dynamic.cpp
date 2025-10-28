
// solve task with usage of
// dymanic arrays
#include <iostream>
#include <cstdlib>
#include <ctime>

// Функция для вычисления модуля
int my_abs(int x) {
    return (x < 0) ? -x : x;
}

int main()
{
    int i, n;
    const int max_size = 1000;
    int massive[max_size];

    // Ввод массива
    std::cout << "Enter number of elements: ";
    std::cin >> n;

    // Рандомное заполнение массива
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        massive[i] = rand() % 21 - 10; // числа от -10 до 10
    }

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

    // 3. Преобразование массива - элементы с индексами кратными 3 сначала
    int new_massive[max_size];
    int new_index = 0;

    // Сначала добавляем элементы с индексами кратными 3
    for (int i = 0; i < n; i++) {
        if (i % 3 == 0) {
            new_massive[new_index] = massive[i];
            new_index++;
        }
    }

    // Затем добавляем остальные элементы
    for (int i = 0; i < n; i++) {
        if (i % 3 != 0) {
            new_massive[new_index] = massive[i];
            new_index++;
        }
    }

    // Вывод преобразованного массива
    std::cout << "Transformed array: ";
    for (int i = 0; i < n; i++) {
        std::cout << new_massive[i] << " ";
    }
    std::cout << std::endl;

 std::cout << "Enter number of elements: ";
    std::cin >> n;
    
    std::cout << "Enter " << n << " elements:" << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cin >> massive[i];
    }
    
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
    } else {
        std::cout << "No zero elements found" << std::endl;
    }
    
    // 3. Преобразование массива - элементы с индексами кратными 3 сначала
    int new_massive[max_size];
    int new_index = 0;
    
    // Сначала добавляем элементы с индексами кратными 3
    for (int i = 0; i < n; i++) {
        if (i % 3 == 0) {
            new_massive[new_index] = massive[i];
            new_index++;
        }
    }
    
    // Затем добавляем остальные элементы
    for (int i = 0; i < n; i++) {
        if (i % 3 != 0) {
            new_massive[new_index] = massive[i];
            new_index++;
        }
    }
    
    // Вывод преобразованного массива
    std::cout << "Transformed array: ";
    for (int i = 0; i < n; i++) {
        std::cout << new_massive[i] << " ";
    }
    std::cout << std::endl;
    //------------------------------------------------------------------------------------------ввод с калвиатуры
    std::cout << "Enter number of elements: ";
    std::cin >> n;

    std::cout << "Enter " << n << " elements:" << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cin >> massive[i];
    }

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

    // 3. Преобразование массива - элементы с индексами кратными 3 сначала
    int new_massive[max_size];
    int new_index = 0;

    // Сначала добавляем элементы с индексами кратными 3
    for (int i = 0; i < n; i++) {
        if (i % 3 == 0) {
            new_massive[new_index] = massive[i];
            new_index++;
        }
    }

    // Затем добавляем остальные элементы
    for (int i = 0; i < n; i++) {
        if (i % 3 != 0) {
            new_massive[new_index] = massive[i];
            new_index++;
        }
    }

    // Вывод преобразованного массива
    std::cout << "Transformed array: ";
    for (int i = 0; i < n; i++) {
        std::cout << new_massive[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
