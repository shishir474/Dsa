#include <bits/stdc++.h>
using namespace std;


SOlution:

The idea is to first remove all balanced part of expression. For example, convert “}{{}}{{{” to “}{{{” by removing highlighted part. If we take a closer look, we can notice that, after removing balanced part, we always end up with an expression of the form }}…}{{…{, an expression that contains 0 or more number of closing brackets followed by 0 or more numbers of opening brackets. 
How many minimum reversals are required for an expression of the form “}}..}{{..{” ?. Let m be the total number of closing brackets and n be the number of opening brackets. We need ⌈m/2⌉ + ⌈n/2⌉ reversals. For example }}}}{{ requires 2+1 reversals.

TC:O(n) and SC:O(1)


int countMinReversals(string expr)
{
	int len = expr.length();

	// Expressions of odd lengths
	// cannot be balanced
	if (len % 2 != 0) {
		return -1;
	}
	int left_brace = 0, right_brace = 0;
	int ans;
	for (int i = 0; i < len; i++) {
		if (expr[i] == '{') {
			left_brace++;
		}
		else {
			if (left_brace == 0) {
				right_brace++;
			}
			else {
				left_brace--;
			}
		}
	}
	ans = ceil(left_brace / 2.0) + ceil(right_brace / 2.0);
	return ans;
}

// Driver program to test above function
int main()
{
	string expr = "}}{{";
	cout << countMinReversals(expr);
	return 0;
}
