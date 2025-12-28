#pragma once
#include "../expr.hpp"

class StringLiteral : public ExprAST {
public:
    explicit StringLiteral(std::string val) : value(val) {}

    NodeType nodeType() const override {
        return NodeType::StringLiteral;
    }

    BaseExpression clone() const override {
        return cExpression<StringLiteral>(*this);
    }

    void accept(Visitor& visitor) const override {
        visitor.visit(*this);
    }
private:
    std::string value;
};