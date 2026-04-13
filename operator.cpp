#include "operator.h"

using namespace std;

// implementing the functions declared in the header file for each operator class to return the description and apply the operator to the inputs

string AndOperator::getDescription() const {
    return "True only if both inputs are true.";
}

bool AndOperator::apply(bool left, bool right) const {
    return left && right;
}

string OrOperator::getDescription() const {
    return "True if at least one input is true.";
}

bool OrOperator::apply(bool left, bool right) const {
    return left || right;
}

string XorOperator::getDescription() const {
    return "True only when the inputs are different.";
}

bool XorOperator::apply(bool left, bool right) const {
    return left != right;
}

string NandOperator::getDescription() const {
    return "True if at least one input is false.";
}

bool NandOperator::apply(bool left, bool right) const {
    return !(left && right);
}

string NorOperator::getDescription() const {
    return "True only if both inputs are false.";
}

bool NorOperator::apply(bool left, bool right) const {
    return !(left || right);
}

string NotOperator::getDescription() const {
    return "Inverts the input.";
}

bool NotOperator::apply(bool value) const {
    return !value;
}