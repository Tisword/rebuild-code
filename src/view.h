#pragma once
#include "statement.h"
#include <iostream>
#include <string>

class View {
public:
    static void displayStatement(const StatementResult& result);
    static std::string generateHtml(const StatementResult& result);
};