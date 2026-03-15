count the no of subarrays with exactly k distinct nos.


-- extreme naive sol.

int cnt = 0;

for(int i =0; i < N; i++){
    for(int j = i; j < N; j++){
        // i..j subarray
        unordered_set<int> st;
        for(int l = i;l <= j; l++){
            st.insert(arr[l]);
        }
        if(st.size() == k){
            cnt++;
        }
    }
}

return cnt;

TC: O(n ^ 3) -- not exactly n ^ 3, somewhere around n^3
SC: O(n); -- you might end up storing all the nos in the set, in the worst case.

----------------------------------------------------------------------------

Better solution 

for(int i =0; i < N; i++){
    unordered_set<int> st;
    for(int j = i; j < N; j++){
        // i..j subarray
        st.insert(arr[j]);
        if(st.size() == k) cnt++;
        else if(st.size() > k) break;
    }
}


TC: O(n ^ 2) -- not exactly n ^ 2, somewhere around n^2
SC: O(n); -- you might end up storing all the nos in the set, in the worst case.


----------------------------------------------------------------------------

Most Optimal solution 

I can trim down the problem to figure out the no of subarrays that contains atmost K distint elements.

Once we have figoured out this -- then the ans is pretty straightforward 
ans = cntAtMost(arr, k) - cntAtMost(arr, k-1)

i.e the no of subarrays with at most k distinct elements - no of subarrays with atmost k-1 distinct element 
 = no of subarrays with exactly k distinct elements 

    int countSubarraysWithCountLesserThanEqualToK(vector<int> &arr, int k){
        // edge case: count of subarrays with atmost 0 distinct elements
        if(k == 0) return 0;

        // keep on expanding until count of distinct element <= k
        // the moment count > k -- start trimming
        int n = arr.size();
        unordered_map<int,int> mp; 
        int cnt = 0;
        int l = 0, r = 0;
        while(r < n){
            mp[arr[r]]++;
            while(mp.size() > k){
                mp[arr[l]]--;
                if(mp[arr[l]] == 0) mp.erase(arr[l]);
                l++;
            }
            cnt += (r - l + 1);
            r++;
        }

        return cnt;

    }

    int subarraysWithKDistinct(vector<int>& arr, int k) {
        int n = arr.size();
        // this gives me no of subarrays with sum equivalent to goal
        return countSubarraysWithCountLesserThanEqualToK(arr, k) - countSubarraysWithCountLesserThanEqualToK(arr, k - 1);
    }

    TC: O(2 * n)
    SC: O(n) -- in the worst case, the map might end up storing all the elements hence O(N)

    I cannot this 2 * n to n here because if you just move l by 1 step, and then when r moves and goes out of bounds -- you will miss out on subarrays 
    that contains distinct elements <= k

    imaging arr = [1 2 1 2 3 ] k = 2 
     l
    [1 2 1 2 3 ]
     r 
     cnt = 1 which is <= k 
     ans += (r - l + 1) => cnt += 1 

     l
    [1 2 1 2 3 ]
       r 
     cnt = 2 which is <= k 
     ans += (r - l + 1) => cnt += 2 

     l
    [1 2 1 2 3 ]
         r 
     cnt = 2 which is <= k 
     ans += (r - l + 1) => cnt += 3

     l
    [1 2 1 2 3 ]
           r 
     cnt = 2 which is <= k 
     ans += (r - l + 1) => cnt += 4 

     l
    [1 2 1 2 3 ]
             r 
     cnt = 3 which is > k 
    Ill need to trim down from the left 


    ******* MOVING L BY 1 STEP 
    If I just move l by 1 step 
       l
    [1 2 1 2 3 ]
              r  
     the cnt is still 3 which is > k 
     r moves ahead and we exit 
     

     ********* MOVING L In while loop 
       l
    [1 2 1 2 3 ]
             r  
     the cnt is still 3 which is > k 
         l
    [1 2 1 2 3 ]
             r  
     the cnt is still 3 which is > k 

           l
    [1 2 1 2 3 ]
             r  
     the cnt shrinks down to 2 which is <= k 
     cnt += 2 


   This 2 wont be added if you just move l by 1 step 