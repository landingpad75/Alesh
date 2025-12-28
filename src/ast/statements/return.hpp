#pragma once

#include "../expr.hpp"

class ReturnStatement : public ExprAST {
public:
    explicit ReturnStatement(BaseExpression value) : returnedValue(value) {}
    
    NodeType nodeType() const override {
        return NodeType::ReturnStatement;
    }

    BaseExpression clone() const override {
        return std::make_shared<ReturnStatement>(*this);
    }

    void accept(Visitor& visitor) const override {
        visitor.visit(*this);
    }
private:
    BaseExpression returnedValue;
};