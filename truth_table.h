#ifndef TRUTH_TABLE_H
#define TRUTH_TABLE_H

#include "expression.h"

#include <string>
#include <vector>

using namespace std;

// creating a class to handle the generation of the truth table for a given boolean expression
class TruthTable {
public:
    string generate(const BooleanExpression& expression) const;
};

#endif
