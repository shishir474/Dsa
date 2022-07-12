infix to prefix -> cnan be acheived using infix to postfix conversion
1. reverse infix expression
2. replace '(' with ')' and vice versa in the reversed infix string
3. get postfix for this reverseed infix expression
3. return the reversed postfix -> ans

Input : A * B + C / D
Output : + * A B/ C D 

Input : (A - B/C) * (A/K-L)
Output : *-A/BC-/AKL

// CPP program to convert infix to prefix
#include <bits/stdc++.h>
using namespace std;

int getPriority(char C)
{
	if (C == '-' || C == '+')
		return 1;
	else if (C == '*' || C == '/')
		return 2;
	else if (C == '^')
		return 3;
	return 0;
}

string infixToPostfix(string infix)
{
	infix = '(' + infix + ')';
	int l = infix.size();
	stack<char> char_stack;
	string output;

	for (int i = 0; i < l; i++) {

		// If the scanned character is an
		// operand, add it to output.
		if (isalpha(infix[i]) || isdigit(infix[i]))
			output += infix[i];

		// If the scanned character is an
		// ‘(‘, push it to the stack.
		else if (infix[i] == '(')
			char_stack.push('(');

		// If the scanned character is an
		// ‘)’, pop and output from the stack
		// until an ‘(‘ is encountered.
		else if (infix[i] == ')') {
			while (char_stack.top() != '(') {
				output += char_stack.top();
				char_stack.pop();
			}

			// Remove '(' from the stack
			char_stack.pop();
		}

		// Operator found
		else
		{
			if (isOperator(char_stack.top()))
			{
				if(infix[i] == '^')
				{
					while (getPriority(infix[i]) <= getPriority(char_stack.top()))
					{
						output += char_stack.top();
						char_stack.pop();
					}
					
				}
				else
				{
					while (getPriority(infix[i]) < getPriority(char_stack.top()))
					{
						output += char_stack.top();
						char_stack.pop();
					}
					
				}

				// Push current Operator on stack
				char_stack.push(infix[i]);
			}
		}
	}
	while(!char_stack.empty()){
		output += char_stack.top();
		char_stack.pop();
	}
	return output;
}

string infixToPrefix(string infix)
{
	/* Reverse String
	* Replace ( with ) and vice versa
	* Get Postfix
	* Reverse Postfix * */
	int l = infix.size();

	reverse(infix.begin(), infix.end());

	// Replace ( with ) and vice versa
	for (int i = 0; i < l; i++) {

		if (infix[i] == '(') {
			infix[i] = ')';
		}
		else if (infix[i] == ')') {
			infix[i] = '(';
		}
	}

	string prefix = infixToPostfix(infix);

	// Reverse postfix
	reverse(prefix.begin(), prefix.end());

	return prefix;
}

// Driver code
int main()
{
	string s = ("x+y*z/w+u");
	cout << infixToPrefix(s) << std::endl;
	return 0;
}













'Prefix to infix conversion':

Input :  Prefix :  *+AB-CD
Output : Infix : ((A+B)*(C-D))

Input :  Prefix :  *-A/BC-/AKL
Output : Infix : ((A-(B/C))*((A/K)-L))


Algorithm for Prefix to Infix: 

Read the Prefix expression in reverse order (from right to left)
If the symbol is an operand, then push it onto the Stack
If the symbol is an operator, then pop two operands from the Stack 
Create a string by concatenating the two operands and the operator between them. 
string = (operand1 + operator + operand2) 
And push the resultant string back to Stack
Repeat the above steps until the end of Prefix expression.
At the end stack will have only 1 string i.e resultant string