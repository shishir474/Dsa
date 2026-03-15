class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        n = len(intervals)
        
        intervals.sort()

        res = []

        i = 0
        while i < n:
            start,end = intervals[i][0],intervals[i][1]
            j = i+1
            while j < n:
                if intervals[j][0] <= end:      # overlap
                    end = max(end, intervals[j][1])
                else:
                    break
                j+=1
            
            res.append([start,end])
            
            i = j

        return res

    # TC: O(NLOGN) + O(N)
    # although it looks like quadratic because of 2 nested loops it isn't. i simply moves to j so its linear
    # SC: O(1) no extra space other than the res array