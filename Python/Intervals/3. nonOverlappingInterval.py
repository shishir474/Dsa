
# Refer Neetcode Youtube for solution


class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        # sort the intervals based on the start value
        intervals.sort()
        res = 0
        prevEnd = intervals[0][1]
        for start,end in intervals[1:]:
            if start < prevEnd:
                #overlap
                res += 1
                prevEnd = min(prevEnd, end) # will keep the shorter end interval
            else:
                prevEnd = end
        
        return res


# TC: O(nlogn) sorting the intervals array
