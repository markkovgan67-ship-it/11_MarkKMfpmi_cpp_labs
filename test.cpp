#include "pch.h"
#include <gtest/gtest.h>
#include "functions.h"

TEST(MainTest, FindsFirstPair) {
    clearResults();
    findFriendlyNumbers(200, 300);
    EXPECT_TRUE(containsPair(220, 284));
}

TEST(EmptyTest, NoResultsInSmallRange) {
    clearResults();
    findFriendlyNumbers(1, 100);
    EXPECT_TRUE(friendlyResults.empty());
}

TEST(MultipleTest, FindsSecondPair) {
    clearResults();
    findFriendlyNumbers(1000, 1300);
    EXPECT_TRUE(containsPair(1184, 1210));
}

TEST(ClearTest, ClearFunctionWorks) {
    clearResults();
    findFriendlyNumbers(200, 300);
    EXPECT_FALSE(friendlyResults.empty());

    clearResults();
    EXPECT_TRUE(friendlyResults.empty());
}

TEST(FunctionTest, SumOfDivisorsCorrect) {
    EXPECT_EQ(sumOfDivisors(220), 284);
    EXPECT_EQ(sumOfDivisors(284), 220);
    EXPECT_EQ(sumOfDivisors(6), 6);
}

TEST(IndexTest, GetPairByIndexWorks) {
    clearResults();
    findFriendlyNumbers(200, 300);

    if (getResultsCount() > 0) {
        auto pair = getResultPair(0);
        EXPECT_EQ(pair.first, 220);
        EXPECT_EQ(pair.second, 284);
    }
}