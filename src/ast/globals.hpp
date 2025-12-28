#pragma once
#include <memory>
#include "visitor.hpp"

class ExprAST;
using BaseExpression = std::shared_ptr<ExprAST>;

#define Expression(x) std::shared_ptr<x>

#define cExpression std::make_shared
// well im structuring the tree code, because all the node types will be super long and i hate long files
// type here

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