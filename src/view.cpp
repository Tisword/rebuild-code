#include "view.h"

void View::displayStatement(const StatementResult& result) {
    std::cout << "Statement for " << result.customer << "\n";
    for (const auto& perf : result.performances) {
        std::cout << " " << perf.playName << ": " << Statement::usd(perf.amount) << "\n";
        std::cout << " (" << perf.audience << " seats)\n";
    }
    std::cout << "Amount owed is " << Statement::usd(result.totalAmount) << "\n";
    std::cout << "You earned " << result.totalCredits << " credits\n";
}