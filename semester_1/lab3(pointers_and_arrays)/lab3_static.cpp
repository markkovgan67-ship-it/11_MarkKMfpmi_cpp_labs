
// solve task with usage of
// static arrays

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

void sortPositiveNegative(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > 0 && arr[j + 1] > 0 && arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] < 0 && arr[j + 1] < 0 && arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    const int max_size = 1000;
    int massive[max_size];
    int choice;

    std::cout << "Choose input method:" << std::endl;
    std::cout << "1 - Manual input" << std::endl;
    std::cout << "2 - Random generation" << std::endl;
    std::cout << "Your choice: ";
    std::cin >> choice;

    if (choice == 1) {
        std::cout << "Enter number of elements in array: ";
        std::cin >> n;
        
        if (n > max_size || n <= 0) {
            std::cout << "Invalid array size!" << std::endl;
            return 1;
        }
        
        std::cout << "Enter " << n << " elements: ";
        for (int i = 0; i < n; i++) {
            std::cin >> massive[i];
        }
    }
    else if (choice == 2) {
        std::cout << "Enter number of elements in array: ";
        std::cin >> n;
        
        if (n > max_size || n <= 0) {
            std::cout << "Invalid array size!" << std::endl;
            return 1;
        }
        
        srand(time(0));
        for (int i = 0; i < n; i++) {
            massive[i] = rand() % 21 - 10;
        }

        std::cout << "Generated array: ";
        for (int i = 0; i < n; i++) {
            std::cout << massive[i] << " ";
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "Invalid choice!" << std::endl;
        return 1;
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (massive[i] > 0) {
            count++;
        }
    }
    std::cout << "Number of positive elements: " << count << std::endl;

    int result = sumAfterLastZero(massive, n);
    std::cout << "Sum of elements after last zero: " << result << std::endl;

    sortPositiveNegative(massive, n);

    std::cout << "Sorted array (positive ascending, negative descending): ";
    for (int i = 0; i < n; i++) {
        std::cout << massive[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}  
