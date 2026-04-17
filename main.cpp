#include "expression.h"
#include "file_manager.h"
#include "truth_table.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// function to build the operator explanation text
string buildExplanationText(const BooleanExpression& expression) {
    OperatorFactory operaFactory;
    vector<string> usedOperators = expression.operators_used();     // get the list of operators used in the expression
    string text = "Operators Detected and Explained:\n";

    for (int i = 0; i < (int)usedOperators.size(); i++) {
        text += "- " + usedOperators[i] + ": " + operaFactory.getOperatorDescription(usedOperators[i]) + "\n";
        // add the operator name and its description to the explanation text
    }

    return text;
}

int main() {
    BooleanExpression expression;

    cout << "*** BOOLEAN TRUTH TABLE SIMULATOR ***\n\n";
    cout << "Enter Boolean Expression (max 3 operators, variables A, B, C): ";

    string inputExpression = "";
    getline(cin, inputExpression);  // read full input expression from the user

    if (!expression.setExpression(inputExpression)) {
        return 0;   // exit the program if the expression is invalid
    }