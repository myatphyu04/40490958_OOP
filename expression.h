#ifndef BOOLEAN_EXPRESSION_H
#define BOOLEAN_EXPRESSION_H

#include "operator_factory.h"   // including the operator factory header file to use its functions in this class

#include <string>
#include <vector>

using namespace std;

// creating a class to handle the boolean expression parsing and evaluation
class BooleanExpression {
public:
    // creating a struct to store the result of parsing an expression, which includes the value of the expression and a label for the step
    struct result {
        bool value;
        string label;
    };

    bool setExpression(string input_expression);
    string input() const;

private:
    string changeToUpperCase(string text) const;
    bool splitTokens();     // function to split the input expression into tokens and store them in a vector
    bool checkExpression();
    string originalExpression;
    vector<string> tokenList;       // vector to store the tokens of the input expression
};

#endif