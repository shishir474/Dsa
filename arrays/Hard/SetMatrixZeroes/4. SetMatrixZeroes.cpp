Set matrix zeroes. 

You will be given a binary matrix containing 0,1.
Now the goal is to fill zeroes in the entire row and columnn where you see 0 in the matrix 

Input: matrix = [[1,1,1],
                 [1,0,1],
                 [1,1,1]]
Output: [[1,0,1],
         [0,0,0],
         [1,0,1]]



Brute --> Better --> Optimal O(1) space approach 



Brute  :

We are given an n X m matrix --> we will iterate over the matrix. The moment you find a zero the task was to convert all values in that row and column to 0.
But if we do that then marking a cell 0 in the row or column in future  can lead to marking 0s in their row/column as well (which would be incorrect)
ex: at(1,1) you found 0 and you marked the entire 1st row 0, then at (1,2) you found 0, so you marked the entire column 2 as 0 (which is wrong)

Instead I will mark every thing(except 0) as -1 or any value that does not exist in the matrix. WHy not zero? because in future we would need to mark its column as well.  

NOTE: Anything apart from 0, I will mark as -1 

INPUT = [[1,1,1,1],
        [1,0,0,1],
        [1,1,0,1],
        [1,1,1,1]]

On (1,1) I found a 0, So I marked 1st row and 1st col with -1 (dont mark 0)
        [[1,-1,1,1],
        [-1,0,0,-1],
        [1,-1,0,1],
        [1,-1,1,1]]
On (1,2) again we found a 0, so we mark 1st row and 2 column -1 (except 0)
        [[1,-1,-1,1],
        [-1,0,0,-1],
        [1,-1,0,1],
        [1,-1,-1,1]]
On (2,2) again we found a 0, so we marked 2nd row and 2nd col with -1 (except 0)
        [[1,-1,-1,1],
        [-1,0,0,-1],
        [-1,-1,0,-1],
        [1,-1,-1,1]]

In the last step --> replace all -1 with 0
This will be your final ans 

void markRow(int i){
    for(int j = 0; j < m ;j++){
        if(arr[i][j] != 0){
            arr[i][j] = -1; 
        }
    }
}
void markCol(int j){
    for(int i = 0; i < n ;i++){
        if(arr[i][j] != 0){
            arr[i][j] = -1; 
        }
    }
}

// The nested for loop will run for n*m times
// TC:  n * m * (n + m)
for(int i = 0; i < n; i++){
    for(int j = 0; j < m ;j++){
        if(arr[i][j] == 0){
            markRow(arr,i); // m times
            markCol(arr,j); // n times
        }
    }
}

// 2nd iteration: convert -1 to 0
// n * m
for(int i = 0; i < n; i++){
    for(int j = 0; j < m ;j++){
        if(arr[i][j] == -1){
            arr[i][j] = 0;
        }
    }
}

// 2 iterations needed 
// TC: O(n * m * (n + m)  +  (n * m) )    -- this is somewhat cubic  


-----------------------------------------------------------------------
Better Solution:

During each n*m states, we were marking the row and col with -1. This is where we can optimise 
So instead of markgin the value right then and there, we will keep track of the rows and columns. And then at the end of the day, I will mark al such rows and columns with 0

In order to convert this thoughtprocess into an algorithm, I woudl need 2 arrays row and col of size n and m 
where row[i] = 1 signifies that ith row needs to be marked as all 0
similarly col[j] = 1 signifies that jth column needs to be marked all 0

In order to mark a row entirely 0, we need at least one zero in that row.
Similarly, in order to mark a columnn entirely 0, we need atleast one zero in that column.

So if I encouter a 0, I mark row[i] = 1 and col[j] = 1
and then in the next step I will mark all rows entirely 0 and all columns entirely 0 where row[i] = 1 and col[j] = 1

vector<int> row(n,0), col(m,0);

