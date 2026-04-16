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

    // NOT operator handling
    if (currentIndex < (int)tokenList.size() && tokenList[currentIndex] == "NOT") {
        currentIndex++;
        result insideAnswer = parseFactor(isValid); // recursively get the result of the expression inside the NOT operator
        answer.value = opera_facto.applyUnaryOperator("NOT", insideAnswer.value);
        answer.label = "NOT(" + insideAnswer.label + ")";
        currentStepLabels.push_back(answer.label);
        currentStepValues.push_back(answer.value ? 1 : 0);
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