Better solution in the previous one using hashing will only work -- This is the best we can do 

TC: O(n) if using an unordered_map in the average or best case. In the worst this will become O(n^2) if the contstraints are such that there are a lot of collisions. So in that case O(1) factor changes to O(n) and thus the overall complexity becomes O(n^2)
If you use an ordered map, it will be O(n * logn). 

SC: O(n) -- in the worst case each index will have its individual prefix sum. Thereby O(n)


Follow up:
To find the no of subarrays with sum K
    -- hasing based solution works
    
// This hashing based solution works in all scenrios 
// if you have zeroes or negative elements, the prefix sum might repeat and that is why you need a hashmap to store the freq of the prefix sums   

        unordered_map<int,int> preSumMap; // (prefixSum,freq)
        preSumMap[0] = 1;
        int count = 0, prefixSum = 0;
        for(int i = 0; i < n; i++){
            prefixSum += arr[i];
            // if(preSumMap.count(prefixSum - K)){              // dont need this if() in case of counting the no of subarray. If the key does not exist mp[key] automatically returns 0.
            count += preSumMap[prefixSum - K];
            // }
            // if(prefixSum == K) count++;    // edge case         // for this you can initialise mp as mp[0] = 1 in the beginning
            preSumMap[prefixSum]++;       // increase the freq of the prefixSum
        }
        return count;




// This 2pointer solution basically relies on a greedy logic that as you move towards the right, the sum is bound to increase.
// (It might stay the same or will increase, but it will never decrease) --- and thus this works only if you have positives or (positives and zeroes)
// This is the most optimal solution 
    int sum = 0;
    int i = 0, j = 0;
    while(j < n){
        sum += arr[j];
        while(sum > K){
            sum -= arr[i];
            i++;
        }
        if(sum == k){
            count++;
        }
        j++;
    }

    return count;
