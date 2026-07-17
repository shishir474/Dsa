unsorted_list = [('Eve', 78), ('Bob', 99), ('Suzy', 86), ('Alice', 86)]

#NOTE: key function takes 1 argument and returns a value to be used for sorting purposes. 
# The key function is applied to each element in the list before sorting.

# In python, we use key based sorting unlike in cpp where we use comparator function. 
# In python, we can use lambda functions to define the key function inline.

# sort by name
unsorted_list.sort(key=lambda x: x[0])
print(unsorted_list)     # [('Alice', 86), ('Bob', 99), ('Eve', 78), ('Suzy', 86)]

# sort by score
unsorted_list.sort(key=lambda x: x[1])
print(unsorted_list)     # [('Eve', 78), ('Alice', 86), ('Suzy', 86), ('Bob', 99)]  

# sort by score and then by name
unsorted_list.sort(key=lambda x: (x[1], x[0]))
print(unsorted_list)     # [('Eve', 78), ('Alice', 86), ('Suzy', 86), ('Bob', 99)]  

# sort by score in descending order
unsorted_list.sort(key=lambda x: x[1], reverse=True)
print(unsorted_list)     # [('Bob', 99), ('Alice', 86), ('Suzy', 86), ('Eve', 78)]