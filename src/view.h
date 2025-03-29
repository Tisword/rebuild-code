#ifndef VIEW_H
#define VIEW_H

#include "statement.h"
#include <iostream>

class View {
public:
    static void displayStatement(const StatementResult& result);
};

#endif // VIEW_H