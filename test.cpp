#include "pch.h"
#include <gtest/gtest.h>

int sumOfDivisors(int n) {
    if (n <= 1) return 0;
    int sum = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) sum += i;
    }
    return sum;
}

// =============== 6 САМЫХ ВАЖНЫХ ТЕСТОВ ===============

// 1. БАЗОВАЯ ПРОВЕРКА функции sumOfDivisors
TEST(BasicTest, SumOfDivisors) {
    EXPECT_EQ(sumOfDivisors(6), 6);     // 1+2+3 = 6 (совершенное число)
    EXPECT_EQ(sumOfDivisors(10), 8);    // 1+2+5 = 8
}

// 2. ГЛАВНЫЙ ТЕСТ: известная пара дружественных чисел
TEST(MainTest, FriendlyPair220_284) {
    EXPECT_EQ(sumOfDivisors(220), 284); // 220 → 284
    EXPECT_EQ(sumOfDivisors(284), 220); // 284 → 220
}

// 3. ВТОРАЯ известная пара (для надежности)
TEST(SecondPairTest, FriendlyPair1184_1210) {
    EXPECT_EQ(sumOfDivisors(1184), 1210);
    EXPECT_EQ(sumOfDivisors(1210), 1184);
}

// 4. ТЕСТ НА ОШИБКУ: проверяем что обычные числа не дружественные
TEST(NegativeTest, NotFriendlyNumbers) {
    EXPECT_NE(sumOfDivisors(10), 10);   // 10 не совершенное
    EXPECT_NE(sumOfDivisors(100), 100); // 100 не совершенное
    EXPECT_FALSE(sumOfDivisors(50) == 60 && sumOfDivisors(60) == 50);
}

// 5. ТЕСТ ПОИСКА в диапазоне (имитация работы программы)
TEST(RangeSearchTest, FindInRange200_300) {
    bool found = false;
    int found_i = 0, found_sum = 0;

    for (int i = 200; i <= 300; i++) {
        int sum_i = sumOfDivisors(i);
        if (sum_i > i && sum_i <= 300) {
            if (sumOfDivisors(sum_i) == i) {
                found_i = i;
                found_sum = sum_i;
                found = true;
                break;
            }
        }
    }

    EXPECT_TRUE(found);
    EXPECT_EQ(found_i, 220);
    EXPECT_EQ(found_sum, 284);
}

// 6. ТЕСТ ПУСТОГО диапазона (граничный случай)
TEST(EmptyRangeTest, NoFriendlyInRange1_100) {
    bool found = false;

    for (int i = 1; i <= 100; i++) {
        int sum_i = sumOfDivisors(i);
        if (sum_i > i && sum_i <= 100) {
            if (sumOfDivisors(sum_i) == i) {
                found = true;
                break;
            }
        }
    }

    EXPECT_FALSE(found); // Не должно найти ничего
}