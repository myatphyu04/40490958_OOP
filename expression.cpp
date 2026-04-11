#include "expression.h"
#include <iostream>
#include <cctype>
#include <string>
using namespace std;

// implementing the functions declared in the header file to handle the parsing and evaluation of the boolean expression
bool BooleanExpression::setExpression(string input_expression) {
    originalExpression = changeToUpperCase(input_expression);
    tokenList.clear();

    if (!splitTokens()) {
        return false;
    }

    if (!checkExpression()) {
        return false;
    }

    return true;
}

// implementing the function to convert the input expression to uppercase for easier processing
string BooleanExpression::changeToUpperCase(string text) const {
    for (int i = 0; i < (int)text.length(); i++) {
        text[i] = toupper(text[i]);
    }

    return text;
}
