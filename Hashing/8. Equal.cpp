Given an array A of integers, find the index of values that satisfy A + B = C + D, where A,B,C & D are integers values in the array

Note:

1) Return the indices `A1 B1 C1 D1`, so that 
  A[A1] + A[B1] = A[C1] + A[D1]
  A1 < B1, C1 < D1
  A1 < C1, B1 != D1, B1 != C1 

2) If there are more than one solutions, 
   then return the tuple of values which are lexicographical smallest. 

Assume we have two solutions
S1 : A1 B1 C1 D1 ( these are values of indices int the array )  
S2 : A2 B2 C2 D2

S1 is lexicographically smaller than S2 iff
  A1 < A2 OR
  A1 = A2 AND B1 < B2 OR
  A1 = A2 AND B1 = B2 AND C1 < C2 OR 
  A1 = A2 AND B1 = B2 AND C1 = C2 AND D1 < D2
Example:

Input: [3, 4, 7, 1, 2, 9, 8]
Output: [0, 2, 3, 5] (O index)
If no solution is possible, return an empty list.



vector<int> Solution::equal(vector<int> &A) {
// https://www.geeksforgeeks.org/find-four-elements-a-b-c-and-d-in-an-array-such-that-a+b = c+d/
// Same approach can be followed for problem finding all quadruplets such that a*b = c*d
// The time complexity of map insert and search is actually O(Log n) instead of O(1). So below implementation is O(n2 Log n).
    map<int,pair<int,int> > mp;
    vector<vector<int> > v;

    int n = A.size();
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int sum = A[i] + A[j];
            if (mp.count(sum) == 1){
                if (mp[sum].first<i && mp[sum].second!=j && mp[sum].second!=i) // checking conditions. NO need to check first two conditions. they are satisfied
                v.push_back({mp[sum].first, mp[sum].second, i, j});
            }

            if (mp.count(sum)==0)
            mp[sum] = {i,j};
        }
    }
    
    if (v.size()==0)
    return {};
  
    sort(v.begin(), v.end());  // sort the v vector to get the desired result
    return v[0];
    
}
