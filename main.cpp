#include "expression.h"
#include "file_manager.h"
#include "truth_table.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    BooleanExpression expression;

    cout << "*** BOOLEAN TRUTH TABLE SIMULATOR ***\n\n";
    cout << "Enter Boolean Expression (max 3 operators, variables A, B, C): ";

    string inputExpression = "";
    getline(cin, inputExpression);  // read full input expression from the user

    if (!expression.setExpression(inputExpression)) {
        return 0;   // exit the program if the expression is invalid
    }