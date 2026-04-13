#include "operator_factory.h"

using namespace std;

// implementing the function to get the description of the operator from the user input by creating an instance of the corresponding operator class then calling its function
string OperatorFactory::getOperatorDescription(string operatorName) const {
    if (operatorName == "AND") {
        AndOperator op;
        return op.getDescription();
    }
    if (operatorName == "OR") {
        OrOperator op;
        return op.getDescription();
    }
    if (operatorName == "NOT") {
        NotOperator op;
        return op.getDescription();
    }
    if (operatorName == "XOR") {
        XorOperator op;
        return op.getDescription();
    }
    if (operatorName == "NAND") {
        NandOperator op;
        return op.getDescription();
    }
    if (operatorName == "NOR") {
        NorOperator op;
        return op.getDescription();
    }

    return "";
}

// implementing the function to apply the operator to the inputs and return the result by creating an instance of the corresponding operator class then calling its function
bool OperatorFactory::applyBinaryOperator(string operatorName, bool left, bool right) const {
    if (operatorName == "AND") {
        AndOperator op;
        return op.apply(left, right);
    }
    if (operatorName == "OR") {
        OrOperator op;
        return op.apply(left, right);
    }
    if (operatorName == "XOR") {
        XorOperator op;
        return op.apply(left, right);
    }
    if (operatorName == "NAND") {
        NandOperator op;
        return op.apply(left, right);
    }
    if (operatorName == "NOR") {
        NorOperator op;
        return op.apply(left, right);
    }

    return false;
}


// implementing the function to apply the NOT operator to the input and return the result by creating an instance of the NotOperator class then calling its apply function
bool OperatorFactory::applyUnaryOperator(string operatorName, bool value) const {
    if (operatorName == "NOT") {
        NotOperator op;
        return op.apply(value);
    }

    return false;
}
