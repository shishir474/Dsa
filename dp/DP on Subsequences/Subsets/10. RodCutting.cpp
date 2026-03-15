https://www.naukri.com/code360/problems/rod-cutting-problem_800284?leftPanelTabValue=PROBLEM

Given a rod of length ‘N’ units. The rod can be cut into different sizes and each size has a cost associated with it. Determine the maximum cost obtained by cutting the rod and selling its pieces.

Note:
1. The sizes will range from 1 to ‘N’ and will be integers.

2. The sum of the pieces cut should be equal to ‘N’.

3. Consider 1-based indexing.

Constraints:
1 <= T <= 50
1 <= N <= 100
1 <= A[i] <= 100

Where ‘T’ is the total number of test cases, ‘N’ denotes the length of the rod, and A[i] is the cost of sub-length.

Time limit: 1 sec.
Sample Input 1:
2
5
2 5 7 8 10
8
3 5 8 9 10 17 17 20
Sample Output 1:
12
24
Explanation of sample input 1:
Test case 1:

All possible partitions are:
1,1,1,1,1           max_cost=(2+2+2+2+2)=10
1,1,1,2             max_cost=(2+2+2+5)=11
1,1,3               max_cost=(2+2+7)=11
1,4                 max_cost=(2+8)=10
5                   max_cost=(10)=10
2,3                 max_cost=(5+7)=12
1,2,2               max _cost=(1+5+5)=12    

Clearly, if we cut the rod into lengths 1,2,2, or 2,3, we get the maximum cost which is 12.



Recurrence Relation

// if I dont pick the ith length stick -- I'll simply move to the next index and cap remains same
// Initially the cap will be n -- representing the length of the stick 
// If I pick the ith stick - its length is (i+1). I will gain profit[i] + f(idx, cap - (idx+1))
// since I can use the same stick again hence idx and the length of the stick reduces by (idx+1)
// length of the stick is represented in terms on idx 

----------------------------------------------------

Recursive Solution

int f(int idx, int cap, vector<int> &price){
	if(cap == 0 || idx >= price.size()) return 0;

	int ans = f(idx+1, cap, price);
	if(idx+1 <= cap)
		ans = max(ans, price[idx] + f(idx, cap - (idx+1), price));
	return ans;
}
int cutRod(vector<int> &price, int n)
{
	return f(0,n,price);
}

// TC: O(2^n) - for each index we have 2 choice, either pick the coin or not pick the coin
// SC: O(n) - for the recursion stack

----------------------------------------------------

// Recursion + memoisation

int t[102][102];
int f(int idx, int cap, vector<int> &price){
	if(cap == 0 || idx >= price.size()) return 0;
	if(t[idx][cap] != -1) return t[idx][cap];

	int ans = f(idx+1, cap, price);
	if(idx+1 <= cap)
		ans = max(ans, price[idx] + f(idx, cap - (idx+1), price));
	return t[idx][cap] = ans;
}
int cutRod(vector<int> &price, int n)
{
	memset(t, -1, sizeof(t));
	return f(0,n,price);
}

// TC: O(n * n)
// SC: O(n * n) + O(n) 
// O(n * amount) for dp array and O(n) for recursion stack


----------------------------------------------------

Tabulation Solution -- to get rid of auxilary stack space

int cutRod(vector<int> &price, int n)
{
	vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
	// initialise base case
	// base case 1 - cap == 0 (first col)
	// base case 2 - idx == n (last row)
	// since we base case is 0, I've already assigned it in dp[][]

	for(int i = n-1; i>=0 ;i--){
		for(int j  = 1; j<=n; j++){
			dp[i][j] = dp[i+1][j];
            if(i + 1 <= j){
                dp[i][j] = max(dp[i][j], price[i] + dp[i][j - (i+1)]);
            }
		}
	}

	return dp[0][n];


}

// TC: O(n * n)
// SC: O(n * n) 



------------------------------------------------------
// Space optimisation -- since ith row only depends on (i+1)th row, we can reduce the matrix to 2 rows


int cutRod(vector<int> &price, int n)
{
	vector<vector<int>> dp(2, vector<int>(n+1, 0));
	// initialise base case
	// base case 1 - cap == 0 (first col)
	// base case 2 - idx == n (last row)
	// since we base case is 0, I've already assigned it in dp[][]

	int flag = 0;

	for(int i = n-1; i>=0 ;i--){
		for(int j  = 1; j<=n; j++){
			dp[flag][j] = dp[flag^1][j];
            if(i + 1 <= j){
                dp[flag][j] = max(dp[flag][j], price[i] + dp[flag][j - (i+1)]);
            }
		}
		flag = flag^1;
	}

	flag = flag^1;

	return dp[flag][n];


}

// TC: O(n * n)
// SC: O(n) 