#include "expression.h"

using namespace std;

// implementing function to evaluate a factor such as a variable, NOT operation, or bracketed expression
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

// implementing function to evaluate a term by appling middle-precendence operators like AND or NAND to factors
BooleanExpression::result BooleanExpression::parseTerm(bool& isValid) {
    result leftSide = parseFactor(isValid);     // evaluate the first factor and store it as the left side of the term

    while (isValid && currentIndex < (int)tokenList.size() && isMiddleOperator(tokenList[currentIndex])) {
        string operatorName = tokenList[currentIndex];
        currentIndex++;     // move to the next token after reading the operator

        result rightSide = parseFactor(isValid);        // parse the factor on the right side of the operator
        result answer;

        if (operatorName == "NAND") {
            // handle NAND separately since it is NOT(AND)
            result andStep;
            // first apply AND to both sides
            andStep.value = opera_facto.applyBinaryOperator("AND", leftSide.value, rightSide.value);
            andStep.label = "(" + leftSide.label + " AND " + rightSide.label + ")";
            currentStepLabels.push_back(andStep.label);
            currentStepValues.push_back(andStep.value ? 1 : 0);

            // then apply NOT to the result of AND to get the final result of NAND
            answer.value = opera_facto.applyUnaryOperator("NOT", andStep.value);
            answer.label = "NOT(" + andStep.label + ")";
            currentStepLabels.push_back(answer.label);
            currentStepValues.push_back(answer.value ? 1 : 0);
        } 
        else {
            answer.value = opera_facto.applyBinaryOperator(operatorName, leftSide.value, rightSide.value);
            answer.label = "(" + leftSide.label + " " + operatorName + " " + rightSide.label + ")";
            currentStepLabels.push_back(answer.label);
            currentStepValues.push_back(answer.value ? 1 : 0);
        }

        leftSide = answer;  // use the new result as the left side for the next operation
    }

    return leftSide;
}