#pragma once

#include "../expr.hpp"
#include <vector>

class FunctionDeclaration : public ExprAST {
public:
    explicit FunctionDeclaration(
        std::vector<std::string> params,
        std::string name,
        std::string returnType,
        std::vector<BaseExpression> body
    ) : 
        params(params),
        name(name),
        returnType(returnType),
        body(body)
    {}
    
    NodeType nodeType() const override {
        return NodeType::FunctionDeclaration;
    }

    BaseExpression clone() const override {
        return std::make_shared<FunctionDeclaration>(*this);
    }

    void accept(Visitor& visitor) const override {
        visitor.visit(*this);
    }
private:
    std::vector<std::string> params;
    std::string name;
    std::string returnType;
    std::vector<BaseExpression> body;
}; 