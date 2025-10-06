#include <iostream>
#include <cstdlib> 
#include <ctime>   

int sumAfterLastZero(int arr[], int size) {
    int lastZeroIndex = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] == 0) {
            lastZeroIndex = i;
        }
    }

    if (lastZeroIndex == -1 || lastZeroIndex == size - 1) {
        return 0;
    }

    int sum = 0;
    for (int i = lastZeroIndex + 1; i < size; i++) {
        sum += arr[i];
    }

    return sum;
}

int main()
{
    int i, n, j;
    const int max_size = 1000;
    int massive[max_size];

    // Часть с ручным вводом
    std::cout << "Enter number element massive:";
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> massive[i];
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (massive[i] > 0)
        {
            count++;
        }
    }
    std::cout << "Number of positive elements: " << count << std::endl;

    int result = sumAfterLastZero(massive, n);
    std::cout << "Sum of elements after last zero: " << result << std::endl;

    int positive_positions[max_size], negative_positions[max_size];
    int pos_values[max_size], neg_values[max_size];
    int pos_count = 0, neg_count = 0;

    // Запоминаем позиции и значения
    for (int i = 0; i < n; i++) {
        if (massive[i] > 0) {
            positive_positions[pos_count] = i;
            pos_values[pos_count] = massive[i];
            pos_count++;
        }
        else if (massive[i] < 0) {
            negative_positions[neg_count] = i;
            neg_values[neg_count] = massive[i];
            neg_count++;
        }
    }

    // Сортируем положительные значения по возрастанию
    for (int i = 0; i < pos_count - 1; i++) {
        for (int j = 0; j < pos_count - i - 1; j++) {
            if (pos_values[j] > pos_values[j + 1]) {
                int temp = pos_values[j];
                pos_values[j] = pos_values[j + 1];
                pos_values[j + 1] = temp;
            }
        }
    }

    // Сортируем отрицательные значения по убыванию
    for (int i = 0; i < neg_count - 1; i++) {
        for (int j = 0; j < neg_count - i - 1; j++) {
            if (neg_values[j] < neg_values[j + 1]) {
                int temp = neg_values[j];
                neg_values[j] = neg_values[j + 1];
                neg_values[j + 1] = temp;
            }
        }
    }

    // Вставляем отсортированные значения обратно на их позиции
    for (int i = 0; i < pos_count; i++) {
        massive[positive_positions[i]] = pos_values[i];
    }
    for (int i = 0; i < neg_count; i++) {
        massive[negative_positions[i]] = neg_values[i];
    }

    std::cout << "All Elements: ";
    for (int j = 0; j < n; j++) {
        std::cout << massive[j] << " ";
    }
    std::cout << std::endl;

    //--------------------------------------------------------------------------------------часть с рандомными числами
    int k;
    int massive_rand[max_size]; 
    std::cout << "Enter number element massive for random:";
    std::cin >> k;

    srand(time(0));
    for (int i = 0; i < k; i++)
    {
        // Генерируем числа от -10 до 10 с нулями
        int random_num = rand() % 21 - 10; // от -10 до 10
        // С вероятностью 10% делаем ноль
        if (rand() % 1 == 0) {
            massive_rand[i] = 0;
        }
        else {
            massive_rand[i] = random_num;
        }
    }

    // Выводим сгенерированный массив
    std::cout << "Generated array: ";
    for (int i = 0; i < k; i++) {
        std::cout << massive_rand[i] << " ";
    }
    std::cout << std::endl;

    int count_rand = 0;
    for (int i = 0; i < k; i++)
    {
        if (massive_rand[i] > 0)
        {
            count_rand++;
        }
    }
    std::cout << "Number of positive elements: " << count_rand << std::endl;

    int result_rand = sumAfterLastZero(massive_rand, k);
    std::cout << "Sum of elements after last zero: " << result_rand << std::endl;

    int positive_positions_rand[max_size], negative_positions_rand[max_size];
    int pos_values_rand[max_size], neg_values_rand[max_size];
    int pos_count_rand = 0, neg_count_rand = 0;

    for (int i = 0; i < k; i++) {
        if (massive_rand[i] > 0) {
            positive_positions_rand[pos_count_rand] = i;
            pos_values_rand[pos_count_rand] = massive_rand[i];
            pos_count_rand++;
        }
        else if (massive_rand[i] < 0) {
            negative_positions_rand[neg_count_rand] = i;
            neg_values_rand[neg_count_rand] = massive_rand[i];
            neg_count_rand++;
        }
    }

    for (int i = 0; i < pos_count_rand - 1; i++) {
        for (int j = 0; j < pos_count_rand - i - 1; j++) {
            if (pos_values_rand[j] > pos_values_rand[j + 1]) {
                int temp = pos_values_rand[j];
                pos_values_rand[j] = pos_values_rand[j + 1];
                pos_values_rand[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < neg_count_rand - 1; i++) {
        for (int j = 0; j < neg_count_rand - i - 1; j++) {
            if (neg_values_rand[j] < neg_values_rand[j + 1]) {
                int temp = neg_values_rand[j];
                neg_values_rand[j] = neg_values_rand[j + 1];
                neg_values_rand[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < pos_count_rand; i++) {
        massive_rand[positive_positions_rand[i]] = pos_values_rand[i];
    }
    for (int i = 0; i < neg_count_rand; i++) {
        massive_rand[negative_positions_rand[i]] = neg_values_rand[i];
    }

    std::cout << "All Elements random: ";
    for (int j = 0; j < k; j++) {
        std::cout << massive_rand[j] << " ";
    }
    std::cout << std::endl;

    return 0;
}