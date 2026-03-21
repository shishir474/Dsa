# https://leetcode.com/problems/compare-version-numbers/

# I need to basically compare the versions across both strings
# first step is to ofcourse, split both the strings on '.'
# this will give us 2 lists corresponding to v1 and v2
# now we compare v1[i] and v2[j]
# if v1[i] > v2[j]: return 1 indicating v1 > v2
# elif v1[i] < v2[j]: return -1 indicating v1 < v2
# else part means v1[i] is equivalent to v2[j], we move on to compare next values
# lenght of both lists need not be same. hence its necessary to ensure that v1[i] and v2[j] exists before we compare them
# if lets say v1[i] doesnt exist, p1 which basically means part 1 will be set as 0 
# and the same for v2[j] as well.
# NOTE: input_str = "001"
# print(int(input_str))     # 1

class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        l1 = version1.split('.')
        l2 = version2.split('.')
        i, j = 0,0  # for version1 and version2 lists

        # we keep on doing this until we have exhausted both the lists.
        # There could be a scenario where list1 exhausts before list2. 
        # In such case, for comparison purpose, we will take list1's part as 0
        while i < len(l1) or j < len(l2):
            # if part exists, take that else consider 0
            p1 = int(l1[i]) if i < len(l1) else 0
            p2 = int(l2[j]) if j < len(l2) else 0
            # compare both the parts
            if p1 > p2: return 1
            elif p1 < p2: return -1
            else:   # both parts are matching, move on to next one
                i+=1
                j+=1

        return 0

        # TC: O(n + m)
        # SC: O(1) though we are creating 2 lists l1 and l2 which will have a max length of 100, which is effectively a constant
