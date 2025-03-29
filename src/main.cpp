#include "statement.h"
#include "view.h"

int main() {
    Plays plays = {
        {"hamlet", {"Hamlet", "tragedy"}},
        {"as-like", {"As You Like It", "comedy"}},
        {"othello", {"Othello", "tragedy"}}
    };

    Invoice invoice = {
        "BigCo",
        {
            {"hamlet", 55},
            {"as-like", 35},
            {"othello", 40}
        }
    };

    Statement statement;
    StatementResult result = statement.generate(invoice, plays);

    // 调用 View 层展示数据
    View::displayStatement(result);

    return 0;
}