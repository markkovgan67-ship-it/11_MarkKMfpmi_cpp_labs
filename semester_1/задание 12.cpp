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

    // 3. Преобразование массива - элементы с ИНДЕКСАМИ кратными 3 сначала, потом остальные
    int new_massive[1000];
    int new_index = 0;

    // Сначала добавляем элементы с индексами кратными 3 (0, 3, 6, 9, ...)
    for (int i = 0; i < n; i++) {
        if (i % 3 == 0) {  // индексы, кратные 3
            new_massive[new_index] = massive[i];
            new_index++;
        }
    }

    // Затем добавляем все остальные элементы (индексы не кратные 3)
    for (int i = 0; i < n; i++) {
        if (i % 3 != 0) {  // индексы, не кратные 3
            new_massive[new_index] = massive[i];
            new_index++;
        }
    }

    // Вывод преобразованного массива
    std::cout << "Transformed array (indices multiple of 3 first): ";
    for (int i = 0; i < n; i++) {
        std::cout << new_massive[i] << " ";
    }
    std::cout << std::endl;

    // Объяснение преобразования
    std::cout << "Explanation: " << std::endl;
    std::cout << "Indices multiple of 3: ";
    for (int i = 0; i < n; i++) {
        if (i % 3 == 0) {
            std::cout << "massive[" << i << "]=" << massive[i] << " ";
        }
    }
    std::cout << std::endl;
    
    std::cout << "Other indices: ";
    for (int i = 0; i < n; i++) {
        if (i % 3 != 0) {
            std::cout << "massive[" << i << "]=" << massive[i] << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    int n;
    const int max_size = 1000;
    int massive[max_size];
    int choice;

    // Выбор способа ввода
    std::cout << "Choose input method:" << std::endl;
    std::cout << "1 - Random generation" << std::endl;
    std::cout << "2 - Manual input" << std::endl;
    std::cout << "Your choice: ";
    std::cin >> choice;

    // Ввод размера массива
    std::cout << "Enter number of elements: ";
    std::cin >> n;

    if (n <= 0 || n > max_size) {
        std::cout << "Invalid size!" << std::endl;
        return 1;
    }

    if (choice == 1) {
        // Рандомное заполнение массива
        srand(time(0));
        for (int i = 0; i < n; i++) {
            massive[i] = rand() % 21 - 10; // числа от -10 до 10
        }
    }
    else if (choice == 2) {
        // Ручной ввод
        std::cout << "Enter " << n << " elements:" << std::endl;
        for (int i = 0; i < n; i++) {
            std::cin >> massive[i];
        }
    }
    else {
        std::cout << "Invalid choice!" << std::endl;
        return 1;
    }

    // Обработка массива
    processArray(massive, n);

    return 0;
}
