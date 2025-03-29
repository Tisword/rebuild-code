#pragma once
#include "performance_calculator.h"
#include <cmath>

class ComedyCalculator : public PerformanceCalculator {
public:
    int calculateAmount(const Performance& perf) const override {
        int result = 30000;
        if (perf.audience > 20) {
            result += 10000 + 500 * (perf.audience - 20);
        }
        result += 300 * perf.audience;
        return result;
    }

    int calculateCredits(const Performance& perf) const override {
        int credits = PerformanceCalculator::calculateCredits(perf);
        credits += std::floor(perf.audience / 5.0);
        return credits;
    }
};