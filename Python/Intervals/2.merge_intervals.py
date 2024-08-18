# 56. Merge Intervals

# Refer Neetcode Youtube for solution

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        # first sort the intervals based on their start time
        intervals.sort(key = lambda i: i[0]) # i in lambda represents the interval, & since we have to sort on the basis of starting value, hence i[0]
        
        output = [intervals[0]]
        
        for start,end in intervals[1:]:
            lastEnd = output[-1][1]
            if start <= lastEnd:
                #overlapping, update the end point, start will remain the same since the intervals are sorted in ascending order
                output[-1][1] = max(lastEnd, end)
            else: # no overlap
                output.append([start,end])

        
        return output
