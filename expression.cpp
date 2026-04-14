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

// implementing the function to return the count of the operations in the expression
int BooleanExpression::operation_count() const {
    int count = 0;

    for (int i = 0; i < (int)tokenList.size(); i++) {
        if (isAnyOperator(tokenList[i])) {
            count++;
        }
    }

    return count;
}

// implementing the function to return a vector of the variables used in the expression
vector<char> BooleanExpression::variables_used() const {
    vector<char> variables;
    bool isA = false;
    bool isB = false;
    bool isC = false;

    // iterating through the token list to check for the variables A, B, and C and adding them to the vector if they are used in the expression
    for (int i = 0; i < (int)tokenList.size(); i++) {
        if (tokenList[i] == "A" && !isA) {
            variables.push_back('A');
            isA = true;
        } else if (tokenList[i] == "B" && !isB) {
            variables.push_back('B');
            isB = true;
        } else if (tokenList[i] == "C" && !isC) {
            variables.push_back('C');
            isC = true;
        }
    }

    return variables;
}


// implementing the function to return a vector of the operators used in the expression
vector<string> BooleanExpression::operators_used() const {
    vector<string> used_operators;

    // iterating through the token list to check for the operators then adding them to the vector if they are used in the expression
    for (int i = 0; i < (int)tokenList.size(); i++) {
        if (isAnyOperator(tokenList[i])) {
            add_usedOperator(tokenList[i], used_operators); // prevent duplicates when storing the operators in the vector
        }
    }

    return used_operators;
}

// implementing functions to check variables and type of operators in the expression
bool BooleanExpression::isVariable(string token) const {
    return token == "A" || token == "B" || token == "C";
}

bool BooleanExpression::isLowOperator(string token) const {
    return token == "OR" || token == "XOR" || token == "NOR";
}

bool BooleanExpression::isMiddleOperator(string token) const {
    return token == "AND" || token == "NAND";
}

bool BooleanExpression::isAnyOperator(string token) const {
    return token == "AND" || token == "OR" || token == "NOT" ||
           token == "XOR" || token == "NAND" || token == "NOR";
}

// implementing the function to return the current value of a variable based on its name 
bool BooleanExpression::variable_value(string variableName) const {
    if (variableName == "A") {
        return currentA;
    }
    if (variableName == "B") {
        return currentB;
    }
    return currentC;
}

// implementing the function to add an operator to the list of used operators if it is not already in the list
void BooleanExpression::add_usedOperator(string operatorName, vector<string>& list) const {
    bool alreadyAdded = false;

    for (int i = 0; i < (int)list.size(); i++) {
        if (list[i] == operatorName) {
            alreadyAdded = true;
        }
    }

    if (!alreadyAdded) {
        list.push_back(operatorName);
    }
}

vector<string> BooleanExpression::stepLabels() const {
    BooleanExpression copy = *this;
    bool isValid = true;

    // resetting the current index and variable values to their default state before parsing the expression to generate the step labels
    copy.currentIndex = 0;
    copy.currentA = false;
    copy.currentB = false;
    copy.currentC = false;
    copy.currentStepLabels.clear();
    copy.currentStepValues.clear();

    copy.parseExpression(isValid);
    return copy.currentStepLabels;
}

vector<int> BooleanExpression::evaluateSteps(bool aValue, bool bValue, bool cValue) const {
    BooleanExpression copy = *this; // creating a copy of the current expression object to evaluate the steps without modifying the original object
    bool isValid = true;

    copy.currentIndex = 0;
    copy.currentA = aValue;
    copy.currentB = bValue;
    copy.currentC = cValue;
    copy.currentStepLabels.clear();
    copy.currentStepValues.clear();

    copy.parseExpression(isValid);
    return copy.currentStepValues;
}