// The original ask of the CSES problem was to print just the length of the LIS. This could be done in O(nlogn) using binary search and greedy approach

// Printing LIS in O(nlogn) --> PENDING

// This function prints the lexicographically smallest LIS (https://www.geeksforgeeks.org/problems/printing-longest-increasing-subsequence/0)

// TC: O(n^2) for constructing the t array and then for constructing lis O(n)

vector<int> longestIncreasingSubsequence(int n, vector<int>& a) {
        vector<int> t(n,1);
        int ans=1,idx=0; // if we have only one element ex: [1]
        
        // assumes that we have atleast 2 elements
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(a[i]>a[j]){
                    t[i]=max(t[i],t[j]+1);
                }
            }
            if(t[i]> ans){
                ans=t[i];
                idx=i;
            }
        }
        
        // Construction of LIS is bit tricky. here we are asked to print the lis which is the lexicographically smallest index wise 
        // That's why used map and bit of logic
        
        map<int, vector<int>> mp; // value -> positions
        for(int i=0;i<n;i++){ // created a map to iterate over the positions of specific length
            mp[t[i]].push_back(i);
        }
        
        int length = ans;
        vector<int> lis;
        lis.push_back(a[idx]); // idx points to first pos where we have the lis value
        length = length-1;
        
        while(length > 0){
            // Iterate over all positions where we have curr length
            for(auto it: mp[length]){
                // position should be on left hand side of idx and the value at that position < a[idx] -> Then its a valid position
                // Add the element to the lis, decrease the length and update the idx to curr position it
                if(it < idx and a[it] < a[idx]){ 
                    lis.push_back(a[it]);
                    idx = it;
                    length -= 1;
                }
            }
        }
        
        // since lis is formed in decreasing fashion reverse it and then return 
        reverse(lis.begin(), lis.end());
        return lis;
        
        
    }