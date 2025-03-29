#include "statement.h"
#include "view.h"
#include "crow.h" // Crow 的头文件


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

    // 启动 HTTP 服务器
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([&result]() {
        return View::generateHtml(result);
    });

    app.port(8080).multithreaded().run();

    return 0;
}