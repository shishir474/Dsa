ex: s1="xaa", s2="xa*"

SOME HINTS: length of both strings should be equal hence 1st col is 0 except t[0][0] 
For first row we aill have to specailly check for '*'

// ith char matches with j-1 char,considder ith char to be part of the * part and now we have to match i-1,j
if(s1[i-1]==s2[j-2]|| s2[j-2]=='?'){

}

// https://www.youtube.com/watch?v=l3hda49XcDE&ab_channel=TusharRoy-CodingMadeSimple
// Take any example and do a dry run

DP Table Meaning
t[i][j] is true if the first i characters of A match the first j characters of B.

Transitions
    Direct Match or .:
        If A[i-1] == B[j-1] or B[j-1] == '.', then t[i][j] = t[i-1][j-1].
    * Handling:
        * can mean:
            Zero occurrence: Ignore the previous character and * (t[i][j] = t[i][j-2]).
            One or more occurrence: If A[i-1] == B[j-2] or B[j-2] == '.', then t[i][j] = t[i-1][j] (use * to match one more character).
    No Match:
        Otherwise, t[i][j] = 0.

Base Cases
Empty string and empty pattern match (t[0][0] = 1).
Empty string and pattern with * can match if the pattern can represent an empty string (handled in the first row).

Pattern Recognition
    This is a classic DP on Strings or "Subsequence/Subarray Pattern" (also called "LCS-style DP") pattern.


int Solution::isMatch(const string A, const string B) {
    int m = A.length(), n = B.length(); // m+1 rows and n+1 cols
    int t[m+1][n+1];
    memset(t,0,sizeof(t));
    t[0][0] = 1;
    for(int i=1;i<=n;i++){
        if (B[i-1]=='*'){
            t[0][i] = t[0][i-2];
        }
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if (A[i-1]==B[j-1] || B[j-1]=='?'){// ith and jth char match
                t[i][j] = t[i-1][j-1];
            }
            else if(B[j-1]=='*'){
                
                t[i][j] = t[i][j-2];
                
                if (A[i-1]==B[j-2] || B[j-2]=='?'){ // ith and j-1th char match or j-1th char is .
                    t[i][j] = t[i][j] || t[i-1][j];
                }
            }
            else{
                t[i][j] = 0;
            }
        }
    }

    return t[m][n];
}

Follow Up
    Wildcard Matching
    Hard