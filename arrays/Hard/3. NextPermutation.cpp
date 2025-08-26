you will be given an arr of integers containing [1 to N]
you have to return the lexicographically next greater permutation

ex; [1,2,3]
n = 3, n! = 6 permuations 
[1,2,3]
[1,3,2]
[2,1,3]
[2,3,1]
[3,1,2]
[3,2,1]

Brute --> Better --> Optimal  

Brute Force solution:

1. Generate all the permuations in the sorted fashion
2. Do a linear search to find the idx at which the input lies
3. return the next idx permuation. If the idx == n-1, then you return the 0th index permuatation

How to generate permuations?  --> Using recursion

TC: 
// so there are n nos and there will be n! permuations. Every permuation is of N length. So at minimum we need atleast n * n! time.
// At minimum, If I go across to generate all the permuations, I will end up taking n! to generate all & each of those is of length n. 
// So  at minimum its going to be about O(n * n!)

SC: O(n * n!) there are n! permatations, each of length n, so we would need atleast n * n! space 

For n = 15, n! is somewhere around 1e12. Imagine the amount of time it will take to execute 1e12 instructions
This complexity is of extremely high order and thus we will not use this.

------------------------------------------------------------------------

Better Solution (this is actually not a better solution -- just uses an inbuilt function)

In CPP, we have a STL function 
next_permutation(A.begin(), A.end()) --> It will automatically change your list to next permuated array


------------------------------------------------------------------------

Optimal Solution :  This gives you the implementation for next_permuatation function

arr[]  = {2,1,5,4,3,0,0}

From the dictionary working -- one thing is pretty clear that the next permuation will have a longer prefix match 

"raj"
"rax"
"rbx"

"raj" appears before "rax" and "rax" appears before "rbx"
Now why does that happen?
In the first 2 string "ra" matches and since "j" < (lexicographially smaller than "x"), thus "raj" tends to appear before "rax"

arr[]  = {2,1,5,4,3,0,0}
prefix  = {2,1,5,4,3,0} you cannot arrange {0} anyway to create a next larger permutation
prefix = {2,1,5,4,3} you cannot arrange {0,0} anyway to create a next larger permutation
prefix = {2,1,5,4} you cannot arrange {3,0,0} anyway to create a next larger permutation
        {3,0,0} can be arrange to {0,3,0} or {0,0,3} all of which are smaller.
prefix = {2,1,5} you cannot arrange {4,3,0,0} anyway to create a next larger permutation
        {4,3,0,0} Anyway you arrange this you will always end up with a smaller permutation
prefix = {2,1} you cannot arrange {5,4,3,0,0} anyway to create a next larger permutation        
        {5,4,3,0,0} Anyway you arrange this you will always end up with a smaller permutation
prefix = {2} This {1,5,4,3,0,0} can be arranged in multiple ways to get the larger permutations. But the question is we need to find just next greater  
    {5,4,3,1,0,0}
    {4,5,3,1,0,0}
    Both of them are after {1,5,4,3,0,0}. But I have to find what is right after {1,5,4,3,0,0}?

I know one thing, we will have 1 prefix match {2} and then there can be a lot of arrangements that can be made {1,5,4,3,0,0}
But can you write {0,0,4,5,3,1} ? No because this will be smaller 

So my target will be to get someone greater than 1 (thats for sure). you want the next. you dont want the very very next 
{2,5} is way ahead 
we can take {2,4}, {2,3} ? 
Which one will you consider? {2,0} and {2,1} is out of question

Some one who is greater than 1 and is the smallest i.e 3

Why is {4,3,0,0} not possible? because we need someone greater than 4
Similarly {5,4,3,0,0} is not possible? because we need someone greater than 5 and there exists no such element
Why is {1,5,4,3,0,0} possible? Because we have elements greater than 1

Step1:
    We basically have to figure out what the break point is? Here its at 1 
    Breakpoint is a[i] < a[i+1]
   bp 
{2,1 | 5,4,3,0,0}

Instead of 1, I am looking for a value which is slightly greater than 1 on rhs and thats 3

Step2:
Find someone > 1 but the smallest one 

Step3
{2,3 | 5,4,1,0,0}

{2,3} > {2,1} Now how do you want to place the remaining elements? In the sorted order so that it is as small as possible 
since we have already acheived the greater value

{2,3 | 0,0,1,4,5}


Conclusion:
1. Try to get as long prefix match is possible 
    a[i] < a[i+1]. ==> i will be your break point
2. Now once you have found the breakpoint, try to put someone who is slightly greater than this guy.
3. Now once you have made the prefix greater, try to fill the remaining as small to get the right next permutation

int ind = -1;
for(int i = n-2; i>=0 ;i--){
    if(arr[i] < arr[i+1]){
        ind = i; break;
    }
}

if(ind == -1){ // no dip    
    reverse(arr.begin(), arr.end());
}

// find a value just greater than arr[ind]
// int mn = INT_MAX, mn_idx = -1;       // mn will store the element just greater than arr[ind] rhs
// NO need of mn because if you iterate from right the array is in non decreasing order. So the first value which you find will be your target elemetn
for(int j = n-1; j > ind ; j--){
    if(arr[j] > arr[ind]){          // this is the first guy just greater than arr[ind]
        swap(arr[ind], arr[j]); 
        break;
    }
}

// sort arr[ind+1 : ]  or you can reverse from arr[ind+1 : ] because the arr[ind+1 : ] was already sorted in the decreasing order, so if you reverse this you will get the required result
sort(arr.begin()+ind+1, arr.end()); 




class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        // step1: find the break point
        int ind = -1;
        for(int i = n-2; i>=0 ;i--){
            if(nums[i] < nums[i+1]){
                ind = i; break;
            }
        }   

        // edge case.  covers case: [3,2,1]
        if(ind == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        // step2: find the element just greater than the break point element
        for(int i = n-1; i > ind; i--){
            if(nums[i] > nums[ind]){
                // swap them so that your prefix now contains the next greater permutation prefix
                swap(nums[i], nums[ind]);
                break;
            }
        }

        // step3: sort the remaining or reverse them
        // reverse(arr.begin()+ind+1, arr.end());
        sort(nums.begin()+ind+1, nums.end());
        return;
        
    }
};

TC: O(n + n + n) = O(3*n)
SC: O(1) not using any extra space. Modifying the input array directly 
 