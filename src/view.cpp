#include "view.h"
#include <sstream>

void View::displayStatement(const StatementResult& result) {
    std::cout << "Statement for " << result.customer << "\n";
    for (const auto& perf : result.performances) {
        std::cout << " " << perf.playName << ": " << Statement::usd(perf.amount) << "\n";
        std::cout << " (" << perf.audience << " seats)\n";
    }
    std::cout << "Amount owed is " << Statement::usd(result.totalAmount) << "\n";
    std::cout << "You earned " << result.totalCredits << " credits\n";
}

std::string View::generateHtml(const StatementResult& result) {
    std::ostringstream html;
    html << "<!DOCTYPE html><html><head><title>Statement</title></head><body>";
    html << "<h1>Statement for " << result.customer << "</h1>";
    html << "<table border='1'><tr><th>Play</th><th>Audience</th><th>Amount</th></tr>";

    for (const auto& perf : result.performances) {
        html << "<tr><td>" << perf.playName << "</td>"
             << "<td>" << perf.audience << "</td>"
             << "<td>" << Statement::usd(perf.amount) << "</td></tr>";
    }

    html << "</table>";
    html << "<p>Amount owed is " << Statement::usd(result.totalAmount) << "</p>";
    html << "<p>You earned " << result.totalCredits << " credits</p>";
    html << "</body></html>";
    return html.str();
}