#include <iostream>
#include <string>
#include <map>
#include <iomanip> // for std::fixed and std::setprecision

struct Performance {
    std::string playID;
    int audience;
};

struct Invoice {
    std::string customer;
    std::vector<Performance> performances;
};

struct Play {
    std::string name;
    std::string type;
};

std::string statement(const Invoice& invoice, const std::map<std::, Play>& plays) {
    int totalAmount = 0;
    int volumeCredits = 0;
    std::string result = "Statement for " + invoice.customer + "\n";

    for (const auto& perf : invoice.performances) {
        const Play& play = plays.at(perf.playID);
        int thisAmount = 0;

        if (play.type == "tragedy") {
            thisAmount = 40000;
            if (perf.audience > 30) {
                thisAmount += 1000 * (perf.audience - 30);
            }
        } else if (play.type == "comedy") {
            thisAmount = 30000;
            if (perf.audience > 20) {
                thisAmount += 10000 + 500 * (perf.audience - 20);
            }
            thisAmount += 300 * perf.audience;
        } else {
            throw std::runtime_error("unknown type: " + play.type);
        }

        // Add volume credits
        volumeCredits += std::max(perf.audience - 30, 0);
        // Add extra credit for every ten comedy attendees
        if (play.type == "comedy") {
            volumeCredits += perf.audience / 5;
        }

        // Print line for this order
        result += " " + play.name + ": $" + std::to_string(thisAmount / 100) + "." + 
                  std::to_string(thisAmount % 100) + " (" + std::to_string(perf.audience) + " seats)\n";
        totalAmount += thisAmount;
    }

    result += "Amount owed is $" + std::to_string(totalAmount / 100) + "." + 
              std::to_string(totalAmount % 100) + "\n";
    result += "You earned " + std::to_string(volumeCredits) + " credits\n";
    return result;
}

int main() {
    Invoice invoice;
    invoice.customer = "BigCo";
    invoice.performances = {
        {"hamlet", 55},
        {"as-like", 35},
        {"othello", 40}
    };

    std::map<std::string, Play> plays = {
        {"hamlet", {"Hamlet", "tragedy"}},
        {"as-like", {"As You Like It", "comedy"}},
        {"othello", {"Othello", "tragedy"}}
    };

    std::cout << statement(invoice, plays) << std::endl;
    return 0;
}