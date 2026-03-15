You will be given an arr of integers. Goal is to find the element that appears more than n/2 times.
arr = {2,2,3,3,1,2,2}
7/2 = 3
freq of 2  = 4  > 7/2
Hence 2 is the majority algorithm

Brute Force:
1. Traverse the array and count the frequency of each element.
2. If any element''s frequency is greater than n/2, return that element.

for(int i = 0; i < n; i++){
    count = 0;
    for(int j = 0; j < n; j++)
    {
        if(arr[i] == arr[j])
            count++;
    }
    if(count > n/2)
        return arr[i];
}

TC: O(n^2)
SC: O(1)


NOTE: Here you can have at max 1 element whose freq > N/2. At minimum you can have 0 eleements
--------------------------------------------------------------------

Better Solution :

Hashing - Create a hashmap to store the freq of each element

// map<int,int> mp;
unordered_map<int,int> mp;
// NlogN      -- The first loop is running for O(N) and we are inserting elements in the map which takes O(logN) time
for(int i=0;i<arr.size(); i++){
    mp[arr[i]]++;
}
for(auto it: mp){
    if(it.second > n/2)
        return it.first;
}
return -1;

TC: O(NlogN) + O(N) = O(NlogN)
SC: O(N) for hashmap -- if all the elements are distinct 

--------------------------------------------------------------------

Here's how the time complexity differs between map<int,int> and unordered_map<int,int> in C++ for your code snippet:

1. Using unordered_map<int,int>

unordered_map<int,int> mp;
for(int i=0;i<arr.size(); i++){
    mp[arr[i]]++;
}
Underlying Data Structure: Hash table

Average Case Per Insertion or Lookup: O(1)

Worst Case Per Insertion or Lookup: O(n) (if many keys hash to the same bucket, but this is rare)

Total Time Complexity:

Average: O(n) for n elements

Worst: O(n^2) (very unlikely in practice)

2. Using map<int,int>

map<int,int> mp;
for(int i=0;i<arr.size(); i++){
    mp[arr[i]]++;
}
Underlying Data Structure: Red-Black Tree (Balanced BST)

Time Complexity Per Insertion or Lookup: O(log n)

Total Time Complexity:

O(n log n) for n elements

Summary Table
Container	Avg per-insert/lookup	Total for n elements	Structure
unordered_map	O(1)	               O(n)             	Hash table
map	            O(log n)	           O(n log n)	        Balanced BST (RB tree)

Conclusion
unordered_map is generally much faster for insertion and lookup than map, delivering O(1) average time compared to O(log n) with map.

Use unordered_map for most cases where order doesn’t matter and you want faster performance.

Use map if you need sorted keys or guaranteed worst-case times.

--------------------------------------------------------------------

Moore Voting Algorithm (Optimal Solution):

Do a dry run of this algorithm and during the dry run try to explain the intuition / thoughtprocess of the algorithn.

2 variables element & count. Initially the count = 0 and the element is not initialised 
Whenever the count is 0, we hypothetically take the element as our majority element 

count = 0 
element = 7

arr[] =   {7,7,5,7,5,1,5,7,5,5,7,7,5,5,5,5}
count = 0  1,2,1,2,1,0,1,0,1,2,1,0,1,2,3,4
element = 7

Initally since count was 0, I hypothetically considered 7 as my majority element.
Now whenever I get 7, count++, else count--;

7,7,5,7,5,1
Here the count became 0 again 
This was because we got 3+ and 3- which effectively made the count 0. Can 7 be considered as my majority element?
No because the definition clearly states that the freq of the element > N/2 
Here the freq is 6/2 = 3 which is equal to N/2. Thereby 7 cannot be my majority element.

count = 1
element = 5

5,7
Again 5 cannot be my majority element because the freq is 1 which is equal to N/2.

count = 1
element = 5 

5,5,7,7
Again 5 cannot be my majority element because the freq is 2 which is equal to N/2.

count = 4
element = 5

We have exhausted the arr. Now if there exists a majority element, it must be the one stored in 'element'.
We need to verify if it is indeed the majority element by counting its frequency in the array.

Idea here is we basically choose an element hypothetically as the majority element and then verify if it meets the criteria.
As an when we encounter that element again, we increment the count. If we encounter a different element, we decrement the count. If the count reaches zero, we choose the new element as the candidate.
At the end, we need to verify if the candidate is indeed the majority element by counting its frequency in the array.


Why verifying for the majority element is crucial?
arr[] =   {7,7,5,7,5,1,5,7,5,5,7,7,1,1,1,1} N = 16
element = 1
freq = 4

So according to our assumption 1 is the majority element. But its freq is 4 which is not > N/2.
Thus its crucial to verify if the element is indeed the majority element.
So here we dont have any majority element.

NOTE: If the problem states that there will always be a majority element, then we can skip the verification step.


class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int n = arr.size();
        int count = 0, element;
        for(int i=0; i<n; i++){
            if(count == 0){
                count = 1; element = arr[i];
            }
            else if(arr[i] == element) count++;
            else count--;   
        }

        // verifying if the element is indeed the majority element
        count = 0;
        for(int i=0; i<n; i++){
            if(arr[i] == element) count++;
        }
        if(count > n/2) return element;
        return -1;
    }
};

NOTE: I will only have 1 majority element ( > N/2 times) in my arr. There cannot exists 2 majority elements.
// TC: O(N)
// SC: O(1)