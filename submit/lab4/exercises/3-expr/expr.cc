#include "expr.hh"

#include <string>
#include <sstream>

std::string
IntExpr::toString() const
{
  std::stringstream s;
  s << value;
  return s.str();
}

static std::string
binaryExprToString(std::string op, ExprPtr left, ExprPtr right)
{
  std::stringstream s;
  s << "(" << *left << ") " << op << " (" << *right << ")";
  return s.str();
}

std::string
AddExpr::toString() const
{
  return binaryExprToString("+", left, right);
}

std::string
SubExpr::toString() const
{
  return binaryExprToString("-", left, right);
}

std::string
MulExpr::toString() const
{
  return binaryExprToString("*", left, right);
}

std::string
DivExpr::toString() const
{
  return binaryExprToString("/", left, right);
}

int
AddExpr::eval() const
{
  return left->eval() + right->eval();
}

int
SubExpr::eval() const
{
  return left->eval() - right->eval();
}

int
MulExpr::eval() const
{
  return left->eval() * right->eval();
}

int
DivExpr::eval() const
{
  return left->eval() / right->eval();
}
