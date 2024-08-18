# 57. Insert Interval
# https://leetcode.com/problems/insert-interval/description/
# https://www.youtube.com/watch?v=A8NUOmlwOlM&list=PLot-Xpze53ldVwtstag2TL4HQhAnC8ATf&index=34

# Example 1:

# Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
# Output: [[1,5],[6,9]]
# Example 2:

# Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
# Output: [[1,2],[3,10],[12,16]]
# Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].


class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        
        res = []
        for i in range(len(intervals)):
            if newInterval[1] < intervals[i][0]:
                # non overlapping
                # if the newIntervals end < currentIntervals Start
                # we can apppend the newInterval and can also append all the intervals from the current pos to last and return ans
                res.append(newInterval)
                return res + intervals[i:]
            elif newInterval[0] > intervals[i][1]:
                # non overlapping
                # newIntervals start is > currentInterval end: I can definitely add currentInterval, but not newInterval. it could possibly overlap with some future intervals
                res.append(intervals[i])
            else:
                # overlapping
                # update the new interval
                newInterval = [min(newInterval[0], intervals[i][0]), max(newInterval[1], intervals[i][1])]
        
        
        res.append(newInterval) # if intervals array is empty, we will just add the newInterval and return ans
        return res
    
TC: O(n)


# Intuition:
# Nonoverlapping can happen in 2 conditions
# if the newIntervals end < currentIntervals Start
                # we can apppend the newInterval and can also append all the intervals from the current pos to last and return ans
# newIntervals start is > currentInterval end: I can definitely add currentInterval, but not newInterval. it could possibly overlap with some future intervals