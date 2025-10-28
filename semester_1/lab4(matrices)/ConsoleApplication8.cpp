﻿#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    int n, m;
    std::cout << "Enter number rows and cols: ";
    std::cin >> n >> m;
    int a[100][100];

    std::cout << "Enter elements matrix: " << n << "x" << m << ":" << std::endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            std::cin >> a[i][j];

   
    int count_cols = 0;
    for (int j = 0; j < m; j++) {
        bool has_a11 = false;
        for (int i = 0; i < n; i++) {
            if (a[i][j] == a[0][0]) {
                has_a11 = true;
                break;
            }
        }
        if (!has_a11) count_cols++;
    }

   
    int max_row = 0, max_len = 1;
    for (int i = 0; i < n; i++) {
        int curr_len = 1;
        for (int j = 1; j < m; j++) {
            if (a[i][j] == a[i][j - 1]) {
                curr_len++;
            }
            else {
                if (curr_len > max_len) {
                    max_len = curr_len;
                    max_row = i;
                }
                curr_len = 1;
            }
        }
        
        if (curr_len > max_len) {
            max_len = curr_len;
            max_row = i;
        }
    }

    std::cout << "Number of columns without the a[0][0] element " << count_cols << std::endl;
    std::cout << "The row number with the longest series: " << max_row << std::endl;
    //--------------------------------------------------------------------------------------------------------
    std::srand(std::time(0));
    int k, l;
    std::cout << "Enter number rows and cols for random matrix: ";
    std::cin >> k >> l;
    int b[100][100];

    std::cout << "Random matrix " << k << "x" << l << ":" << std::endl;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < l; j++) {
            b[i][j] = rand() % 10; 
            std::cout << b[i][j] << " ";
        }
        std::cout << std::endl;
    }

    
    int count_colsrand = 0;
    for (int j = 0; j < l; j++) {
        bool has_a11 = false;
        for (int i = 0; i < k; i++) {
            if (b[i][j] == b[0][0]) { 
                has_a11 = true;
                break;
            }
        }
        if (!has_a11) count_colsrand++;
    }

    
    int max_rowrand = 0, max_lenrand = 1; 
    for (int i = 0; i < k; i++) {
        int curr_lenrand = 1;
        for (int j = 1; j < l; j++) {
            if (b[i][j] == b[i][j - 1]) { 
                curr_lenrand++;
            }
            else {
                if (curr_lenrand > max_lenrand) { 
                    max_rowrand = i;
                }
                curr_lenrand = 1;
            }
        }
       
        if (curr_lenrand > max_lenrand) { 
            max_lenrand = curr_lenrand;
            max_rowrand = i;
        }
    }

    std::cout << "Number of columns without element b[0][0]: " << count_colsrand << std::endl;
    std::cout << "Row number with the longest series: " << max_rowrand << std::endl;

    return 0;
}