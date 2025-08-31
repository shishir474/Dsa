 arr[] = {3, 3, 3, 1 , 2, 1, 1, 2, 3, 3, 4}

What is the max no of fruits that you can pick?

You are at max allowed to pick 2 types of fruits and this fruit picking should be contigouus 


can we trim down the question to finding the max length of the subarray with atmost 2 types of fruits 


Brute force sol --

The question is about subarrays-- and thus the extreme naive sol that I can think of is to generate all subarrays 

for(int i = 0; i < N; i++){
    unordered_set<int> s;
    for(int j = i; j < N; j++){
        s.insert(arr[j]);
        if(s.size() > 2) break;
        ans = max(ans, j - i + 1);
    }
}

TC: O(n^2) -- not exactly n^2, somewhere around n^2. 
the outer loop runs n times, whereas the inner loop does not always run for n times for each i. Hence Im saying that the tc willl be somewhere around n^2, and not exactly n^2.

s.insert() is defitely logarithmic, but here the set size at max will be 2 & log2 is as good as constant. Hence we can ignore thhe log factor of set insert here 


SC: O(2) --which is as good as constant

---------------------------------------------------------------------

better sol -- 

we have to optimsise n^2 -- somewhere around n. and the problem involves subarrays -- so the first thing which comes to my mind is 2ptrs and sliding window 


unordered_map<int,int> mp;  // num, freq

int l = 0, r = 0;
while(r < n){
    mp[arr[j]]++;       // keep on expanding until you have <= 2 fruits -- ie in our case that will be mp size
    while(mp.size() > 2){
        // we have 3 or more fruits
        mp[arr[l]]--;
        if(mp[arr[l]] == 0) mp.erase(arr[l]);
        l++;
    }
    ans = max(ans, j - i + 1);
    j++;
}

return ans;

TC: O(2 * n)
Whats the driving factor for the time complexity here? definitely the outer loop where right ptr moves forward from start to end . Hence O(n) for sure.
Now in the inner loop we start trimming down when the mp.size() which represents the no of unique elements in the mp
exceeds 2. In the worst case, overall the inner loop left ptr moves n steps, but this is overall for the outer loop. 

For the inner while loop, you will have to keep in mind, that this while loop is not running till n always. 
Overall in the worst scenario, l will move n steps 

worst possible case -- l needs to move the entire array until we hvae 2 distinct elements
l l l l l 
3 3 3 3 1 2 
          r  

Thereby the tc is O(n) + O(n) = O(2 * n)


SC: O(1) -- mp.size at max will be 3 hence the space complexity is as good as constant

Size of the map is extremely small. Thereby the sc is O(1)



----------------------------------------------------------------------------------------------------------

Best solution -- O(n) solution   
    ------[have used the same concept of MAX CONSECUTIVE ONES 3]

We need to optimse O(2 * n) into O(n)

But for that we need to first understand what was taking O(2 * n) ? 
It was because of the inner while loop. Whenever the mp.size() exceeded 2, we used to move left ptr l 1 step until the mp.size() became <= 2
But here we will just move 1 step.

WHy this works?
because we are not allowing the algorithm to update our ans if mp.size() > k. We continue to move right, but the ans only updates if mp.size() <= 2.

and if mp.size() > 2 then we trim 1 char from the left. This could result in 2 ways. either the mp size becomes <= 2 and we could update ans or 
there are still 3 distinct chars in the window and the ans wont be updated. 


Unlike the prev sol where we used to move l to the point until it exhausts all the occurnece / I have 2 distinct elements or what ever condition it is 
we just move l by one step. Whatever we used to do inside the while loop, that same stuff we will now do just once inside if block.
if moving one step helps, then we update our ans and if it doesnt then anyways we wont update our ans



l
3 3 3 1 2 1 1 2 3 3 4
      r  
maxLen = 4

l
3 3 3 1 2 1 1 2 3 3 4
        r  
3 - > 3, 1 - > 1 2 -> 1 although the length of subarray l..r is 5, we wont update ans since we have 3 distinct elements

moving l by 1 step -- but this wont reduce the no of distinct elements 

  l
3 3 3 1 2 1 1 2 3 3 4
        r  
3 - > 2, 1 - > 1, 2 -> 1 -- ans still not updated, because of 3 distinct elements 

  l
3 3 3 1 2 1 1 2 3 3 4
          r 
3 - > 2, 1 - > 2, 2 -> 1 -- ans still not updated, because of 3 distinct elements 

move l by 1 step 
    l
3 3 3 1 2 1 1 2 3 3 4
          r 
3 - > 1, 1 - > 2, 2 -> 1 -- ans still not updated, because of 3 distinct elements 

    l
3 3 3 1 2 1 1 2 3 3 4
            r 
3 - > 1, 1 - > 3, 2 -> 1 -- ans still not updated, because of 3 distinct elements 

move l by 1 step 
      l
3 3 3 1 2 1 1 2 3 3 4
            r 
1 - > 3, 2 -> 1 -- len subarray l..r  = 4, maxLen wont be updated since it is already 4

      l
3 3 3 1 2 1 1 2 3 3 4
              r 

1 - > 3, 2 -> 2 -- len subarray l..r  = 5, maxLen = 5

      l
3 3 3 1 2 1 1 2 3 3 4
                r 

1 - > 3, 2 -> 2 , 3 -> 1-- ans wont be updated 

l moves by 1 step 

        l
3 3 3 1 2 1 1 2 3 3 4
                r 
1 - > 2, 2 -> 2 , 3 -> 1-- ans wont be updated 
        l
3 3 3 1 2 1 1 2 3 3 4
                  r 
1 - > 2, 2 -> 2 , 3 -> 2-- ans wont be updated 

l moves by 1 step 

          l
3 3 3 1 2 1 1 2 3 3 4
                  r 
1 - > 2, 2 -> 1 , 3 -> 2-- ans wont be updated 



int maxLen = 0;
int l = 0, r = 0;

map<int,int> mp;
while(r < n){
    mp[arr[r]]++;

    // Instead of the  while loop, we just move l by 1 step. 
    if(mp.size() > k){
        // Ill shrink 1 step
        mp[arr[l]]--;
        if(mp[arr[l]] == 0) mp.erase(arr[l]);
        l++;
    }
    if(mp.size() <= k){
        maxLen = max(maxLen, r - l + 1);
    }
    r++;
}

return maxLen



