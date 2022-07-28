Remove Element

Given an array and a value, remove all the instances of that value in the array. 

Also return the number of elements left in the array after the operation.

It does not matter what is left beyond the expected length.

Example:

If array A is [4, 1, 1, 2, 1, 3]

and value elem is 1, 

then new length is 3, and A is now [4, 2, 3]


int Solution::removeElement(vector<int> &A, int B) {
    int j=0; // j = 0, basically refers the front pointer where the element should be placed. SO if it is a good element just place it at the position pointed by the front and do front++(next good element will be placed here)
    for(int i=0; i<A.size(); i++){
        if (A[i] != B){
            A[j] = A[i];
            j++;
        }
    }

    return j;
}
