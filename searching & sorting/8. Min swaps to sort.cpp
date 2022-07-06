iven an array of n distinct elements. Find the minimum number of swaps required to sort the array in strictly increasing order.


Example 1:

Input:
nums = {2, 8, 5, 4}
Output:
1

1st step : {(2,0), (8,1), (5,2), (4,3)}
2nd step: {(2,0), (4,3), (5,2), (8,1)}
3rd step: count swaps required

Explaination:
swap 8 with 4.
Example 2:

Input:
nums = {10, 19, 6, 3, 5}
Output:
2
Explaination:
swap 10 with 3 and swap 19 with 5.

int minSwaps(vector<int>&nums)
	{
	    // Code here
	    vector<pair<int, int> > v;
	    for (int i=0;i<nums.size();i++){
	        v.push_back(make_pair(nums[i], i));
	    }
	    sort(v.begin(), v.end());
	    
	     bool visited[v.size()];
	    memset(visited, false, sizeof(visited));
	    
	    int ans = 0;
	    
	    for (int i=0;i<v.size();i++){
	        if (!visited[i]){
	            int c=0, j=i;
	            while (!visited[j]){
	                visited[j] = true;
	                c++;
	                j = v[j].second;
	            }
	            ans+=(c-1);
	        }
	    }
	    
	    
	    return ans;
	}