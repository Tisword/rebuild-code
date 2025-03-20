// Statement.hpp
#pragma once
#include "types.h"
#include <sstream>

class Statement {
public:
    static std::string generate(const Invoice& invoice, const Plays& plays);

private:
    // 辅助函数
    static const Play& playFor(const Performance& perf, const Plays& plays);
    static int amountFor(const Performance& perf, const Plays& plays);
    static int volumeCreditsFor(const Performance& perf, const Plays& plays);
    static std::string usd(int amount);
};