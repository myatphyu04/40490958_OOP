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
    int operation_count() const;
    vector<char> variables_used() const;
    vector<string>operators_used() const;

    vector<string> stepLabels() const;
    vector<int> evaluateSteps(bool aValue, bool bValue, bool cValue) const;

private:
    string changeToUpperCase(string text) const;
    bool splitTokens();     // function to split the input expression into tokens and store them in a vector
    bool checkExpression();
    string originalExpression;
    vector<string> tokenList;       // vector to store each element of the input expression

    bool isVariable(string token) const;     // function to check if a token is a variable (A, B, C)
    bool isAnyOperator(string token) const;  // function to check if a token is an operator (AND, OR, NOT, XOR, NAND, NOR)
    void add_usedOperator(string operator_name, vector<string>& operator_list) const;   // function to add an operator to the list of used operators only if it is not already in the list

    bool isLowOperator(string token) const;
    bool isMiddleOperator(string token) const;

    bool variable_value(string variableName) const;
    bool currentA;
    bool currentB;
    bool currentC;

    int currentIndex;
    vector<string> currentStepLabels;
    vector<int> currentStepValues;
    result parseExpression(bool& isValid);
};

#endif