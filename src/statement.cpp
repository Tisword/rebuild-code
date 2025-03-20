// Statement.cpp
#include "statement.h"
#include <iomanip>
#include <cmath>

std::string Statement::generate(const Invoice& invoice, const Plays& plays) {
    std::ostringstream result;
    result << "Statement for " << invoice.customer << "\n";

    for (const auto& perf : invoice.performances) {
        const auto& play = playFor(perf, plays);
        result << " " << play.name << ": " << usd(amountFor(perf, plays))
               << " (" << perf.audience << " seats)\n";
    }

    // 计算总金额和积分
    int totalAmount = 0;
    int totalCredits = 0;
    for (const auto& perf : invoice.performances) {
        totalAmount += amountFor(perf, plays);
        totalCredits += volumeCreditsFor(perf, plays);
    }

    result << "Amount owed is " << usd(totalAmount) << "\n";
    result << "You earned " << totalCredits << " credits\n";
    return result.str();
}

// 实现辅助函数
const Play& Statement::playFor(const Performance& perf, const Plays& plays) {
    auto it = plays.find(perf.playID);
    if (it == plays.end()) throw std::runtime_error("Play not found");
    return it->second;
}

int Statement::amountFor(const Performance& perf, const Plays& plays) {
    const auto& play = playFor(perf, plays);
    int result = 0;

    if (play.type == "tragedy") {
        result = 40000;
        if (perf.audience > 30) {
            result += 1000 * (perf.audience - 30);
        }
    } else if (play.type == "comedy") {
        result = 30000;
        if (perf.audience > 20) {
            result += 10000 + 500 * (perf.audience - 20);
        }
        result += 300 * perf.audience;
    } else {
        throw std::runtime_error("unknown type: " + play.type);
    }

    return result;
}

int Statement::volumeCreditsFor(const Performance& perf, const Plays& plays) {
    const auto& play = playFor(perf, plays);
    int credits = std::max(perf.audience - 30, 0);
    if (play.type == "comedy") {
        credits += std::floor(perf.audience / 5.0);
    }
    return credits;
}

std::string Statement::usd(int amount) {
    double dollars = amount / 100.0;
    std::ostringstream oss;
    oss.imbue(std::locale("en_US.UTF-8"));
    oss << std::fixed << std::setprecision(2) << "$" << dollars;
    return oss.str();
}   