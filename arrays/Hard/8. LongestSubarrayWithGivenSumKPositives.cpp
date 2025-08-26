Longest Subarray of Size K [Positives]

arr[] = {1,2,3,1,1,1,1,4,2,3}


Brute -- Better -- Optimal 

Find me the length of the longest subarray whose sum is K.
Subarray -- contigous portion of your arr 


Brute Force:
I am gonna generate all the subarrays and calculate their sum 

for(int i = 0; i < n; i++){
    for(int j = i; j < n; j++){
        // arr[i .. j]
        for(int k = i; k <= j; k++)
            sum += arr[k];
         
        if(sum == K) len = max(len, j - i + 1);
    }
}
return len;

TC: 3 loops -- Somewhere around O(n^3) -- not exactly n^3, because the subarray is diminishing
SC: O(1) -- not using any extra space


Optimised Brute Force 
    calculate the subarray sum in the 2nd loop itself 

for(int i = 0; i < n; i++){
    int sum = 0;
    for(int j = i; j < n; j++){
        sum += arr[j];
        // once sum == K (found a subarray, compare its length and break because all the elements are +ve so you will never get the sum as K again)
        if(sum == K){
            len = max(len, j - i + 1);
            break;
        }
    }
}
return len;

TC: 2 loops -- Somewhere around O(n^2) -- not exactly n^2, because of the break condition (we will not traverse the 2nd loop entirely)
SC: O(1) -- not using any extra space



------------------------------------------------------------------------
Better solution:

Uses Hashing -- kinda doing reverse engineering (if the current prefix sum is p and there exists a prefix with sum p - x, then the sum of the subarray in between these 2 prefixes is k)

I will store the prefix_sum and the corresponding_index in map 
since all elements are +ve, prefix sum wont ever repeat (we dont have 0 or -ve element, so prefix sum will always increase in the positive direction)
If at a certain index, lets say my prefix sum is P, I will check into the map if we have encoutered any prefix with sum P - K 
If there exists a prefix with sum P - K, then the subarray between these 2 prefixes has sum K [j+1, i] = len will be (i - j)

unordered_map<int,int> preSumMap;       // prefix_sum, idx
preSumMap[0] = -1;      // initialised mp
int ans = 0, prefix_sum = 0;
for(int i = 0; i < n; i++){
    prefix_sum += arr[i];
    if(prefix_sum == K){
        ans = max(ans, i + 1);
    }
    if(preSumMap.count(prefix_sum - K)){
        int len = i - preSumMap[prefix_sum - K];
        ans = max(ans, len);
    }
    preSumMap[prefix_sum] = i;
}

return ans;

// TC: O(n)
// SC: O(n) --> for the hashmap 


Edge case for 0s and negatives 

This solution wont work if you have zeroes
arr = [2,0,0,3] K = 3
                    map
index 0: ps = 2     (2,0). -- -1 does not exist
index1: ps: 2       (2,1) -- -1 does not exist 
index2: ps = 2      (2,2) -- -1 does not exist
index3: ps = 5      (5-3) = 2 does exist and based on the map it gives index 2
So if your curr prefix sum is x and you are looking for x - k, you should look for the prefix as left as possible in order to generate longest subarray of sum K 
So that means if your prefix sum repeats, you dont update the map 
here ans should be [0,0,3], but based on the current solution where we keep on updating the prefixSumMap, we are intereseted in pre sum of 2 and that is at 0,1,2(latest in the mp)
whereas if we dont update the map and just record the first occurence of the prefix sum this will give us the longest subarray with sum K

This slight change makes the code work in both scenarios where we have zeroes and negatives (because the presence of 0s and -ve's in the array means, the prefix sum can repeat and if it is going to repeat we would want to store just the first index where we got that sum.
Updating the prefix sum indexes will not result in the largest subarray of size K )

// Below code works when 0s or negatives are present in the array.
// In case of just positives, we dont need the last if(storing first occurence of prefix_sum) because the prefix_sum wont repeat (all element > 0)
// So the prefix sum will keep on increasing 

unordered_map<int,int> preSumMap;       // prefix_sum, idx
// preSumMap[0] = -1;      // initialised mp -- dont need this if you explicitly checking prefix_sum == K condition
int ans = 0, prefix_sum = 0;
for(int i = 0; i < n; i++){
    prefix_sum += arr[i];
    if(prefix_sum == K){
        ans = max(ans, i + 1);
    }
    if(preSumMap.count(prefix_sum - K)){
        int len = i - preSumMap[prefix_sum - K];
        ans = max(ans, len);
    }
    if(preSumMap.count(prefix_sum) == 0)        
        preSumMap[prefix_sum] = i;
}
// if the current prefix has sum X and we are looking for prefix X - K, then we are interested in that prefix which is as left as possible because this will guarantee us to give the longest subarray of size K
// and the way acheive this is by storing only the first occurence of the prefix sum 

return ans;


TC: I am iterating over the array and I am inserting the elements into the hashmap
If I use an ordered_map in c++, tc is going be O(nlogn) since all the keys are stored in the sorted order. But If I use an unordered_map in the average or best case, tc will be O(n * 1 i.e O(n), but 
if the constraints are in such a way that it ends up having a lot of collisions then this O(1) in unordered_map ends up becoming O(n). Thus making the overall complexity to O(n^2) in the worst case.
I can use unordered_map if I dont have any collisions. I will end up with O(N * 1) which is O(N) and I will have N logarightmic N if I am using ordered map. It will not have any collisions 

SC: We are using a hashmap where we are storing every prefix sum. So in the worst case every index will have its individual prefix sum. Thereby O(N) 

This is the optimal solution for positives and negatives 
------------------------------------------------------------------------

Optimal Solution:

If the array contains just positives and zeros, I''ll  turn to the most optimal solution that will be using 2 pointers and a greedy appraoch  

Uses 2 pointer 

The thoughprocess is something like this. Initially we are at 0th index, then we keep expanding on the right 
The moment you move right in the array, the summatoin is bound to increase and there will be a point where it will go beyond K. When does that happen I''ll try to trim it down from the front (shrink) 

int sum = 0, len = 0;
int i = 0, j = 0;
while(j < n){
    sum += arr[j];
    while(sum > k){
        sum -= arr[i];
        i++;
    }
    if(sum == K)    
        len = max(len, j - i + 1);
    j++;
}

return len;

TC: O(n)
    From the naked eye it might look like O(n^2) because of the 2 while loops, but its not. Its actually O(2*n) -- because you are always moving forward and in the worst case you will travererse each element twice. Hence O(2N) which is O(N)
    right pointer j always moves right (0 to n)
    But is the inner while loop always running O(n)? If yes, then it would have been a O(n^2). But in reality its not.
    Overall during all iterations, the inner loop will run at max n times 

SC: O(1) -- not using any extra space other than 2 variables i and j which is effectively constant i.e O(1)



NOTE: If the array contains positives and negatives, better solution (hashing one) is the most optimal that we can do.
But if the array contains only positives or positives and zeroes --> 2 pointers solution would be the most optimal one.

The reason 2 pointers does not work with negatives is because this is a greedy solution which means if you move right the sum will never decrease (it might stay same or increase , but will never decrease) ie.e non decreasing 
After a certain point when then sum > K you basically trim down the elements from the front 
But if you have negative elements, non decreasing nature of sum is not guranteed. The sum might decrease here and hence the 2pointers solution does not work for -ve elements 