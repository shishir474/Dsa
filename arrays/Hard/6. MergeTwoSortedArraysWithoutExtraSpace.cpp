Merge 2 sorted arrays without extra space. After merging the first m elements needs to go into arr1 and then the next n elements must go into arr2.

arr1 = [1,3,5,7]
arr2 = [0,2,6,8,9]

Brute Force -- uses extra space of m + n

1. create a 3rd array of size n + m. Take 3 pointers i,j,k for arr1,arr2 and arr3 

vector<int> arr3(m+n);
int i = 0, j = 0, k = 0;
while(i < m and j < n){
    if(arr1[i] <= arr2[j]){
        arr3[k] = arr1[i];
        k++; i++;
    }
    else{
        arr3[k] = arr2[j];
        k++; j++;
    }
}

while(i < n){
    arr3[k++] = arr1[i++];
}

while(j < m){
    arr3[k++] = arr2[j++];
}

for(int i = 0; i < m+n; i++){
    if(i < m) arr1[i] = arr3[i];
    else arr2[i-m] = arr3[i];
}

// in the first iteration we put values into arr3/temp & then in the next iteratoin we put values back into arr1 and arr2
TC: O(n + m) + O(n + m) = O(n + m)
SC: O(n + m)

 
-------------------------------------------------------------------------------- 
Optimal Solution 1 --- no extra space (using 2 pointers)
              i           j
arr1 = [1,3,5,7]  arr2 = [0,2,6,8,9]

if I stand at i in arr1, that is the largest elemeent in arr1 and j has the smallest element in arr2.
If I compare 7 and 0, 7 should be on the rhs and 0 should be on lhs. Yes that is what it technically should be, becuae 7 is bigger and should be on the rhs 
and 0 is smaller and should be on lhs and that is where we will take the advantage.

I will always start with the largest element in arr1 and smallest element in arr2 and I will compare them. Are they at their correct position?

so lets swap them and update i,j

            i               j
arr1 = [1,3,5,0]  arr2 = [7,2,6,8,9]

Again 5 is lesser than 2, so 2 should be on lhs and 5 on rhs 
so we swap them and update i,j

          i                   j
arr1 = [1,3,2,0]  arr2 = [7,5,6,8,9]
Now 3<=6, so technically it is already in the correct portion and so does the the prev elements of i and next elements of j.
All the elements on lhs of 3 will be smaller than 3 and all the elements on rhs of 6 will be greater than 6, so that means all those prev elements of i and next elements of j are also in their correct positions.

We have somehow managed to put everyting on the left and everything on the right. They are not in their correct order, but they are in their correct portions. 

Now by doing this we have made sure that each portion contains correct set of elements, although they are not in their correct order yet.
arr1 contains {1,2,3,0} and arr2 contains {7,5,6,8,9} and this is what was their in the final configuration as well.
So if we sort arr1 and arr2 we will get the desired result

arr1 = [0,1,2,3] arr2[5,6,7,8,9]

Conclusion:
We will always compare the largest element from arr1 with smallest element from arr2. if the largest element in arr1 is < smallest element in arr2, both the arrays are already sorted 
But if they are not, the smaller element on arr2 should be present in arr1 and vice versa for arr1 element.
Quite simple, just the 2 pointer approach


int n = arr1.size(), m = arr2.size();
int i = n-1, j = 0;
while(i >=0 && j < m){
    if(arr1[i] > arr2[j]){
        swap(arr1[i], arr2[j]);
        i--; j++;
    }
    else{       // elements are in their correct fashion and so does the remaining elements 
         break;
    }
}

// At this point, both arr1 and arr2 will contain correct set of elements(just sort them to get the final order)
sort(arr1.begin(), arr1.end());
sort(arr2.begin(), arr2.end());

TC: O(min(n,m)) + O(nlogn) + O(mlogm) -- either the arr1 will be first exhausted or arr2, hence min(n,m)
SC: O(1) -- not using any extra space apart from the given input arrays 


-------------------------------------------------------------------------------- 
Optimal Solution 2 --- no extra space (using gap method)

This gap method intuition comes from sorting technique known as shell sort. This gap method has been taken from this particular sorting technique 

how does the gap method work?
first calculate ceil((n + m)/2) where n,m are the size of arr1 and arr2.
here gap = ceil((4+5)/2) = 5

Initially we will start off with gap 5. 
I will keep first pointer at 0th index in arr1 and 2nd pointer at gap i.e 5 distance from i 
 i             j 
