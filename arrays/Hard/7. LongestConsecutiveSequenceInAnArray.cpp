Longest Consecutive Sequence. 

You will be given an array of integers and you need to determine the lenght of the longest consecutive sequence.

Brute Force:

arr[] = {100, 102, 100, 101, 101, 4, 3, 2, 3, 2, 1, 1, 1, 2}


You treat each element as the starting point of your seq.
for(int i = 0; i < n; i++){
    int x = arr[i];
    while(ls(arr,x+1)){ // ls - linear search
        x++;
    }
}

TC: O(n^2)
SC: O(1)








----------------------------------------------------------------------------

Better Solution 

If I sort the array arr
arr[] ={1,1,1,2,2,2,3,3,4,100,100,101,101,102}

I will basically keep track of the last smaller element 
Initially 
int last_smaller = INT_MIN, curr_cnt = 0;
int longest = 1  // (I know that the length of longest consc seq is atleast 1)

In order to include the current element, the last element must be curr_ele - 1 --> then we include it 
if the curr_ele == last_ele --> we dont do anything and move to next element
else we start off fresh, so last_smaller = curr_ele and curr_cnt = 1


Ill start with the 1st element 1.
Now inorder to be a part of the sequence , the last smaller element needs to be 0.
Its not and it is neither same, so we'll start off fresh 
update the last_smaller = 1, curr_cnt = 1

index: 1 (1) --> In order to be part of the seq, the last smaller element needs to be 0.
Its not, last_ele is same as curr ele so we continue 
stays same: last_smaller = 1, curr_cnt = 1

index: 2 (1) --> In order to be part of the seq, the last smaller element needs to be 0.
Its not, last_ele is same as curr ele so we continue 
update the last_smaller = 1, curr_cnt = 1

index: 3 (2)-->  In order to be part of the seq, the last smaller element needs to be 1.
The last smaller is indeed 1, so increase the curr_cnt = 2
update the last_smaller = 2, curr_cnt = 2
update the longest = 2

index: 4 (2)-->  In order to be part of the seq, the last smaller element needs to be 1.
Its not, last_ele is same as curr ele so we continue 
stays same: last_smaller = 2, curr_cnt = 2

index: 5 (2)-->  In order to be part of the seq, the last smaller element needs to be 1.
Its not, last_ele is same as curr ele so we continue 
stays same: last_smaller = 2, curr_cnt = 2

index: 6 (3)-->  In order to be part of the seq, the last smaller element needs to be 2.
The last smaller is indeed 2, so increase the curr_cnt = 3
update the last_smaller = 3, curr_cnt = 3
longest = 3

index: 9 (100)-->  In order to be part of the seq, the last smaller element needs to be 99.
Its not, last_ele is 4 and it is neither same as curr_ele
we start off fresh, so last_smaller = curr_ele and curr_cnt = 1


NOTE: You will always start fresh if the last element is not equal or not 1 lesser.

class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        int n = arr.size();
        // edge case
        if(n == 0) return 0;                // empty array --> return 0

        sort(arr.begin(), arr.end());       // sort the array so that consecutive elements come together

        int last_smaller = INT_MIN;         // keeping track of the last smaller element in the seq
        int longest = 1;                    // ans will be atleast 1
        int curr_cnt = 0;                   

        for(int i = 0; i< n;i++){
            // if arr[i] is part of the seq
            if(last_smaller == arr[i]-1){
                curr_cnt++;
                last_smaller = arr[i];
                longest = max(longest, curr_cnt);
            }
            else if(arr[i] == last_smaller){    // we simply dont do anything and move to the next index 
                continue;
            }
            else{   // start off fresh
                last_smaller = arr[i];
                curr_cnt = 1;
            }
        }

        return longest;
    }
};

TC: O(nlogn) + O(n)
SC: O(1) 


---------------------------------------------------------------------------

Optimal Solution

Put everything into a set. Now you need to find the starting points of the sequences.
An element is a starting point of a seq only iff ele-1 does not exist in the set.

arr[] = {100, 102, 00, 101, 101, 4, 3, 2, 3, 2, 1, 1, 1, 2}

s = {102, 4, 100, 1, 101, 3, 2}
This works becuase we know for sure that the first element will never have a prev one.
100 -> 101 -> 102
1 -> 2 -> 3 -> 4

Appantely this will be the 2 iteration which we will do. We avoided any extra iteration just by checking if the prev elemetn exists. If it does, then its not my starting point 
In the worst case you will cover all the all the elements in the sequence.
and there can be n distinct elements in worst case.


SC: O(N)    --> if all elements are unique u will endup storing all elemetns in the set.

*** State this in interview ****

For TC we know one thing, If we use unordered_set it will end up taking O(1) in average or best case.For the worst case when collision happens (thats a very very rare case), then the set will endup taking O(n)
Assuming the set takes O(1), you are iterating and inserting every element into set -> thats O(n)

and then we are iterating thru the set thats (7 iteratoins here) and then for construcitng seq 3+4 = 7 iterations.
In total we did 2*set.size() iterations i.e 2*N in the worst case.

Now it might look like N^2, but its not. Because we have made sure that we are only starting iterations from the potential starting points.

So O(n) for the set insertion under the assumption that the set take O(1) time 
and another O(2*n) for the set loop 
So in total O(N + 2N) = O(3*N)

class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        int n = arr.size();
        if(n == 0) return 0;        // edge case: empty array

        // single line code to create and populate an unordered_set with array elements
        unordered_set<int> s(arr.begin(), arr.end());

        int longest = 1;
        // why iterating over set works? Because arr can contain dupliates and we would know with certainity if arr[i] could be my starting point or not.
        // So no need to check for the same arr[i], because if its not then we will simply move to next element
        // instead of iterating over arr, I'll iterate over the set
        for(auto num: s){
            // check if num is a starting point 
            if(s.count(num-1) == 0){
                int val = num, curr_cnt = 0;
                while(s.count(val)){
                    curr_cnt++;
                    val = val + 1;
                    longest = max(longest, curr_cnt);
                }
            }
        }

        return longest;
    }
};

// Hack here is - if you iterate over array and check if arr[i] is a starting point, then that will give TLE.
// Because if it is a starting point, we will construct a seq using that and in future if I encouter the same value in array which I will for sure(because array might contain duplicates) we will again start constructing the seq.
// Instead iterate over the set. This way we ensure that we are only considering unique starting points and if a starting point is covered, we dont touch that again.