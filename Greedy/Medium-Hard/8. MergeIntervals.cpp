We are Given a collection of intervals, merge all overlapping intervals.

The first thing you need to ask the interviewer is, are the intervals sorted or not? Because it is no where stated in the problem statement that the intervals are sorted.
Assuming they are not sorted, the first thing that I''ll do is sort the intervals on the basis of start times. 

Sort all the given intervals on the basis of start times.
[[1,3],[2,6],[8,10],[9,9][15,18]]
Once I have sorted them, Im going to linearly iterate over the intervals.

We start with [1,3] and we checkout every other interval which can be merged in [1,3]. Here [2,6] is merging. SO Im gonna take one more data structure which will store the merged part 

[1,6]

After that we checkout to [2,6]. For this we see that it already lies in the previous merged interval. So we can skip this.

After that we checkout to [8,10]. We see that [8,10] doesnt collide with the previous merged interval. So you checkout amongst all the intervals on right -- with which is it merging?
It merges with [9,9]. So the merged interval will be [8,10]

[1,6], [8,10]

Now we checkout to [9,9]. It already lies in the previous merged interval. So we can skip this.

Now we checkout to [15,18]. It doesnt collide with the previous merged interval. So you checkout amongst all the intervals on right -- with which is it merging?
It doesnt merge with any interval. So the merged interval will be [15,18]   

[1,6], [8,10], [15,18]

TC: O(nlogn) + O(n^2)
for sorting the intervals and then for linearly iterating over the intervals and for each interval checking with all the other intervals on the right side -- whether it is merging or not. So overall TC is O(nlogn) + O(n^2)


----- 

Optimal solution 
[[1,3], [2,6], [8,10], [8,9], [9,11], [15,18], [2,4], [16,17]]

Sort all the given intervals on the basis of start times. Sorting assures that the merging intervals will be place consecutively.

[[1,3], [2,4], [2,6], [8,10], [8,9], [9,11], [15,18], [16,17]]
I''ll take a pair p = [1,3]

i = 0, collides with p, so merge it p = [1,3]
i = 1, collides with p, so merge it p = [1,4]
i = 2, collides with p, so merge it p = [1,6]
i = 3, doesnt collide with p, so push p to ans and make p = [8,10]
i = 4, collides with p, so merge it p = [8,10]
i = 5, collides with p, so merge it p = [8,11]
i = 6, doesnt collide with p, so push p to ans and make p = [15,18]
i = 7, collides with p, so merge it p = [15,18]
At the end of the loop, push the last pair p to ans

TC: O(nlogn) + O(n)
SC: O(n) 


vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> mergedIntervals;
    int n = intervals.size();
    if(n == 0) {                // edge case 
        return mergedIntervals;
    }
    
    sort(intervals.begin(), intervals.end());

    vector<int> tempInterval = intervals[0];
    for(int i = 1; i < n; i++){
        if(intervals[i][0] <= tempInterval[1]){   // collides
            tempInterval[1] = max(tempInterval[1], intervals[i][1]);
        } else {                        // doesnt collide
            mergedIntervals.push_back(tempInterval);
            tempInterval = intervals[i];
        }
    }
    mergedIntervals.push_back(tempInterval);   // push the last pair

    return mergedIntervals;
}

if its not merging: we simply put the resultant of the consecutive intervals into the mergedIntervals and after that we reassign the value of the interval into temp interval.
Once we have completed the iteration of all intervals, we can simply push back the last resultatnt interval into the mergedIntervals and return the ans.