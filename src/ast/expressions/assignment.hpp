#pragma once

#include "../expr.hpp"

class AssignmentExpr : public ExprAST {
public:
    explicit AssignmentExpr(BaseExpression target, BaseExpression value) : target(target), value(value) {}
    
    NodeType nodeType() const override {
        return NodeType::AssignmentExpr;
    }

    BaseExpression clone() const override {
        return cExpression<AssignmentExpr>(*this);
    }

    void accept(Visitor& visitor) const override {
        visitor.visit(*this);
    }
private:
    BaseExpression target;
    BaseExpression value;
};