[1,3,5,7]   [0,2,6,8,9]

Now we will start comparing 
1 < 2 so they are already in correct position, update i and j 

   i             j 
[1,3,5,7]   [0,2,6,8,9]
3 and 6 are in their correct place. 3 should be on the left and 6 should be on the right 

     i             j 
[1,3,5,7]   [0,2,6,8,9]
5 and 8 are in their correct place. 5 should be on the left and 8 should be on the right 

       i             j 
[1,3,5,7]   [0,2,6,8,9]
7 and 9 are in their correct place. 7 should be on the left and 9 should be on the right 

             i          j 
[1,3,5,7]   [0,2,6,8,9]

The momemnt one of the pointers i,j move out of bounds, we restart the same activity. It is quite obvioous that j will always move out of bounds first 

How do we restart, by reducing the value of gap 
gap = ceil(gap/2)
gap = ceil(5/2) = 3

 i     j        
[1,3,5,7]   [0,2,6,8,9]
1 and 7 are in their correct place. 1 should be on the left and 7 should be on the right 

   i         j        
[1,3,5,7]   [0,2,6,8,9]
3 and 0 are not at their correct place. So we swap them 

     i         j        
[1,0,5,7]   [3,2,6,8,9]
5 and 2 are not at their correct place. So we swap them 

       i         j        
[1,0,2,7]   [3,5,6,8,9]
7 and 6 are not at their correct place. So we swap them 

             i     j        
[1,0,2,6]   [3,5,7,8,9]
3 and 8 are in correct position, so we update i,j 

               i     j        
[1,0,2,6]   [3,5,7,8,9]
5 and 9 are in correct position, so we update i,j 

                 i     j        
[1,0,2,6]   [3,5,7,8,9]
Since j is now out of bounds, we restart.

gap = ceil(3/2) = 2

 i   j                
[1,0,2,6]   [3,5,7,8,9]
1,2 are in correct position, so we update i,j
   i   j                
[1,0,2,6]   [3,5,7,8,9]
0,6 are in correct position, so we update i,j
     i       j                
[1,0,2,6]   [3,5,7,8,9]
2,3 are in correct position, so we update i,j
       i       j                
[1,0,2,6]   [3,5,7,8,9]
swap 6,5 and update i,j
             i   j                
[1,0,2,5]   [3,6,7,8,9]
3,7 are in correct position , so we update i,j
               i   j                
[1,0,2,5]   [3,6,7,8,9]
6,8 are in correct position , so we update i,j
                 i   j                
[1,0,2,5]   [3,6,7,8,9]
7,9 are in correct position , so we update i,j
                   i   j                
[1,0,2,5]   [3,6,7,8,9]
j goes out of bounds, so we restart by calculating new gap 

void swapIfGreater(vector<int> &arr1, vector<int> &arr2, int ind1, int ind2){
    if(arr1[ind1] > arr2[ind2]){
        swap(arr1[ind1], arr2[ind2]);
    }
}

int gap = ceil((n + m)/2.0);

while(gap > 0){
    int i = 0,  j = i + gap;
    while(j < (n + m)){     
        // 3 cases, (i in arr1 and j in arr2), (i,j in arr1) & (i,j in arr2)
        // arr1 and arr2
        if(i < n and j >= n){
            swapIfGreater(arr1, arr2, i, j - n);        // (j - n) will be the correspondint index in arr2
        }
        // arr2 and arr2  (both pointers i and j are in arr2) --> since j > i, and if we check i>=n then it also means j>=n, so we dont need 2 conditions i>=n and j>=n
        else if (i >= n){
            swapIfGreater(arr2, arr2, i - n, j - n);        // (i - n) and (j - n) are the corresponding index in arr2
        }
        // arr1 and arr1 (both pointers i and j are in arr1)
        else{
            swapIfGreater(arr1, arr1, i, j);      
        }
        
        i++; j++;
    }
   
    if(gap == 1) break;         // if you again calculate ceil(1/2.0) you will again get the gap as 1, so we break as soon as gap 1 has been processed
   
    gap = ceil(gap/2.0);

}

// TC: 
We have 2 while loops, The gap starts from len/2 and during each iteration it keep on getting halfed. 
In the inner while loop we are somewhat covering the entire len (n+m) not each time, but in certain instances when gap is small. In the worst case this is somewhere around n+m 
TC: O(log2(n+m) * (n+m))

// SC:  
O(1) nont using any extra space 