#pragma once
#include "performance_calculator.h"

class TragedyCalculator : public PerformanceCalculator {
public:
    int calculateAmount(const Performance& perf) const override {
        int result = 40000;
        if (perf.audience > 30) {
            result += 1000 * (perf.audience - 30);
        }
        return result;
    }
};