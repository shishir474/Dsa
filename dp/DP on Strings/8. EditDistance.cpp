s1 = "horse"
s2 = "res"
I am gettin an intuition that we need to do char matching. If the chars match then well n good, else we are allowed to do 3 types of operations:
1. We can insert a char 
2. We can delete a char
3. We can replace a char

I know i have to try all possible ways (insert, delete, replace). Amongst all this I need to figure out whats the best for us.
and this leads us to explore all possibilities and return the min of them.

The way we check all ways is using recursion.

How to write recurrence?
1. Express in terms of indexes. Here we need 2 indexes (i,j)
2. Explore all paths of matching
3. Return min of all paths 
4. Base case -- when either of the strings is empty

           i 
s1 = "horse"
        j
s2 = "res"

f(n-1, m-1)-- this signifies the min no of operations to convert s1[0..i] to s2[0..j]
   i,   j

I know whenever we are doing string matching, there are always 2 possible cases:
1. They match
2. They dont match

Insert operation:
you hypothetically insert a char right next to ith index which matches the jth char of s2. Now you need to match f(i,j-1)

Delete operation:
you hypothetically delete the ith char of s1. Now you nee d to match f(i-1,j)

Replace operation:
you hypothetically replace the ith char of s1 with the jth char of s2. Now you need to match f(i-1,j-1)

I can do 3 operations:

f(i,j){
    if (s1[i] == s2[j]) {       // If they end up matching -- you dont want to do anything. Just shrink the string 
        return 0 + f(i-1,j-1)
    }
    else{
        // I can delete the ith char and now I need to match f(i-1,j)
        // I can insert the jth char and now I need to match f(i,j-1) - since the jth char is matched because we added that in s1, we now need to match s1 i with s2 j-1
        // I can replace the ith char with jth char and now I need to match f(i-1,j-1)
        return 1 + min({f(i+1,j), f(i+1,j+1), f(i,j+1)});
    }
}

// TC: exponential (we are calling 3 states each time 3^n)
// SC: O(n+m)

If you try to draw the recursion tree, you will see that there are many overlapping subproblems. Hence we can apply memoisation

base case: 
if either of string is empty
    if s1 is empty, we need to delete all characters of s2 which will be m - j 
    if s2 is empty, we need to delete all characters of s1 which will be n - i 
    where n & m are the lengths of s1 and s2 respectively.
    and i and j are the current indices in s1 and s2.
if both s1 and s2 are empty:
    no operations needed -- we return 0 since those 2 are already equal


------------------------------------------------------

Recursion + memoisation

class Solution {
public:
    int t[502][502];
    int f(int i, int j, string word1, string word2){
        int n = word1.size(), m = word2.size();
        if(i >= n && j >= m) return 0;
        if(i >= n || j >= m){
            if(i >= n) return m - j;
            else return n - i;
        }
        if(t[i][j] != -1) return t[i][j];

        if(word1[i] == word2[j]){
            return t[i][j] = f(i+1,j+1,word1,word2);
        }
        else{
            return t[i][j] = 1 + min({f(i+1,j,word1,word2), f(i+1,j+1,word1,word2), f(i,j+1,word1,word2)});
        }
    }
    int minDistance(string word1, string word2) {
        memset(t, -1, sizeof(t));
        return f(0,0,word1,word2);
    }
};

// TC: O(n * m)
// SC: O(n * m) + O(n + m) 
// O(n * m) for dp array and O(n + m) for recursion stack

-- Doubt : The auxilary Stack space should it be O(max(n,m)) or O(n + m)?


------------------------------------------------------

Tabulation Solution -- to get rid of auxilary stack space

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();

        vector<vector<int>> t(n+1, vector<int> (m+1, 0));

        // base case1 : i == n and j == m
        t[n][m] = 0;
        // base case 2: i == n or j == m
        for(int j=0; j<=m-1; j++) t[n][j] = m - j;
        for(int i=0; i<=n-1; i++) t[i][m] = n - i;

        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j >= 0; j--){
                if(word1[i] == word2[j]){
                    t[i][j] = t[i+1][j+1];
                }
                else{
                    t[i][j] = 1 + min({t[i+1][j], t[i+1][j+1], t[i][j+1]}); 
                }
            }
        }

        return t[0][0];


    }
};


// TC: O(n * m)
// SC: O(n * m)


------------------------------------------------------
// Space optimisation -- since ith row only depends on (i+1)th row, we can reduce the matrix to 2 rows


class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();

        vector<vector<int>> t(2, vector<int> (m+1, 0));

        // base case1 : i == n and j == m
        t[1][m] = 0;
        // base case 2: i == n or j == m
        for(int j=0; j<=m-1; j++) t[1][j] = m - j;
        // for(int i=0; i < 1; i++) t[i][m] = n - i;  -- covered this base case inside this for loop because its value changes depending on the current row

        int flag = 0;
        for(int i = n-1; i>=0; i--){
            t[flag][m] = n - i;         // 2nd base case for every row,, the last column value is n - i
            for(int j = m-1; j >= 0; j--){
                if(word1[i] == word2[j]){
                    t[flag][j] = t[flag^1][j+1];
                }
                else{
                    t[flag][j] = 1 + min({t[flag^1][j], t[flag^1][j+1], t[flag][j+1]}); 
                }
            }

            flag = flag^1;
        }
        
        flag = flag^1;

        return t[flag][0];


    }
};

// TC: O(n * m)
// SC: O(2*m)

// Can we optimise this to 1-D space?
// No, because we need to store the previous row for the current row's calculations.
// So you cannot optimise this beyond 2 1-D arrays.