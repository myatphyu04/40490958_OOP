#ifndef BOOLEAN_OPERATOR_H
#define BOOLEAN_OPERATOR_H

#include <string>

using namespace std;

// base class for all boolean operators
class BooleanOperator {
public:
    virtual string getDescription() const = 0;
    virtual ~BooleanOperator() {}
};

// base class for binary operators
class BinaryOperator : public BooleanOperator {
public:
    virtual bool apply(bool left, bool right) const = 0;
};

// base class for unary operators
class UnaryOperator : public BooleanOperator {
public:
    virtual bool apply(bool value) const = 0;
};

// derived class for AND
class AndOperator : public BinaryOperator {
public:
    string getDescription() const;
    bool apply(bool left, bool right) const;
};

// derived class for OR
class OrOperator : public BinaryOperator {
public:
    string getDescription() const;
    bool apply(bool left, bool right) const;
};

// derived class for XOR
class XorOperator : public BinaryOperator {
public:
    string getDescription() const;
    bool apply(bool left, bool right) const;
};

// derived class for NAND
class NandOperator : public BinaryOperator {
public:
    string getDescription() const;
    bool apply(bool left, bool right) const;
};

// derived class for NOR
class NorOperator : public BinaryOperator {
public:
    string getDescription() const;
    bool apply(bool left, bool right) const;
};

// derived class for NOT
class NotOperator : public UnaryOperator {
public:
    string getDescription() const;
    bool apply(bool value) const;
};

#endif
