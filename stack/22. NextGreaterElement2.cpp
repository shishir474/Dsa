// https://leetcode.com/problems/next-greater-element-ii/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        stack<int> s; 
        // Hypothetically double the array whenever dealing with circular array
        for(int i=2*n-1; i>=0; i--){
            while(!s.empty() and s.top()<=nums[i%n]){
                s.pop();
            }
            if (i < n){  // for this index we need to compute the nge
                if(s.empty()){
                    res[i] = -1;
                }
                else{
                    res[i] = s.top();
                }
            }
            s.push(nums[i%n]);
        }

        return res;
    }
};

// TC: O(N)
// SC: O(N)