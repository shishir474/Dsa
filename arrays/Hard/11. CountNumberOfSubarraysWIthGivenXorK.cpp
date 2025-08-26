Count the no of subarrays with xor k

brute:
    consider all subarrays and calc their xor -- 3 nested for loops
    How do you consider all subarray -- run 2 nested for loops

    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int curr_xor = 0;
            for(int k = i; k <= j; k++)
                curr_xor = curr_xor ^ arr[k];

            if(curr_xor == target) count++;
        }
    }

    TC: somewhere around O(n^3)
    SC: O(1)


    this can be optimised to n^2 by calculating the curr_xor in the 2nd for loop itslef
    eventually as j is moving the next subarray is including one more element. We are essentially keeping track of running xor  

    for(int i = 0; i < n; i++){
        int curr_xor = 0;
        for(int j = i; j < n; j++){
            curr_xor = curr_xor ^ arr[j];
            if(curr_xor == target) count++;
        }
    }
    TC: somewhere around O(n^2)  
    SC: O(1)



Same logic as above problems:
if at the current index -  my prefixXor is p, then I am essentially intereseted in knowing the #of times we have got p^k till now.
Because for all those instacnes, the subarray in between will have a xor k.

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        unordered_map<int,int> mp;  // (prefixXor, freq)
        
        int prefixXor = 0, count = 0; 
        for(int i = 0; i < n; i++){
            prefixXor = prefixXor ^ arr[i];
            // if(mp.count(prefixXor ^ k)){            // dont need this if() for count problems
            count += mp[prefixXor ^ k];
            // }
            if(prefixXor == k) count++;         // edge case -- can handle this in beginning if you initialise mp[0] = 1
            mp[prefixXor]++;
        }
        
        return count;
    }
};

TC: O(n) -- since we are using an unordered_map, the tc is O(n) in the average or best case. In the worst case, if there are a lot of collisions, then the tc becomes O(n^2)
If we use an ordered map, the tc becomes O(nlogn)
SC: O(n) -- since you are storing the prefix xor at every index 


Does the 2 pointer solution work here?  NO
    For this we need to understand if the prefix xor behaves in the similar way as the prefix sum does.
    NOTE: the array contains only positives and zeroes (no negatives)
    The prefix_sum will always follow a non decreasing order. it will either stay the same or it will increase.

    But what about prefix xor? 
    
        Why 2-pointer (sliding window) works for prefix sum (with only positives):

Prefix sum with only positive numbers is monotonic non-decreasing.
If the sum exceeds the target, moving the left pointer forward will always decrease the sum (or keep it the same), so you can "shrink" the window and still potentially find a valid subarray.
Why 2-pointer does not work for prefix xor:
Prefix xor is not monotonic. XOR does not have an order-preserving property like addition.
When you move the left pointer forward, the xor can increase, decrease, or change unpredictably, because:
xor = a ^ b ^ c ^ d
If you remove a, the new xor is b ^ c ^ d, which is not necessarily less than or related to the previous xor in any ordered way.
So, you cannot guarantee that moving the left pointer will get you closer to or further from the target xor.