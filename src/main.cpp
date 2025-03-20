#include "statement.h"
#include <iostream>

int main() {
    // 示例数据
    Plays plays = {
        {"hamlet", {"Hamlet", "tragedy"}},
        {"as-like", {"As You Like It", "comedy"}}
    };

    Invoice invoice = {
        "BigCo",
        {
            {"hamlet", 55},
            {"as-like", 35}
        }
    };

    try {
        std::cout << Statement::generate(invoice, plays);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}