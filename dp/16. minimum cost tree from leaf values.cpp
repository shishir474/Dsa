1130. Minimum Cost Tree From Leaf Values
Given an array arr of positive integers, consider all binary trees such that:

Each node has either 0 or 2 children;
The values of arr correspond to the values of each leaf in an in-order traversal of the tree.
The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree, respectively.
Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node. It is guaranteed this sum fits into a 32-bit integer.

A node is a leaf if and only if it has zero children.


Input: arr = [6,2,4]
Output: 32
Explanation: There are two possible trees shown.
The first has a non-leaf node sum 36, and the second has non-leaf node sum 32.


// Logic:
Possible Partitions
6 | 2, 4
6,2 | 4

We need atleast one element in each partition.
i.  j
6,2,4
so if we denote the boundaries of the partitions as i and j, then I can run a loop k from i to k < j and the partitions will be [i..k] and [k+1..j].

for(int k=i; k<j; k++){
    // partition1: [i..k]
    // partition2: [k+1..j]
    mx1 = max(arr[i..k]) = max value of partition1
    mx2 = max(arr[k+1..j]) = max value of partition2
    // ans for this partiition will be:
    tans = mx1 * mx2 + solve(i,k) + solve(k+1,j)
    ans = min(ans, tans);
}


// base case:
If n==1: only single element, so no non-leaf nodes, return 0.
if n==2: only two elements, so the product of the two elements is the only non-leaf node, return arr[0] * arr[1].

// use max_element(start, end) to find the maximum element in a range. Returns a pointer to the maximum element in the range [start, end).


class Solution {
public:
    int t[41][41];
  int helper(vector<int> &arr, int i, int j){
        if (i==j) return 0;
        if (i+1==j) return arr[i]*arr[j];
      
        if (t[i][j]!=-1) return t[i][j];
        
        int ans = INT_MAX;
        for (int k=i;k<j;k++){
            int mx1=  *max_element(arr.begin()+i, arr.begin()+k+1);
            int mx2 = *max_element(arr.begin()+k+1, arr.begin()+j+1);
            ans = min(ans,mx1*mx2 + helper(arr,i,k) + helper(arr,k+1,j));
        }
        
        return t[i][j] = ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        memset(t,-1,sizeof(t));
        return helper(arr,0,arr.size()-1);
    }
};
TC: O(n^4):
    // O(n^2) for the dp table
    // O(n^2) for the max_element function in the loop
    // So overall complexity is O(n^4).
SC: O(n^2)
    // for the dp table
    // O(n) for the recursion stack space.
    // So overall space complexity is O(n^2).
// where n is the size of the input array arr.

Pattern:
// paritioning problem similar to matrix chain multiplication