Merge Overlapping sub interval s

input = [(1,3), (2,6), (8,9), (9,11), (8,10), (2,4), (15,18), (16,17)]

o/p = 

1--------------3                        8------9                    15---------18
        2------------------6                   9---------11             16---17
        2-----------4                   8-----------10
    
o/p = [(1-6), (8,11), (15,18)]
This is the shortest list of merged intervals. Why dont we consider an interval of (1-18), because then there are some points which are not touched.


Brute force 

one thing which I see here is in order to club them together, I would need to bring the overlapping intervals close to each other
Lets sort the array -- since we sort on 1st element (if the first elements are same, then it automatically sorts on 2nd element)
        i
we get [(1,3), (2,4), (2,6), (8,9), (8,10), (9,11), (15,18), (16,17)]

Initially you will be at (1,3)
Just hypothetically say this is my possible interval 
Then I'll check next intervals 
is (2,4) overlapping? yes becuase 2<=3 
So this (1,3) will expand in order to accumulate (2,4)
Next (2,6) Is this overlapping with (1,4)? Yes 2<=4
So (1,4) will expand to become (1,6) so that it can accumulate (2,6)
is (8,9) overlapping? No its not. At this moment I have found my first merged interval (1,6). Push this into res vector.
Now jump i to j. 
At this point I'm hypothetically sayint that (8,9) is my interval.
lets try to merge as much as we can by checking the next intervals. so j = i+1
is (9,11) overlapping with (8,10)? Yes, because 9 <= 10
so you expand (8,10) to (8,11) to accomodate (9,11)
Now is (15,18) overlapping with (8,11)? No its not. So I have one interval (8,11). Push this into res 
Update i to j 
At this point I'm saying (15,18) is hypothetically my next interval
j = i+1 
is (16,17) overlapping with (15,18)? Yes, sicne 16 <= 18



(1,6)

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        vector<vector<int>> res;
        int n = arr.size();

        sort(arr.begin(), arr.end()); 

        int i, j;
        for(i = 0; i < n; i = j){
            int start = arr[i][0];          // start will never update (bcoz the arr is sorted in increasing order )
            int end = arr[i][1];
            for(j = i + 1; j < n; j++){
                if(arr[j][0] <= end){    // if overlapping--> extend the ith interval to accumulate the jth interval
                    end = max(end, arr[j][1]);
                }
                else break;                     // if not overlapping break
            }
            res.push_back({start,end});                   // you will have one interval 
        }

        return res;
    }
};

// TC: O(nlogn) + O(n)
// SC: O(n) -- if all the intervals are non overlapping so you will end up storing everyone.

Same solution -- just written in a different way 
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        for(int i = 0;i < n; i++){  
            // I'll insert if it is the first element or if its not overlapping
            if(ans.empty() || arr[i][0] > ans.back()[1]){
                ans.push_back(arr[i]);
            }
            else{ // else it is overlapping -- expand the ans.back() interval to accomodate arr[i]
                ans.back()[1] = max(ans.back()[1], arr[i][1]);
            }
        }

        return ans;
    }
}