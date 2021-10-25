//Drew Childs

#include "Eval_Infix.h"


int main() {
	evalInfix infixExpression_1("(8 - 12 + 300) * 6 - ((13 + 7) * 24)");
	evalInfix infixExpression_2;
	evalInfix infixExpression_3("1");

	
	infixExpression_2.addOperator("(");
	infixExpression_2.addOperator("(");
	infixExpression_2.addOperand("4");
	infixExpression_2.addOperator("*");
	infixExpression_2.addOperand("2");
	infixExpression_2.addOperator(")");
	infixExpression_2.addOperator("-");
	infixExpression_2.addOperator("(");
	infixExpression_2.addOperand("4");
	infixExpression_2.addOperator("^");
	infixExpression_2.addOperand("6");
	infixExpression_2.addOperator(")");
	infixExpression_2.addOperator(")");
	infixExpression_2.addOperator("/");
	infixExpression_2.addOperand("2");
	

	cout << infixExpression_1.returnSolution() << endl;
	cout << infixExpression_2.returnSolution() << endl;
	cout << infixExpression_3.returnSolution() << endl;
}