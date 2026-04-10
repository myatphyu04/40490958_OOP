#include "operator_factory.h"

using namespace std;

// implementing the function to get the description of the operator from the user input
string OperatorFactory::getOperatorDescription(string operatorName) const {
    if (operatorName == "AND") {
        return "True only if both inputs are true.";
    }
    if (operatorName == "OR") {
        return "True if at least one input is true.";
    }
    if (operatorName == "NOT") {
        return "Inverts the input.";
    }
    if (operatorName == "XOR") {
        return "True only when the inputs are different.";
    }
    if (operatorName == "NAND") {
        return "True if at least one input is false.";
    }
    if (operatorName == "NOR") {
        return "True only if both inputs are false.";
    }

    return "";
}

// implementing the function to apply the binary operator to the inputs and return the result
bool OperatorFactory::applyBinaryOperator(string operatorName, bool left, bool right) const {
    if (operatorName == "AND") {
        return left && right;
    }
    if (operatorName == "OR") {
        return left || right;
    }
    if (operatorName == "XOR") {
        return left != right;
    }
    if (operatorName == "NAND") {
        return !(left && right);
    }
    if (operatorName == "NOR") {
        return !(left || right);
    }

    return false;
}

// implementing the function to apply the NOT operator to the input and return the result
bool OperatorFactory::applyUnaryOperator(string operatorName, bool value) const {
    if (operatorName == "NOT") {
        return !value;
    }

    return false;
}
