//Drew Childs

#include "Eval_Infix.h"

//default constructor
evalInfix::evalInfix() {
	expression = "";
	solution = 0;
}

//constructor to assign expression
evalInfix::evalInfix(string infixExpression) {
	expression = infixExpression;
	solution = 0;
}

//allows user to push new operators to an existing expression
void evalInfix::addOperator(string Operator) {
	expression += Operator;
}

//allows user to push new operands to existing expression
void evalInfix::addOperand(string Operand) {
	expression += Operand;
}

//evaluates and returns solution
int evalInfix::returnSolution() {
	string tempStr;

	//iterates through expression and pushes back each element
	for (int i = 0; i < expression.length(); i++) {
		if (expression[i] == '^' || expression[i] == '*' || expression[i] == '/' || expression[i] == '+' || expression[i] == '-' || expression[i] == '(' || expression[i] == ')') {

			if (tempStr != "") {
				evalOperand(stoi(tempStr));
			}
			tempStr = expression[i];
			evalOperator(tempStr);
			tempStr = "";
		}
		else if (expression[i] != ' ') {
			tempStr += expression[i];

			if (i == expression.length() - 1) {
				evalOperand(stoi(tempStr));
			}
		}
	}

	//once everything has been added, any existing elements will be processed
	int temp = operators.size();

	for (int i = 0; i < temp; i++) {
		if (operators.top() == "(") {
			operators.pop();
		}
		else {
			performOperation(operators.top());
			operators.pop();
		}
	}

	solution = operands.top();
	return solution;
}

//function to determine precedence of operators
int evalInfix::returnPrecedence(string Operator) {
	if (Operator == "^") {
		return 3;
	}
	else if (Operator == "*" || Operator == "/") {
		return 2;
	}
	else if (Operator == "+" || Operator == "-") {
		return 1;
	}
}

//This function will add operators to the stack and call for operations to be performed
void evalInfix::evalOperator(string Operator) {

	if (!operators.empty()) {
		if (operators.top() == "(" || Operator == "(") {
			operators.push(Operator);
		}

		//will pop until it finds the closing parenthesis. Once found, will also pop the '('
		else if (Operator == ")") {
			while (operators.top() != "(") {
				performOperation(operators.top());
				operators.pop();
			}
			operators.pop();
		}

		//if operators have equal precendence
		else if (returnPrecedence(Operator) == returnPrecedence(operators.top())) {
			performOperation(operators.top());
			operators.pop();
			operators.push(Operator);
		}

		//if current operator has less precedence as top
		else if (returnPrecedence(Operator) < returnPrecedence(operators.top())) {
			performOperation(operators.top());
			operators.pop();
			evalOperator(Operator);
		}

		//if current operator has more precedence than top
		else if (returnPrecedence(Operator) > returnPrecedence(operators.top())) {
			operators.push(Operator);
		}
	}
	else {
		operators.push(Operator);
	}
}

//adds operands to stack
void evalInfix::evalOperand(int Operand) {
	operands.push(Operand);
}

//This function will perform a given operation on the operand stack and store the result
void evalInfix::performOperation(string Operator) {
	int top = 0, belowTop = 0, result = 0;

	char charOperator = Operator[0];

	top = operands.top();
	operands.pop();
	belowTop = operands.top();
	operands.pop();

	switch (charOperator)
	{
	case '*':
		result = belowTop * top;
		break;
	case '/':
		result = belowTop / top;
		break;
	case '+':
		result = belowTop + top;
		break;
	case '-':
		result = belowTop - top;
		break;
	case '^':
		result = pow(belowTop, top);
		break;

	default:
		break;
	}

	operands.push(result);
}