for(int i = 0; i < n; i++){
    for(int j = 0; j < m ;j++){
        if(arr[i][j] == 0){         
            row[i] = 1;             // this signifies that at the end ith row and jth column needs to be marked as 0
            col[j] = 1;
        }
    }
}

// mark a cell 0 iff either row[i]==1 or col[j] ==1
for(int i = 0; i < n; i++){
    for(int j = 0; j < m ;j++){
        if(row[i] || col[j]){
            arr[i][j] = 0;
        }
    }
}


// Instead of doing this in 2 iterations, we can do this in 1 iteration as well

// for(int i = 0; i < n; i++){
//     if(row[i] == 1){       // mark the entire ith row 0
//         for(int j = 0; j < m;j++){
//             arr[i][j] = 0;
//         }
//     }
// }

// for(int i = 0; i < m; i++){
//     if(col[i] == 1){       // mark the entire ith col 0
//         for(int j = 0; j < n;j++){
//             arr[j][i] = 0;
//         }
//     }
// }
 
// TC: O(n*m + n*m) = O(2*n*m) = O(n*m)       quadratic solution 
// SC: O(n) + O(m) for 2 arrays row[] and col[]


-----------------------------------------------------------------------

Optimal Solution:  O(1) space 

We have already solved this in O(n*m) time, we cant do any better than this as we need to traverse the matrix atleas which will take n*m time
But we can probably think of optimising the space

We were taking a row[] and a col[] and if we have to optimise this we have to do this in the matrix itself?

can I keep a track in the matrix itself?

yes, we can. Instead of taking a row[] outside what if I consider 1st col as my row[] and 1st row as my col[] (inplace)

Only thing to take care while taking the row and col as 1st col and 1st row is (0,0) will be a commmon for both. So Instead for the 0th col, I will track that in a variable.

col[]= [1: ] and col variable for tracking 0th col 
row[]=  [0:n-1] 
 
class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {
        int n = arr.size(), m = arr[0].size();
        // int col[m] = {0};  -> arr[0][...]
        // int row[n] = {0};  -> arr[..][0]
        int col0 = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m ;j++){
                if(arr[i][j] == 0){       
                    // mark the i-th row
                    arr[i][0] = 0;
                    // mark the j-th col
                    if(j != 0)
                        arr[0][j] = 0;
                    else    
                        col0 = 0;
                }
            }
        }


        // The direction in which you traverse the matrix is important
        // you cannot start from 0th row or 0th col         This is also vlid
        for(int i = n-1; i>=1; i--){            // can go from i = 1 -> n
            for(int j = m-1; j>= 1; j--){           // and j = 1 -> m
                if(arr[i][0] == 0 || arr[0][j] == 0){
                    arr[i][j] = 0;
                }
            }
        }

        // first cover the 0th row [m-1:1]
        if(arr[0][0] == 0){
            for(int j = 0; j < m; j++) arr[0][j] = 0;
        }

        if(col0 == 0){
            for(int i = 0; i < n; i++) arr[i][0] = 0;
        }

    }
};


TC: O(n*m + n*m + m + n) = O(n*m)
SC: O(1) - we are not using any extra space. Matrix is being modified in place.

1. Took row[] and col[] as 1st col and 1st row in the matrix.
2. (0,0) cell is common in both hence took another variable col_val which if marked 0 signifies 0th col will be entirely 0
3. Now you cannot modify the 1st row and 1st col initially. So the way we would reiterate is mat[1:][1:] but in the reverse order. For these cells, if any of matrix[i][0] or matrix[0][j] is 0 matrix[i][j] will be set to 0
4. Now we will traverse 1st row from col[1:] because the value of a cell in matrix[0][j] depends on matrix[0][0] and if you traverse first col, first, then that would change the value of matrix[0][0] which will impact the 0th row values 
5. Hence its necessary that you start traversing 1st row first columns matrix[0][1:] 
    and then 1st col matrix[0:][0]