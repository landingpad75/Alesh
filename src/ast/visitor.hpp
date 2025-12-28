#pragma once

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