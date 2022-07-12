Examples: 

Input :  Prefix :  *+AB-CD
Output : Postfix : AB+CD-*
Explanation : Prefix to Infix :  (A+B) * (C-D)
              Infix to Postfix :  AB+CD-*

Input :  Prefix :  *-A/BC-/AKL
Output : Postfix : ABC/-AK/L-*
Explanation : Prefix to Infix :  (A-(B/C))*((A/K)-L)
              Infix to Postfix : ABC/-AK/L-* 


Algorithm for Prefix to Postfix: 

Read the Prefix expression in reverse order (from right to left)
If the symbol is an operand, then push it onto the Stack
If the symbol is an operator, then pop two operands from the Stack 
Create a string by concatenating the two operands and the operator after them. 
string = operand1 + operand2 + operator 
And push the resultant string back to Stack
Repeat the above steps until end of Prefix expression.



// CPP Program to convert prefix to postfix
#include <iostream>
#include <stack>
using namespace std;

// function to check if character is operator or not
bool isOperator(char x)
{
	switch (x) {
	case '+':
	case '-':
	case '/':
	case '*':
		return true;
	}
	return false;
}

// Convert prefix to Postfix expression
string preToPost(string pre_exp)
{

	stack<string> s;
	int length = pre_exp.size();

	// reading from right to left
	for (int i = length - 1; i >= 0; i--)
	{
		if (isOperator(pre_exp[i]))
		{
			// pop two operands from stack
			string op1 = s.top();
			s.pop();
			string op2 = s.top();
			s.pop();

			// concat the operands and operator
			string temp = op1 + op2 + pre_exp[i];

			// Push string temp back to stack
			s.push(temp);
		}

		// if symbol is an operand
		else {
			s.push(string(1, pre_exp[i]));
		}
	}

	return s.top();
}

int main()
{
	string pre_exp = "*-A/BC-/AKL";
	cout << "Postfix : " << preToPost(pre_exp);
	return 0;
}







'Algorithm for Postfix to Prefix:'
infix: (A+B)*(C-D)
prefix: *+AB-CD
postfix: AB+CD-*
 
Read the Postfix expression from left to right
If the symbol is an operand, then push it onto the Stack
If the symbol is an operator, then pop two operands from the Stack 
Create a string by concatenating the two operands and the operator before them. 
string = operator + operand2 + operand1 
And push the resultant string back to Stack
Repeat the above steps until end of Postfix expression.
