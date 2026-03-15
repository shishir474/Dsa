// https://www.youtube.com/watch?v=ZHyb-A2Mte4&ab_channel=takeUforward 
// https://www.youtube.com/watch?v=zoilQD1kYSg&ab_channel=takeUforward. -- covers the edge case in count subsets where arr[i] can be 0 as well
// watch again



recurrence relation --> recursive solution --> tabulation solution ---> space optimisation

// One edge case in this problem is 
// Here the problem constraint clearly states 1 <= arr[i] <= 1000
{0,0,1} and target = 1 --> our solution will gives 1 subs which is {1}
but correct ans would be {0,1}, {0,1}, {0,0,1}, {1}

What does this zero contribute to sum? -- nothing but it does contribute to the #of subsets
count the #of zeroes -- 2
0_
_0
00
__

so if 0 <= arr[i], return pow(2,cnt)*ans

const int mod = 1e9 + 7;
int t[102][1002];
int f(int idx, int target, vector<int>& arr){
	if(target == 0) return 1;		// if target == 0 --> found one subset
	if(idx == 0){					// another base case: if I'm at the last index, I'll be able to acheive target only iff arr[0] == target. If this is true we return 1 else return 0
		return arr[idx] == target;
	}
	if(t[idx][target] != -1) return t[idx][target];

	int not_take = f(idx-1, target, arr);

	int take = 0;

	if(arr[idx] <= target){
		take = f(idx-1, target-arr[idx], arr);
	}
	
	return (take + not_take)%mod;
}
int findWays(vector<int>& arr, int k)
{
	int n = arr.size();
	memset(t, -1, sizeof(t));
	int ans = f(n-1,k,arr);
	// f(n-1, k) means the #of subsets till n-1th index whose sum is k

	return ans;
}


-- tabulation solution
int t[n][target+1];
for(int i = 0; i <= n; i++) t[i][0] = 1; // base case: if target == 0, we can always form a subset with sum 0
if(arr[0] <= target) t[0][arr[0]] = 1;

// .. complete this later 



