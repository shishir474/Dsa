You are given 3 arrays A, B and C. All 3 of the arrays are sorted.

Find i, j, k such that :

max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])) is minimized.

Return the minimum max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i]))

**abs(x) is absolute value of x and is implemented in the following manner : **

      if (x < 0) return -x;
      else return x;
Example :

Input : 
        A : [1, 4, 10]
        B : [2, 15, 20]
        C : [10, 12]

Output : 5 
         With 10 from A, 15 from B and 10 from C. 



int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int ans=INT_MAX;
    int n1=A.size(), n2 = B.size(), n3 = C.size();
    int i=0,j=0,k=0;
    while(i<n1 && j<n2 && k<n3){
        int x =  abs(A[i]-B[j]), y=abs(B[j]-C[k]), z=abs(C[k]-A[i]);
        int maxVal =  max({x,y,z});
        ans = min(ans, maxVal);
        if (maxVal==x){
            if (A[i] < B[j]) i++;
            else
            j++;
        }
        else if(maxVal==y){
            if (B[j] < C[k]) j++;
            else
            k++;
        }
        else{
            if (A[i] < C[k]) i++;
            else
            k++;
        }
    }

    return ans;

}
