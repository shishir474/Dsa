#include<bits/stdc++.h>
using namespace std;

//Function to return precedence of operators
int prec(char c) {
	if(c == '^')
		return 3;
	else if(c == '/' || c=='*')
		return 2;
	else if(c == '+' || c == '-')
		return 1;
	else
		return -1;
}

// The main function to convert infix expression
//to postfix expression
void infixToPostfix(string s) {

	stack<char> st; 
	string result;

	for(int i = 0; i < s.length(); i++) {
		char c = s[i];

		// If the scanned character is
		// an operand, add it to output string.
		if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
			result += c;

		else if(c == '(')
			st.push('(');

		else if(c == ')') {
			while(st.top() != '(')
			{
				result += st.top();
				st.pop();
			}
			st.pop();
		}
		//If an operator is scanned
		else {
			while(!st.empty() && prec(s[i]) <= prec(st.top())) {
				result += st.top();
				st.pop();
			}
			st.push(c);
		}
	}

	while(!st.empty()) {
		result += st.top();
		st.pop();
	}

	cout << result << endl;
}

//Driver program to test above functions
int main() {
	string exp = "a+b*(c^d-e)^(f+g*h)-i";
	infixToPostfix(exp);
	return 0;
}




'Postfix to infix conversion'
ab*c+ -> ((a*b)+c)
stack<string> s;
if operand push into stack 
else if (operator) then pop top two operands (op1 op op2) push this string into stack again