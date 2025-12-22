
#include <set>
#include <numeric>
#include <iostream>
#include <vector>


int main()
{
	setlocale(LC_ALL, "ru");
	std::vector<int> vector;
	int count_elements;
	int value;
	// ввод n-го числа элементов пользователем:
	std::cout << "Введите элементы для вектора(для остановки напишите 0 ):"<< std::endl; 
	while (true) {
		std::cin >> value;
		if (value == 0) break;  // стоп-символ
		vector.push_back(value);
	}
	//вывод элментов конструктора:
	std::cout << "Вы ввели: ";
	for (int num : vector) {
		std::cout << num << " ";
	}
	//методы cуммы:
	int sum = 0;
	for (int num : vector) {
		sum += num;
	}
	std::cout << "Сумма: " << sum << std::endl;
	//метод числа элментов:
	int total_count_number = vector.size();
	std::cout <<"Число элементов конструктора:" << total_count_number;
    // количество чисел, равных заданному:
    int target;
    std::cout << "\n3. Введите число для поиска: ";
    std::cin >> target;

    int count_equal = 0;
    for (int num : vector) {
        if (num == target) count_equal++;
    }
    std::cout << "   Количество чисел равных " << target << ": " << count_equal << std::endl;

    //  Количество чисел, больших чем n:
    int n;
    std::cout << "\n4. Введите число n (посчитаем сколько чисел > n): ";
    std::cin >> n;

    int count_greater = 0;
    for (int num : vector) {
        if (num > n) count_greater++;
    }
    std::cout << "   Количество чисел больше чем " << n << ": " << count_greater << std::endl;

    //  Заменить все нули средним арифметическим:
    if (!vector.empty()) {
        double average = static_cast<double>(sum) / vector.size();
        int avg_int = static_cast<int>(average); // целая часть

        std::cout << "\n5. Среднее арифметическое: " << average
            << " (целая часть: " << avg_int << ")" << std::endl;

        
        int zero_count = 0;
        for (int& num : vector) {
            if (num == 0) {
                num = avg_int;
                zero_count++;
            }
        }

        if (zero_count > 0) {
            std::cout << "   Заменено " << zero_count << " нулей" << std::endl;
            std::cout << "   Вектор после замены: ";
            for (int num : vector) std::cout << num << " ";
            std::cout << std::endl;
        }
        else {
            std::cout << "   Нулей для замены не найдено" << std::endl;
        }
    }

    //  Добавить к каждому элементу сумму всех чисел из заданного интервала:
    if (!vector.empty()) {
        int start_idx, end_idx;
        std::cout << "\n6. Введите начало интервала (индекс от 0 до "
            << vector.size() - 1 << "): ";
        std::cin >> start_idx;

        std::cout << "   Введите конец интервала (индекс от " << start_idx
            << " до " << vector.size() - 1 << "): ";
        std::cin >> end_idx;

        // Проверка корректности индексов
        if (start_idx >= 0 && end_idx < vector.size() && start_idx <= end_idx) {
            
            int interval_sum = 0;
            for (int i = start_idx; i <= end_idx; i++) {
                interval_sum += vector[i];
            }

            std::cout << "   Сумма элементов интервала [" << start_idx
                << ", " << end_idx << "]: " << interval_sum << std::endl;

          
            for (int& num : vector) {
                num += interval_sum;
            }

            std::cout << "   Вектор после добавления суммы интервала: ";
            for (int num : vector) std::cout << num << " ";
            std::cout << std::endl;
        }
        else {
            std::cout << "   Некорректный интервал!" << std::endl;
        }
    }

    //  Заменить числа с четным модулем на разность max-min:
    if (!vector.empty()) {
        
        int max_val = vector[0];
        int min_val = vector[0];

        for (int num : vector) {
            if (num > max_val) max_val = num;
            if (num < min_val) min_val = num;
        }

        int diff = max_val - min_val;
        std::cout << "\n7. Максимальный элемент: " << max_val
            << ", Минимальный: " << min_val
            << ", Разность: " << diff << std::endl;

       
        int replaced_count = 0;
        for (int& num : vector) {
            if (abs(num) % 2 == 0) {
                num = diff;
                replaced_count++;
            }
        }

        std::cout << "   Заменено " << replaced_count << " элементов" << std::endl;
        std::cout << "   Вектор после замены: ";
        for (int num : vector) std::cout << num << " ";
        std::cout << std::endl;
    }
    //  Удалить равные по модулю числа, кроме первого:
    if (!vector.empty()) {
        std::cout << "\n8. Удаление равных по модулю чисел (кроме первого):" << std::endl;
        std::cout << "   Исходный вектор: ";
        for (int num : vector) std::cout << num << " ";
        std::cout << std::endl;

        
        std::vector<int> result;
        std::set<int> seen_abs; 

        for (int num : vector) {
            int abs_val = std::abs(num);
            if (seen_abs.find(abs_val) == seen_abs.end()) {
                
                result.push_back(num);
                seen_abs.insert(abs_val);
            }
        }

        std::cout << "   Было элементов: " << vector.size() << std::endl;
        std::cout << "   Стало элементов: " << result.size() << std::endl;

       
        vector = result;

        std::cout << "   Вектор после удаления: ";
        for (int num : vector) std::cout << num << " ";
        std::cout << std::endl;
    }
	return 0;
}

