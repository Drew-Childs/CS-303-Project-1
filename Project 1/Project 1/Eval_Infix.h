//Drew Childs

#pragma once

#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

class evalInfix {
public:
	evalInfix();
	evalInfix(string infixExpression);

	void addOperator(string Operator);
	void addOperand(string Operand);

	int returnSolution();
	int returnPrecedence(string Operator);

	void evalOperator(string Operator);
	void evalOperand(int Operand);

	void performOperation(string Operator);

private:
	stack<string> operators;
	stack<int> operands;

	int solution;
	string expression;
};