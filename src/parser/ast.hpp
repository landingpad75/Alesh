#pragma once
#include <memory>
#include <vector>

class ExprAST;
using Expression = std::shared_ptr<ExprAST>;

enum class NodeType {
    NumberLiteral,
    StringLiteral,

    ProgramRoot,

    IdentifierExpr,
    AssignmentExpr,

    BinaryOperation,

    FunctionDeclaration,

    ReturnStatement,
};

class NumberLiteral;
class StringLiteral;
class ProgramRoot;
class IdentifierExpr;
class AssignmentExpr;
class BinaryOperation;
class FunctionDeclaration;
class ReturnStatement;

class Visitor {
public:
    virtual ~Visitor() = default;

    virtual void visit(const NumberLiteral& node) = 0;
    virtual void visit(const StringLiteral& node) = 0;
    virtual void visit(const ProgramRoot& node) = 0;
    virtual void visit(const IdentifierExpr& node) = 0;
    virtual void visit(const AssignmentExpr& node) = 0;
    virtual void visit(const BinaryOperation& node) = 0;
    virtual void visit(const FunctionDeclaration& node) = 0;
    virtual void visit(const ReturnStatement& node) = 0;
};

class ExprAST {
public:
    virtual ~ExprAST() = default;
    virtual NodeType nodeType() const = 0;
    virtual Expression clone() const = 0; // deep clone, only use on important moments
    virtual void accept(Visitor& visitor) const = 0;
};

class NumberLiteral : public ExprAST {
public:
    explicit NumberLiteral(double val) : value(val) {}

    NodeType nodeType() const override {
        return NodeType::NumberLiteral;
    }

    Expression clone() const override {
        return std::make_shared<NumberLiteral>(*this);
    }

    void accept(Visitor& visitor) const override {
        visitor.visit(*this);
    }
private:
    double value;
};

class StringLiteral : public ExprAST {
public:
    explicit StringLiteral(std::string val) : value(val) {}

    NodeType nodeType() const override {
        return NodeType::StringLiteral;
    }

    Expression clone() const override {
        return std::make_shared<StringLiteral>(*this);
    }

    void accept(Visitor& visitor) const override {
        visitor.visit(*this);
    }
private:
    std::string value;
};

class ProgramRoot : public ExprAST {
public:
    explicit ProgramRoot(std::vector<Expression> val) : value(val) {} // what what

    NodeType nodeType() const override {
        return NodeType::ProgramRoot;
    }

    Expression clone() const override {
        return std::make_shared<ProgramRoot>(*this);
    }

    void accept(Visitor& visitor) const override {
        visitor.visit(*this);
    }
private:
    std::vector<Expression> value;
};

class IdentifierExpr : public ExprAST {
public:
    explicit IdentifierExpr(std::string val) : name(val) {} // what what

    NodeType nodeType() const override {
        return NodeType::IdentifierExpr;
    }

    Expression clone() const override {
        return std::make_shared<IdentifierExpr>(*this);
    }

    void accept(Visitor& visitor) const override {
        visitor.visit(*this);
    }
private:
    std::string name;
}; // variable/function