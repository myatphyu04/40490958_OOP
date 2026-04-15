#include "expression.h"

using namespace std;

BooleanExpression::result BooleanExpression::parseFactor(bool& isValid) {
    result answer;
    answer.value = false;
    answer.label = "";

    if (currentIndex >= (int)tokenList.size()) {
        isValid = false;
        return answer;
    }

    // bracket handling
    if (tokenList[currentIndex] == "(") {
    currentIndex++;
    answer = parseExpression(isValid);

        if (!isValid) {
            return answer;
        }

        if (currentIndex >= (int)tokenList.size() || tokenList[currentIndex] != ")") {
            isValid = false;
            return answer;
        }

        currentIndex++;
        return answer;
    }

    // variables handling
    if (isVariable(tokenList[currentIndex])) {
        answer.label = tokenList[currentIndex];
        answer.value = variable_value(tokenList[currentIndex]);
        currentIndex++;
        return answer;
    }

    isValid = false;
    return answer;

}