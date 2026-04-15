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

    if (isVariable(tokenList[currentIndex])) {
        answer.label = tokenList[currentIndex];
        answer.value = variable_value(tokenList[currentIndex]);
        currentIndex++;
        return answer;
    }

    isValid = false;
    return answer;
}