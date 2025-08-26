Majority Element [ > N/3 times]

You will be given an arr of integers. Goal is to find all the elements that appears more than n/3 times.
arr[] = {1,1,1,3,3,2,2,2}
N = 8
N/3 = 8/3 = 2 
ans = {1,2} -- both 1 and 2 appears more than 2 times.

How many integers can be in the answer?
At max 2 integers can be there in the answer.
Why?
Lets assume there are 3 integers a,b,c which appears more than N/3 times.
So freq(a) + freq(b) + freq(c) > N/3 + N/ 3 + N/3 = N
This is a contradiction because the total freq of all elements cannot be more than N.

for ex:Here n = 8, so n/3 = 2
the minimal freq that we need to have such that it is greater than n/3 is 3
So if we have 2 elements whose freq is 3 -- total becomes 6
and if you have 1 more than the total becomes 9 which exceeds the overall count of elements 

So at max you can only have 2 eleements whose freq > N/3. At minimum we can have 0 integers.


Brute force:

You chech the freq of every element and store those whose freq ? N/3

vector<int> res;
for(int i = 0; i < n; i++){
    if(res.size() == 0  ||  arr[i] != res[0]){
        // if the res list is empty or arr[i] != res[0] (arr[i] is already in the list, so move to next element)
        // determine the count/freq of arr[i] & if its greater than n/3, append that in the list
        // since I know, the res list will at max contain 2 elements. If the res.size() == 2 -- break out
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(arr[j] == arr[i]) cnt++;
        } 
        if(cnt > n/3) res.push_back(arr[i]);
    }
    if(res.size() == 2) break;
}

TC: O(n^2) -- its going to be near about O(n^2)
SC: O(1) -- are we using any extra space? yes we are. We are taking a list but thats hardly going to store 2 elements .
So O(2) space is as good as the constant.

--------------------------------------------------------------------

Better Solution 

Hashing : Once you iterate the entire array, your hashmap will contain all the unique elements and its corresponding frequency.
Now if I go thru the hashmap, I can easily check whose freq > N/3


unordered_map<int,int> mp;      // no, cnt 
// NlogN      -- The first loop is running for O(N) and we are inserting elements in the map which takes O(logN) time
for(int i=0;i<arr.size(); i++){
    mp[arr[i]]++;
}
for(auto it: mp){
    if(it.second > n/2)
        res.push_back(arr[i]);
}
return -1;

TC: O(NlogN) + O(N) = O(NlogN)
SC: O(N) for hashmap -- if all the elements are distinct 

First we iterated over the array and then we iterated over the hashmap. But do we need 2 iterations?
No, I can do it in a single iteration as well.
So while iterating if the freq of the element > N/3 and if the list is empty or if the element != list[0], I append that element in the list 

unordered_map<int,int> mp;      // no, cnt 
vector<int> res;

for(int i=0;i<arr.size(); i++){
    mp[arr[i]]++;
    if(mp[arr[i]] > n/3){
        if(res.size() == 0  ||   res[0] != arr[i]){ // 2nd condition to avoid adding the same element again
            res.push_back(arr[i]);
        }
    }
}

If you are using a ordered map, the insertion takes O(logn) per key. So in total O(nlogn) for n elements
If you use an unordered_map, the insertion takes O(1) time on average per key. So that will be O(n) for n elements 
But remember the unordered_map takes O(N) time in the worst case per key for insertion (very rare scenario)

// single iteration
TC: O(N)
SC: O(N) for hashmap -- if all the elements are unique, hashmap will end up storing all the elments in the map 

--------------------------------------------------------------------

Optimal Solution 

arr = [2, 1, 1, 3, 1, 4, 5, 6]
cnt1 = 0        cnt2 = 0
el1 =           ele2 = 

since cnt1 = 0 ele1 = 2, cnt1 = 1
since cnt2 = 0 ele2 = 1, cnt2 = 1
since ele2 == arr[2], cnt2 = 2
since arr[i] != ele1 and arr[i] != ele2: cnt1 = 0, cnt2 = 1, ele1 = 2, ele2 = 1
at index = 4, cnt1 = 0, so I will initalise ele1 to 1 which is incorrect because ele2 is already holding 1.
So you should not initialse ele1 to 1 
since ele2 is equal to arr[4] cnt2 = 2



We'll replicate the same logic that we applied for > N/2 elements 

class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        int n = arr.size();
        int cnt1 = 0, cnt2 = 0;      // counters
        int ele1, ele2;             // elements
        // el1 & el2 are unique elements that appear > n/3 times

        for(int i = 0; i < n; i++){     
            if(cnt1 == 0 && arr[i] != ele2){ // edge case; assigning arr[i] to ele1, so it should not be equal to ele2
                cnt1 = 1; ele1 = arr[i];
            }
            else if(cnt2 == 0 && arr[i] != ele1){ // edge case; simlarly, since we are assinging arr[i] to ele2, it should not be equal to ele1
                cnt2 = 1; ele2 = arr[i];
            }
            else if(ele1 == arr[i]){
                cnt1++;
            }
            else if(ele2 == arr[i]){
                cnt2++;
            }
            else{   // arr[i] is neither eqaul to ele1 nor to ele2
                cnt1--; cnt2--;
            }
        }


        vector<int> res;

        // you will have something stored in the ele1 and ele2, but you cannot say with certainity if those are your majority element.
        // hence we need to manually verify
        // manually check if ele1 and ele2 are majority elements > N/3 frequency
        cnt1 = cnt2 = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] == ele1) cnt1++;
            else if(arr[i] == ele2) cnt2++;
        }

        if(cnt1 > n/3) res.push_back(ele1);
        if(cnt2 > n/3) res.push_back(ele2);

        // NOTE: el1 and el2 are unique elements whose freq > n/3

        return res;
    }
};

TC: O(n + n) = O(n)
SC: O(1)