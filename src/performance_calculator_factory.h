#pragma once
#include "tragedy_calculator.h"
#include "comedy_calculator.h"

class PerformanceCalculatorFactory {
public:
    static std::unique_ptr<PerformanceCalculator> createCalculator(const Play& play) {
        if (play.type == "tragedy") {
            return std::unique_ptr<PerformanceCalculator>(new TragedyCalculator());
        } else if (play.type == "comedy") {
            return std::unique_ptr<PerformanceCalculator>(new ComedyCalculator());
        } else {
            throw std::runtime_error("unknown type: " + play.type);
        }
    }
};