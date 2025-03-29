#pragma once
#include "types.h"

class PerformanceCalculator {
public:
    virtual ~PerformanceCalculator() = default;
    virtual int calculateAmount(const Performance& perf) const = 0;
    virtual int calculateCredits(const Performance& perf) const {
        return std::max(perf.audience - 30, 0);
    }
};