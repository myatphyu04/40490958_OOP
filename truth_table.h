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

private:
    string makeSpaces(int count) const;
    string makeDashes(int count) const;
    string fitCell(string text, int width) const;
    vector<string> buildHeaders(const BooleanExpression& expression) const;
    vector<int> buildWidths(const vector<string>& headers) const;

};

#endif
