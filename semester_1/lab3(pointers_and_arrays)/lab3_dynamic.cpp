
// solve task with usage of
// dymanic arrays
 #include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// функция модуля
int my_abs(int x) {
    if (x < 0) return -x;
    return x;
}

void processArray(int* massive, int n) {
    // функция объявления массива
    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << massive[i] << " ";
    }
    cout << endl;

    // Нахождение минимального элемента по модулю
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

    // Сумма и нахождение элементов до последнего 0
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

    // сортировка массива по числам кратным 3 сначала
    // объявление динамичесвкого массива
    int* new_massive = new int[n];

    int new_index = 0;

    // добавленеи элеменетов кратных 3
    for (int i = 0; i < n; i++) {
        if (massive[i] % 3 == 0 && massive[i] != 0) {
            new_massive[new_index] = massive[i];
            new_index++;
        }
    }

    //добавленеи оставшихся элементов
    for (int i = 0; i < n; i++) {
        if (massive[i] % 3 != 0 || massive[i] == 0) {
            new_massive[new_index] = massive[i];
            new_index++;
        }
    }

    // вывод преобразованного массива
    cout << "Transformed array (multiples of 3 first): ";
    for (int i = 0; i < n; i++) {
        cout << new_massive[i] << " ";
    }
    cout << endl;

    // освобожденеи динамической памяти
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

    // динамическое выделение памяти под освновной масиив
    int* massive = new int[n];
//-----------------------------------------------------------------------------------------------рандомный выбор
    if (choice == 1) {
       
        srand(time(0));
        for (int i = 0; i < n; i++) {
            massive[i] = rand() % 21 - 10; // 
        }
        
        
        cout << "Generated array: ";
        for (int i = 0; i < n; i++) {
            cout << massive[i] << " ";
        }
        cout << endl;
    } else if (choice == 2) {
       
        cout << "Enter " << n << " elements:" << endl;
        for (int i = 0; i < n; i++) {
            cin >> massive[i];
        }
    } else {
        cout << "Invalid choice!" << endl;
        delete[] massive; 
        return 1;
    }

    
    processArray(massive, n);

   
    delete[] massive;

    return 0;
}   
