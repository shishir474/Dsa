Given an array of n distinct elements. Find the minimum number of swaps required to sort the array in strictly increasing order.


Example 1:

Input:
nums = {2, 8, 5, 4}
Output:
1
Explaination:
swap 8 with 4.


Expected Time Complexity: O(nlogn)
Expected Auxiliary Space: O(n)

    int minSwaps(vector<int>&nums)
	{   
	    vector<pair<int,int> > v;
	    for(int i=0;i<nums.size();i++){
	        v.push_back({nums[i], i});
	    }
	    
        // O(nlogn)
	    sort(v.begin(),v.end());
	    
	    vector<int> vis(v.size(),false);
	    
	    int swaps=0;
	    
        // O(n)
	    for(int i=0;i<v.size();i++){
	        if(v[i].second!=i and !vis[i]){
	            int j=i,cnt=0;
	            while(!vis[j]){
	                vis[j]=true;
	                cnt++;
	                j=v[j].second;
	            }
	            
	            swaps+=(cnt-1);
	        }
	    }
	    
	    return swaps;
        
	}