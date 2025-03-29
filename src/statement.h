// Statement.hpp
#pragma once
#include "types.h"
#include <sstream>

struct StatementPerformance {
    std::string playName;
    int audience;
    int amount;
};

struct StatementResult {
    std::string customer;
    std::vector<StatementPerformance> performances;
    int totalAmount;
    int totalCredits;
};

class Statement {
public:
    static StatementResult generate(const Invoice& invoice, const Plays& plays);
    static std::string usd(int amount);
    static int amountFor(const Performance& perf, const Plays& plays);
    static int volumeCreditsFor(const Performance& perf, const Plays& plays);

private:
    // 辅助函数
    static const Play& playFor(const Performance& perf, const Plays& plays);
};