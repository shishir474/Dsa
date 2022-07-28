Search in Bitonic Array!


Given a bitonic sequence A of N distinct elements, write a program to find a given element B in the bitonic sequence in O(logN) time.

NOTE:

A Bitonic Sequence is a sequence of numbers which is first strictly increasing then after a point strictly decreasing.


Problem Constraints
3 <= N <= 105

1 <= A[i], B <= 108

Given array always contain a bitonic point.

Array A always contain distinct elements.



Input Format
First argument is an integer array A denoting the bitonic sequence.

Second argument is an integer B.



Output Format
Return a single integer denoting the position (0 index based) of the element B in the array A if B doesnt exist in A return -1.



Example Input
Input 1:

 A = [3, 9, 10, 20, 17, 5, 1]
 B = 20
Input 2:

 A = [5, 6, 7, 8, 9, 10, 3, 2, 1]
 B = 30


Example Output
Output 1:

 3
Output 2:

 -1


 int getPeakElementIndex(vector<int> &A, int B){
    int lo=0,hi=A.size()-1;
    while(lo<hi){
        int mid=lo+(hi-lo)/2;
        if(A[mid]<A[mid+1]){
            lo=mid+1;
        }
        else{
            hi=mid;
        }
    }
    
    return lo;
}

int binarySearch1(int i,int j, vector<int>& A,int B){
    int lo=i,hi=j;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(A[mid]==B) return mid;
        else if(A[mid] < B){
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }
    
    return -1;
}


int binarySearch(int i,int j, vector<int>& A,int B){
    int lo=i,hi=j;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(A[mid]==B) return mid;
        else if(A[mid] < B){
            lo=mid+1;
        }
        else{
            hi=mid-1;
        }
    }
    
    return -1;
}

int Solution::solve(vector<int> &A, int B) {
    int i=getPeakElementIndex(A,B);
   // cout<<i<<endl;
    if(A[i]==B) return i;
    int idx=binarySearch(0,i,A,B);
    if(idx!=-1) return idx;
    int idx2 = binarySearch1(i,A.size()-1,A,B);
    return idx2;
    
    
}
