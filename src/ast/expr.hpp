#pragma once
#include "globals.hpp"

class Visitor;

class ExprAST {
public:
    virtual ~ExprAST() = default;
    virtual NodeType nodeType() const = 0;
    virtual BaseExpression clone() const = 0; // deep clone, only use on important moments
    virtual void accept(Visitor& visitor) const = 0;
};