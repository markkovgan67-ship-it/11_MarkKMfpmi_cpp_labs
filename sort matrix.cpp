#include <iostream>
using namespace std;


void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


void countingSort(int arr[], int n) {
    if (n <= 0) return;

   
    int max = arr[0], min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }

    int range = max - min + 1;
    int* count = new int[range](); 

    
    for (int i = 0; i < n; i++) {
        count[arr[i] - min]++;
    }

   
    int index = 0;
    for (int i = 0; i < range; i++) {
        while (count[i] > 0) {
            arr[index++] = i + min;
            count[i]--;
        }
    }

    delete[] count;
}


void matrixToArray(int** matrix, int rows, int cols, int arr[]) {
    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[index++] = matrix[i][j];
        }
    }
}


void arrayToMatrix(int arr[], int** matrix, int rows, int cols) {
    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = arr[index++];
        }
    }
}


void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int rows, cols, choice;

    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of cols: ";
    cin >> cols;

    
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    
    cout << "Enter matrix elements:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "matrix[" << i << "][" << j << "] = ";
            cin >> matrix[i][j];
        }
    }

    cout << "\nOriginal matrix:" << endl;
    printMatrix(matrix, rows, cols);

    cout << "\nChoose sorting method:" << endl;
    cout << "1 - Bubble sort" << endl;
    cout << "2 - Insertion sort" << endl;
    cout << "3 - Counting sort" << endl;
    cout << "Enter your choice (1-3): ";
    cin >> choice;

   
    int totalElements = rows * cols;
    int* tempArray = new int[totalElements];

   
    matrixToArray(matrix, rows, cols, tempArray);

  
    switch (choice) {
    case 1:
        bubbleSort(tempArray, totalElements);
        cout << "\nMatrix sorted with Bubble Sort:" << endl;
        break;
    case 2:
        insertionSort(tempArray, totalElements);
        cout << "\nMatrix sorted with Insertion Sort:" << endl;
        break;
    case 3:
        countingSort(tempArray, totalElements);
        cout << "\nMatrix sorted with Counting Sort:" << endl;
        break;
    default:
        cout << "Invalid choice!" << endl;
        return 1;
    }

   
    arrayToMatrix(tempArray, matrix, rows, cols);

  
    printMatrix(matrix, rows, cols);

   
    delete[] tempArray;
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
	   










 
}


