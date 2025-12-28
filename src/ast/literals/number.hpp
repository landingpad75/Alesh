#pragma once
#include "../expr.hpp"

class NumberLiteral : public ExprAST {
public:
    explicit NumberLiteral(double val) : value(val) {}

    NodeType nodeType() const override {
        return NodeType::NumberLiteral;
    }

    BaseExpression clone() const override {
        return std::make_shared<NumberLiteral>(*this);
    }

    void accept(Visitor& visitor) const override {
        visitor.visit(*this);
    }
private:
    double value;
};