# https://www.geeksforgeeks.org/python/file-handling-python/

file = open('geeks.txt', 'r')
data = file.read()
print(data)

# accessing some metadata about file 
print(file.name) 
print(file.mode) # mode in which file was opened
print(file.closed) # false 

file.close()

# syntax:
# file = open('filename.txt', 'mode')
# filename.txt: name (or path) of the file to be opened.
# mode: mode in which you want to open the file (read, write, append, etc.).
# returns a file object associated with the file
# if the file does not exist -- raises FileNotFoundError

# file.close()
# closes the file and releases the system resources


# writing to a file

# creates a new file(if the file doesn't exist) or overwrites the existing file
# file is the file object -- we're trying to open geeks.txt in write mode
# write() allows us to write into the file
# this syntax automatically closes the file at the end
with open('geeks.txt','w') as file:
    file.write("Hey there")
    
    
# Using with statement
# Instead of manually opening and closing the file, you can use the with statement, which automatically handles closing.
with open('file.txt','r') as file:
    data = file.read()
    print(data)
    

# handling exception:even if an error occurs during file operations. Here, the finally block ensures the file is closed even if an error occurs.
try:
    file = open('geeks.txt','r') 
    data = file.read()
    print(data)
finally:
    file.close()
    
    
# Different modes in file handling: https://www.geeksforgeeks.org/python/file-mode-in-python/. [[ revisit -- pending]]