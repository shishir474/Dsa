Given a string, 

find the length of the longest substring without repeating characters.

Example:

The longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.

For "bbbbb" the longest substring is "b", with the length of 1.




int Solution::lengthOfLongestSubstring(string A) {
// TC: O(N)+O(N) = O(2N), SC: O(256)
    // int ans=0;
    // set<char> s;
    // int i=0,j=0;
    // while(j<A.length()){
    //     if (s.count(A[j])==0){
    //         s.insert(A[j]);
    //         ans=  max(ans,(int)s.size());
    //         j++;
    //     }else{
    //         s.erase(A[i]);
    //         i++;
    //     }
    // }

    // return ans;



// Most optimised solution: O(N) time

    //     int ans=0;
    // map<char,int> mp;
    // int i=0,j=0;
    // while(j<A.length()){
    //     if (mp.count(A[j])==1){
    //         if (mp[A[j]] >= i){
    //             i = mp[A[j]]+1;
    //         }
    //     }
    //     mp[A[j]] = j;
    //     ans = max(ans, j-i+1);
    //     j++;
    // }

    // return ans;
    
    
           int ans=0;
    map<char,int> mp;
    int i=0,j=0;
    while(j<A.length()){
     mp[A[j]]++;
     if(mp[A[j]] > 1){
         ans = max(ans, j-i);
         while(mp[A[j]] > 1){
             mp[A[i]]--;
             i++;
         }
     }
     j++;
    }
    ans = max(ans, j-i);
    return ans;
}
