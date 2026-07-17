from bisect import bisect_left, bisect_right

sorted_list = [1, 2, 4, 4, 4, 5, 7, 9]
target = 4
target_not_present = 6
target_larger = 10



# Find the lower bound of 4
lower_bound_4 = bisect_left(sorted_list, target)
print(f"The lower bound of {target} is at index: {lower_bound_4}")
# Output: The lower bound of 4 is at index: 2 (index of the first '4')

# Find the lower bound of a value not in the list
lower_bound_6 = bisect_left(sorted_list, target_not_present)
print(f"The lower bound of {target_not_present} is at index: {lower_bound_6}")
# Output: The lower bound of 6 is at index: 6 (index of '7', the first value >= 6)

# Find the lower bound of a value larger than any element
lower_bound_10 = bisect_left(sorted_list, target_larger)
print(f"The lower bound of {target_larger} is at index: {lower_bound_10}")
# Output: The lower bound of 10 is at index: 8 (length of the list)