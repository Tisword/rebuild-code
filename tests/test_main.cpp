#include <gtest/gtest.h>
#include "../src/statement.h" // 包含 Statement 类的头文件
#include "../src/types.h"     // 包含 Play、Performance 等类型定义

// 测试 Statement::amountFor 方法
TEST(StatementTest, AmountFor) {
    Statement statement;
    Plays plays = {
        {"hamlet", {"Hamlet", "tragedy"}},
        {"as-like", {"As You Like It", "comedy"}}
    };

    Performance perf1 = {"hamlet", 35}; // Hamlet, 35 人
    Performance perf2 = {"as-like", 25}; // As You Like It, 25 人

    EXPECT_EQ(statement.amountFor(perf1, plays), 45000); // Hamlet: 40000 + 1000 * (35 - 30)
    EXPECT_EQ(statement.amountFor(perf2, plays), 50000); // Comedy: 30000 + 10000 + 500 * (25 - 20) + 300 * 25
}

// 测试 Statement::volumeCreditsFor 方法
TEST(StatementTest, VolumeCreditsFor) {
    Statement statement;
    Plays plays = {
        {"hamlet", {"Hamlet", "tragedy"}},
        {"as-like", {"As You Like It", "comedy"}}
    };

    Performance perf1 = {"hamlet", 35}; // Hamlet, 35 人
    Performance perf2 = {"as-like", 25}; // As You Like It, 25 人

    EXPECT_EQ(statement.volumeCreditsFor(perf1, plays), 5); // Hamlet: max(35 - 30, 0)
    EXPECT_EQ(statement.volumeCreditsFor(perf2, plays), 5); // Comedy: max(25 - 30, 0) + floor(25 / 5.0)
}

// 测试 Statement::usd 方法
TEST(StatementTest, Usd) {
    Statement statement;

    EXPECT_EQ(statement.usd(45000), "$450.00");
    EXPECT_EQ(statement.usd(58000), "$580.00");
    EXPECT_EQ(statement.usd(0), "$0.00");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}