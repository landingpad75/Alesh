#pragma once

#include "../expr.hpp"
#include <vector>

class ProgramRoot : public ExprAST {
public:
    explicit ProgramRoot(std::vector<BaseExpression> val) : value(val) {}

    NodeType nodeType() const override {
        return NodeType::ProgramRoot;
    }

    BaseExpression clone() const override {
        return std::make_shared<ProgramRoot>(*this);
    }

    void accept(Visitor& visitor) const override {
        visitor.visit(*this);
    }
private:
    std::vector<BaseExpression> value;
};