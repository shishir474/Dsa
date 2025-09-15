intervals= [[1,2], [2,3], [3, 4], [1,3]]

[1,2] & [2,3] is not considered overlapping -- in this problem. 

The question states that we need to find min no of intervals to be removed such that the rest of the intervals are non overlapping

[[1,2], [1,3], [2,3], [3,4]]

We need to determine, min no of intervals to be removed such that the rest of the intervals are non overlapping.
Min no of removals correspond to max no of non overlapping intervals -- which is what we did in n meetigns in one room.

There we were given the start and end times of n meetings and our task was to maximise the no of meetings that we can take.
In order to maximise the no of meetings- we prioritised the meetings that were ending faster. This ensures that we can take max no of meetings.
We were being greedy in choosing the meetings that we would want to take. 

Sorting on end times 
[[1,2], [2,3], [1,3], [3,4]]

ans here = n - max_meetings_that_can_be_taken

max_meetings_that_can_be_taken signifies the max no of non overlapping intervals that can be choosen from the given intervals array 


bool compare(vector<int> &v1, vector<int> &v2){
    return v1[1] < v2[1];
}
sort(intervals.begin(), intervals.end(), compare); // sort meetings on the basis of end times
int cnt = 1, lastFree = intervals[0][1];
for(int i =1; i < n; i++){
    if(intervals[i][0] >= lastFree){
        cnt++;
        lastFree = intervals[i][1];
    }
}
return n - cnt;

TC analysis:
we are sorting the array on end times -- O(nlogn)
Then we are linearly iterating over the intervals -- O(n)
Overall TC: O(nlogn) + O(n) = O(nlogn)
SC: O(1) -- not using any extra space just 1 variables which is practically constant   

Here we figure out the max no of non-overlapping intevals that we can choose  