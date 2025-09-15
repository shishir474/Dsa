The problem which we will be solving today is Insert Intervals. So what is the problem stating? 
It is stating that we will be given an intervals array. Each interval will have a start time and an end time.
We will also be given a new interval. We have to insert this new interval in the intervals array such that the intervals array remains sorted and non-overlapping. 
If there is any overlap, we will have to merge those intervals. 

intervals [[1,3],[6,9]], newInterval = [2,5]

output: [[1,5],[6,9]]

intervals [[1,2],[3,3],[6,7],[8,10],[12,16]], newInterval = [4,8]

Here we do see that the new interval [4,8] is overlapping with [6,7] and [8,10].
So we will have to merge these 3 intervals and the output will be [[1,2],[3,10],[12,16]].

Typically if I have to write them. So if we look at it, the left and right section is not overlapping. What is overlapping is the mid section.
I''ll take the non overlapping intervals as it is. For the overlapping intervals, I''ll merge them and take the merged interval.   
Also in the problem statement they have stated that the intervals array is sorted on the basis of start times and will have no overlapping intervals, and if you try to insert there might be overlap

[[1,2],[3,3],[5,7],[6,8],[8,10],[12,16]],
------------ ------------------ --------
not overlapping. overlapping     not overlapping 

So how do we solve this perticular problem? Im gonna start with the extreme naive solution and then we can analyse the TC and see if we can do better or not.

Brute force: 
The new interval si [6,7] and from the naked eye its pretty clear that it is overlapping with [5,7] and [8,10].
So there will be a segement on the left which will not overlap. There will be a segment on the right which will not overlap

I can break the problem into 3 segments, the left, the middle and the right segment.

For the intersecting segment: technically what Im doing is take the min of all the start times and max of all the end times.
Since the intervals array is sorted, anything to the right of the first interval in right segment -- will also be non overlapping

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> ans;
    int n = intervals.size();
    int i = 0;

    // left segment -- non overlapping
    while(i < n && intervals[i][1] < newInterval[0]){
        ans.push_back(intervals[i]);
        i++;
    }

    // middle segment -- overlapping
    while(i < n && intervals[i][0] <= newInterval[1]){
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    ans.push_back(newInterval);

    // right segment -- non overlapping
    while(i < n){
        ans.push_back(intervals[i]);
        i++;
    }

    return ans;
}

We have the left portion, we have the middle portion and we have the right portion.
Overall we are going through each and every element. So can I say that the TC is O(n) and the space complexity in order to store the ans - because the question is already stating you need to use an extra variable to store the ans is O(n) for the output array.

can we optimise this? No, becauase the question is already stating we need a separate array to return the ans. 
From the TC perspective: you cannot do better than O(n), because you need to traverse each and every element at least once.
So this will be the most optimal solution 