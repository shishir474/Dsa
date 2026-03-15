// count the # of ways in which you can evalute the given input expression to true
ex: s = "T|F&T^F"

// I will simply make the cuts at the operators
We would also need to track the no of ways in which we evaluate a certain partition to false

T ^ T = F
T ^ F = T
F ^ T = T
F ^ F = F

so if we want to evaluate the whole expression to true, we need to consider all possible partitions and their corresponding ways to evaluate to true and false.
if s[k] == ^
the whole expression will evaluate to true if either left or right and not both are true.
So we would need to know # of ways in which the right part evalutes to false and #of ways in which left part evaluates to true. let this be n, m. Then total ways to evaluate the whole expression to true = n * m + (ways left true * ways right true)

// in addition to (i,j) boundaries I'll need a 3rd parameter here that will tell us wheter we want to count the ways to evaluate to true or false
solve(s, i, j, eval_to){

}

dp[i][j][k] tells us #of ways to evaluate s[i..j] to k where k is either true or false.

bool isOperator(char ch){
    if(ch == '&' || ch == '|' || ch == '^') return true;
    return false;
}
solve(s, i, j, eval_to){
    // base condition
    if(i == j){
        if(eval_to == true && s[i] == 'T') return 1;
        if(eval_to == false && s[i] == 'F') return 1;
        return 0;
    }

    for(int k = i; k<=j ;k++){
        if(isOperator(s[k])){       // we dont even need to check  this instead run a loop from for(k = i + 1; k<= j-1; k+=2)
            int left_true = solve(s, i, k-1, true);
            int left_false = solve(s, i, k-1, false);
            int right_true = solve(s, k+1, j, true);
            int right_false = solve(s, k+1, j, false);

            if(s[k] == '&'){
                if(eval_to == true) dp[i][j][true] += left_true * right_true;
                else dp[i][j][false] += left_false * right_false + left_true * right_false + left_false * right_true;
            }
            else if(s[k] == '|'){
                if(eval_to == true) dp[i][j][true] += left_true * right_true + left_true * right_false + left_false * right_true;
                else dp[i][j][false] += left_false * right_false;
            }
            else if(s[k] == '^'){
                if(eval_to == true) dp[i][j][true] += left_true * right_false + left_false * right_true;
                else dp[i][j][false] += left_true * right_true + left_false * right_false;
            }
        }
    }

    return dp[i][j][eval_to];

}

// Time Complexity: O(n^3)
O(n^2) recursive calls and O(n) work during each call

// Space Complexity: O(n^2 * 2)


Follow Up
    1106. Parsing A Boolean Expression. (not an mcm problem though)