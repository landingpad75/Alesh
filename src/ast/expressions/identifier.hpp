#pragma once

#include "../expr.hpp"

class IdentifierExpr : public ExprAST {
public:
    explicit IdentifierExpr(std::string val) : name(val) {}

    NodeType nodeType() const override {
        return NodeType::IdentifierExpr;
    }

    BaseExpression clone() const override {
        return std::make_shared<IdentifierExpr>(*this);
    }

    void accept(Visitor& visitor) const override {
        visitor.visit(*this);
    }
private:
    std::string name;
};