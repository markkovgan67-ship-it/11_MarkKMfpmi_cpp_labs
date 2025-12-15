#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <utility>

std::vector<std::pair<int, int>> friendlyResults;

int sumOfDivisors(int n) {
    if (n <= 1) return 0;
    int sum = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) sum += i;
    }
    return sum;
}

bool checkAndStoreFriendly(int a, int b) {
    if (sumOfDivisors(a) == b && sumOfDivisors(b) == a && a != b) {
        friendlyResults.push_back(std::make_pair(a, b));
        return true;
    }
    return false;
}

void findFriendlyNumbers(int start, int end) {
    for (int i = start; i <= end; i++) {
        int sum_i = sumOfDivisors(i);
        if (sum_i > i && sum_i <= end) {
            checkAndStoreFriendly(i, sum_i);
        }
    }
}

void clearResults() {
    friendlyResults.clear();
}

int getResultsCount() {
    return friendlyResults.size();
}

std::pair<int, int> getResultPair(int index) {
    if (index >= 0 && index < friendlyResults.size()) {
        return friendlyResults[index];
    }
    return std::make_pair(0, 0);
}

bool containsPair(int a, int b) {
    for (const auto& pair : friendlyResults) {
        if ((pair.first == a && pair.second == b) ||
            (pair.first == b && pair.second == a)) {
            return true;
        }
    }
    return false;
}

#endif