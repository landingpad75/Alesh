#pragma once

#include "../expr.hpp"

class BinaryOperation : public ExprAST { // a binop is a math operation like + - / *
public:
    explicit BinaryOperation() {}
    
    NodeType nodeType() const override {
        return NodeType::BinaryOperation;
    }

    BaseExpression clone() const override {
        return std::make_shared<BinaryOperation>(*this);
    }

    void accept(Visitor& visitor) const override {
        visitor.visit(*this);
    }
private:
    char _operator;
    BaseExpression lhs, rhs; // left hand side and right hand side
};