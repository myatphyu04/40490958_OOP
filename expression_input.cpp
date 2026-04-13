#include "expression.h"

using namespace std;

// implementing the function to split the input expression into tokens and store them in a vector
bool BooleanExpression::splitTokens() {
    string currentWord = "";

    for (int i = 0; i < (int)originalExpression.length(); i++) {
        char ch = originalExpression[i];

        // if the character is a space, it indicates the end of a token so add the current word to the token list and reset it
        if (ch == ' ') {
            if (currentWord != "") {
                tokenList.push_back(currentWord);
                currentWord = "";
            }
        } 
        // if the character is a parenthesis, add the current word to the token list if it's not empty
        else if (ch == '(' || ch == ')') {
            if (currentWord != "") {
                tokenList.push_back(currentWord);
                currentWord = "";
            }

            // adding the parenthesis as a separate token to the token list
            string oneCharacter = "";
            oneCharacter += ch;
            tokenList.push_back(oneCharacter);
        }
        else {
            currentWord += ch;
        }
    }

    // adding the last token to the token list if it's not empty
    if (currentWord != "") {
        tokenList.push_back(currentWord);
    }

    if (tokenList.size() == 0) {
        return false;
    }

    return true;
}


// implementing the function to check if the expression is valid by checking if all tokens are either variables, operators, or parentheses, and also checking if the number of operations does not exceed 3
bool BooleanExpression::checkExpression() {
    for (int i = 0; i < (int)tokenList.size(); i++) {
        string token = tokenList[i];

        if (!isVariable(token) && !isAnyOperator(token) && token != "(" && token != ")") {
            return false;
        }
    }

    if (operation_count() > 3) {
        return false;
    }

    return true;
}
