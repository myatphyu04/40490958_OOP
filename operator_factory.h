// operator_factory.h
#ifndef OPERATOR_FACTORY_H
#define OPERATOR_FACTORY_H

#include <string>

using namespace std;

// creating a class to handle the logic gate operations and return the results based on the operator and inputs
class OperatorFactory {
public:
    string getOperatorDescription(string operatorName) const;   // function to get the description of the operator from the user input
    bool applyBinaryOperator(string operatorName, bool left, bool right) const;     // function to apply the operator to the inputs and return the result
    bool applyUnaryOperator(string operatorName, bool value) const;     // function to apply the NOT operator to the input and return the result
};

#endif