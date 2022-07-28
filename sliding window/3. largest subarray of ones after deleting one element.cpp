Given a binary array, U should delete one element from it,
return the lngth of the longest non empty subarrau containing only 1s


solution:
The question is same as atmost 1 zero is allowed. 
TC: O(n); 
SC: O(n);  used map for storing freq. Map size at max will be 2 as there are only 0's and 1;s in string
So sc can be said to be O(1);

class Solution {
public:
    int longestSubarray(vector<int>& a) {
        map<int,int> mp;
        int ans=0;
        int i=0,j=0,n=a.size();
        while(j<n){
            mp[a[j]]++;
            if(mp[0] > 1){
                ans = max(ans,j-i);
                while(mp[0]>1){
                    mp[a[i]]--;
                    i++;
                }
            }
            j++;
        }
        
        ans=max(ans,j-i);
        
        return ans-1;
        
    }
};

Extension problem:
Return the length of the longest subarray with atmost k zeros. IN the above problm atmost 1 zero was allowed