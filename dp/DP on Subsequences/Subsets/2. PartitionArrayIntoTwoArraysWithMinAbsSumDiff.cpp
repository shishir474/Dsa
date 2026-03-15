ER Diagram
Class Diagram
UML Diagram
Data Modelling

whats the difference between ER and Class Diagrams?

https://www.naukri.com/code360/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494?leftPanelTabValue=PROBLEM

Given an array of n non negative integers, your task is to partittion the array into 2 subsets such that the absolute difference between the sum of the elements in the two subsets is minimized.
1 <= 'n' <= 10^3
0 <= 'arr'[i] <= 10^3
0 <= 𝚺 'arr'[i] <= 10^4,

int minSubsetSumDifference(vector<int>& arr, int n)
{
	int target = 0;
	for(auto val: arr) target+=val;

	int t[n+1][target+1];
	memset(t, -1, sizeof(t));
	for(int i = 0; i<=n; i++) t[i][0] = 1;
	for(int j = 1; j<= target; j++) t[n][j] = 0;
	for(int i = n-1; i>=0; i--){
		for(int j = 1; j <= target; j++){
			if(arr[i] <= j){
				t[i][j] = t[i+1][j] or t[i+1][j-arr[i]];
			}
			else{
				t[i][j] = t[i+1][j];
			}
		}
	}

	// for(int i=0; i<=n; i++){
	// 	for(int j=0; j<=target; j++){
	// 		cout<<t[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	int ans = INT_MAX;
	for(int j=0;j<=target;j++){
		// cout<<t[n][j]<<" ";
		if(t[0][j] == 1){
			// cout<<j<<" ";
			ans = min(ans, abs((2*j) - target));
		}
	}
	return ans;

}


Follow up:
2035. Partition Array Into Two Arrays to Minimize Sum Difference
same problem but arr[i] can be -ve as well.
