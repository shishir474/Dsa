from collections import deque

# Directions: L, R, U, D
X_dir = [0, 0, -1, 1]
Y_dir = [-1, 1, 0, 0]
dir_char = ['L', 'R', 'U', 'D']


def get_A_pos(mat):
    for i in range(len(mat)):
        for j in range(len(mat[i])):
            if mat[i][j] == 'A':
                return (i,j)
    return -1,-1  # If 'A' is not found, return None

def bfs(sr,sc,mat):
    n, m = len(mat), len(mat[0])
    vis = [[False] * m for _ in range(n)]
    temp = [['$'] * m for _ in range(n)]  # Initialize the matrix with '$'
    
    # deque stands for double-ended queue, which allows appending and popping from both ends
    # It is more efficient than using a list for queue operations
    # In list, appending and popping from the front is O(n), while in deque it is O(1)
    # list.pop(0) is O(n) because it has to shift all elements, while deque.popleft() is O(1)
    q = deque()
    q.append((sr,sc))
    vis[sr][sc] = True
    
    while q:
        x,y = q.popleft()
        
        if mat[x][y] == 'B':
            # reconstruct the path
            path = []
            a,b = x,y
            while (a,b) != (sr,sc):
                d = temp[a][b]
                path.append(d)
                if d == 'L':    
                    b += 1
                elif d == 'R':
                    b -= 1
                elif d == 'U':
                    a += 1
                elif d == 'D':
                    a -= 1
            path.reverse()
            return True, ''.join(path)
        
        for k in range(4):
            newx = x + X[k]
            newy = y + Y[k]
            if 0 <= newx < n and 0 <= newy < m and not vis[newx][newy] and mat[newx][newy] != '':
                vis[newx][newy] = True
                temp[newx][newy] = dir_char[k]
                q.append((newx,newy))

    return False, ''  # If 'B' is not found, return False and empty path


def main():
    n,m = map(int,input().split())      # python oneliner to read two integers from input
    # input() reads a line from standard input
    # .split() splits a string into a list of substrings. For ex: "5 8" -> ['5', '8']
    # map(int, ...) converts each element in the list to an integer
    # n,m unpack the two integers from the list into two variables
    
    mat = [list(input().strip()) for _ in range(n)]
    # list comprehension to read a 2D matrix from input
    # input().strip() reads a line, removes leading/trailing whitespace
    # list(input().strip()) converts the string into a list of characters
    # [list(input().strip()) for _ in range(n)] creates a list of lists
    
    x,y = get_A_pos(mat)
    
    found, path = bfs(x,y,mat)
    if found:
        print("YES")
        print(len(path))
        print(path)
    else:
        print("NO")
        
if __name__ == "__main__":
    main()
    