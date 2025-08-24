// Till now we have covered lis using recursion, memoisation, tabaulation, space oiptimisation and algorithmic approach.
The best we could do till now was time complexity of O(n^2) and space complexoity of O(n)
Constraint is N <= 1e5


Now we'll see how to implement LIS using binary search. 

arr = {1,7,8,4,5,6,-1,9}
Lets try to go across every element and try to form subsequences.
Initally when I am at 1, {1}
Now lets move to 7. Do I neeed to form a new subsequence using 7 or can I attach it  over here
{1, 7}
you can attach 8 {1,7,8}
You cannot attach 4 because the subsequence must be increasing.
but you can attach it to 1 
{1,7,8} & {1,4}
The moment I go to 5, can I attach it to 1,7,8? No 
Can I attach it to 1,4? Yes {1,4,5}
{1,7,8} & {1,4,5}
6 can I attach it to 1,7,8? No
can I attach it to 1,4,5? Yes {1,4,5,6}
{1,7,8} & {1,4,5,6}
-1 where can I attach it? Nowhere. So I will start a new subsequence
{1,7,8} & {1,4,5,6} & {-1}
Now when I go to 9, you can attach it to all {1,7,8,9}, {1,4,5,6,9}, {-1,9}

Now will you go across and generate all these subsequences? No, because its gonna be very hectic. If you make new subsequences at every junction, its gonna take a lot of space  

But this is the intution behind the binary search approach. I dont need the print lis. I just need to know the length of the longest increasing subsequence.

{1,7,8}
Now when we reached 4, can I rewrite 4 over here {1,4,8}
Yes, we can do this. Because we are just concerned about the length 

Instead of making {1,4}, since we are not concerned about the lis. We only want to know the length.
we'll say where can 4 fit in the existing subsequence?
Remember this does not mean that {1,4,8} is a subsequence. I''m just making sure that instead of storing {1,4} separately. I save 1,4 right over there to save space 
I know 8 is there and the reason it is there is because perviously 7 was there

At 5 I can either create 1,4,5  


The length of the final array will be the your length of the list. This is definitely not the actual lis, but this appraoch allows us to find the length.
// If you want to determine the actual lis, you will need to via the dp[] array algorithmic technique 

Why binary search?
Since you the arr is sorted, in order to insert the nums[i] right at the right position, you can use binary search to find the position where it can be inserted

int f(vector<int>& nums){
    vector<int> temp;
    for(int i = 0; i< nums.size(); i++){
        auto it = lower_bound(temp.begin(), temp.end(), nums[i]);
        if(it == temp.end()){ 
            temp.push_back(nums[i]);
        }
        else{
            *it = nums[i];      // replace the current element. In order to save space instead of createing a new subs we'll just replace the current element
            // remember this arr does not represent the actual lis. It just gives you the length
        }
    }

    return arr.size();
}


// why lower_bound ?
// because we need to find the nums[i] or first element > nums[i]
We find nums[i] because --> consider case [8,8] ans will 1

Can you regenerate the lis from binary search? The answer is No because you will need to store all this subsequences separately in order to reconstruct the actual longest increasing subsequence.
We optimised space, instead of carrying different subsequences, we reused that space and created it. 

TC: O(n * logn) -- logn for binary search 
SC: O(n) for temp[]

Remember that we are not generating the lis. We are just finding the length of the lis.

Why arent we using the input array instead of temp? 
This is not a recommended approach in interviews, we generally dont tamper with the input.