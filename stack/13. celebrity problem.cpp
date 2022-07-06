Celebrity is the person who knows everyone at the party, whereas nobody knows him.We have to find celebrity
mat[i][j] = 1 -> ith person knows jth person
// sol1. check each person if he is a celebrity or not
Tc; O(n^2)

Input:
MATRIX = { {0, 0, 1, 0},
           {0, 0, 1, 0},
           {0, 0, 0, 0},
           {0, 0, 1, 0} }
Output:id = 2
Explanation: The person with ID 2 does not 
know anyone but everyone knows him

Input:
MATRIX = { {0, 0, 1, 0},
           {0, 0, 1, 0},
           {0, 1, 0, 0},
           {0, 0, 1, 0} }
Output: No celebrity
Explanation: There is no celebrity.

// optimised sol.
facts:
1. if A knows B, then A cannot be celebrity bcoz celebrity knows nobody, but since A knows B, A cannot be our ans
2. if A does not know B, then B cannot be celebrity bcoz everybody knows celebrity.
each time we wiil consider two persons and will discard either of them 
so store all the persons id in a stack. Pop the first two elements and then push the one which can possibly me ans,while disregarding the other
do this until size of stack is not equal to 1. 
now st.top() can be my possible ans, but not necessary. so ensure if st.top() is my celebrity or not. 
If its not then there are no celebrity present

TC: O(n), sc:O(n)