We can write 2 nested loop and check each pair if it satisfies the criteria of reverse pairs

better solution

arr[] = {7, 2, 3, 3, 1, 5}

broke it down into 2 halves and got the count in each part. now lets check for the pairs between these 2 parts

left        right    
{2, 3, 7}  {1, 3, 5}

In inversion count 2 > 1 -- yes so (2,3,7) all will form a pair with 1 
but this logic will not work here.

2 not > 2*1
so we will simply put 3 into temp and do right++
2 might not form a pair, but 3 and 7 can


Assume you have been given these 2 sorted arrays and the condition is arr[i] > 2*arr[j]
For these couple of arrays can you find the no of pairs where if you take something from the left that should be > 2 * somethingn on right array
[6, 13, 21, 25]     [1,2,3,4,4,5,9,11,13]
 
(21,2), (21,3) can be a pair 
but (21,13) cant

so lets move in the same way as we did in the count inversions problem.
So we have 2 arrays both of them are sorted. In count inversions what we did was we were basically having condition 
arr[i] > arr[j], so in a case where we were standing at 6 and 3 we were sure enough that if 3 and 6 are compared, 6 > 3 , so thereby all the nos on the rhs of 6 will form a pair with 3.

[6, 13, 21, 25]     [1,2,3,4,4,5,9,11,13]
i                        j

(6,3) (13,3), (21,3), (25,3) -- this is only possible because since 6 > 3, all the nos on the rhs will also form a pair with 3. Thats why we ended up increasing the count by 4.
But over here that condition or that process will not work.
I know 6 > 3, but its not greater than 2*3, so 6 cannot form a pair, but 13 can, 21 can and 25 can. You will miss out. You will just take 3 and move forward to 4

In the arr[i] > arr[j] case, if 6 forms, all the nos on the rhs will also form.
But over here arr[i] > 2*arr[j], 6 does not form a pair with 3, but 13, 21 & 25 can 

If 6 is not forming the pair, the next elements mightbe

We will apply a slighlty different logic.
For 6 we will try to find with which elements can 6 form a pair 
Then for 13, we will try to do the same thing (with which elemetns can 13 form a pair)
and then again repeat the same process for next elements in arr1

6 ->. {1, 2}
13 ->. {1, 2, 3, 4, 4, 5}
21 -> {1, 2, 3, 4, 4, 5, 9}
25 -> {1, 2, 3, 4, 4, 5, 9, 11}

There is a pattern. If {1,2} can form a pair with 6, then they can also form a pair with 13, 21, and 25.
Why? The reason is 13 > 6 so all the elements that form a pair with 6, with also form a pair with 13, 21, and 25.
Because if 6 > someone, 13, 21 and 25 are also bound to be greater than those elements.  We will use this analogy and the same elements can be reused.

As of now what Im doing is first Im trying to find the pairs for 6, then Ill try to find the pairs for 13, 21, and 25.
So Im iterating throughout which might end up taking a lot of time.

Because the array is sorted, Ill end up using a very simple technique.
For 6 lets see till which we can have the ans
{1,2} can and Ill stop at 3 because 6 is not greater than 2*3


[6, 13, 21, 25]     [1,2,3,4,4,5,9,11,13]
l                        r   
For 6 I can add 2 to my ans

Next I ll move to 13, Remember you dont need to start checking from the first again. Straightaway start from 3.
[6, 13, 21, 25]     [1,2,3,4,4,5,9,11,13]
    l                    r 

[6, 13, 21, 25]     [1,2,3,4,4,5,9,11,13]
    l                            r 
Ill stop at this point because 13 is not greater than 2*9.
For 13 I can 6 to my ans which is essentially r 

Next Ill move to 21
[6, 13, 21, 25]     [1,2,3,4,4,5,9,11,13]
        l                        r 
[6, 13, 21, 25]     [1,2,3,4,4,5,9,11,13]
        l                           r 
Ill stop at 11, because 21 is not greater than 2*11. I will add r to the ans.

[6, 13, 21, 25]     [1,2,3,4,4,5,9,11,13]
             l                      r 
[6, 13, 21, 25]     [1,2,3,4,4,5,9,11,13]
             l                        r 
Ill stop at 13.


The trick is for each l, you dont need to start from the first in 2nd array. because the arrays are sorted, if arr[l] > 2 * arr[r], then all the elements next to arr[l] will also be greater than arr[r]

For every element, I figured out how many elements can it be paired with. So this is what we will try to implement in the merge sort. 
Why ? because both the parts are sorted. and if you remember where did we have sorted arrays because the starting / original array might not be sorted

We know one thing for sure, when we break down in merge sort, we get sorted parts. So for every sorted part I can compute the ans

Instead of relying on 2 pointers, I slightly changed the 2 ptr technique. Lets come back to our original problem. Now we did solved a different problem where we were given 2 sorted arrays.

If I have the original array, how can I take them to a position where we have 2 sorted arrays. The best is to perform a merge sort. because it divides, divides, divides
 
and then auto converts them to the sorted arrays. Lets try to divide them 

                                                    {40,25,19,12,9,6,2}
                                              {40,25,19,12}         {9,6,2}       
                                          {40,25}  {19,12}            {9,6} {2}
                                      {40}{25}          {19}{12}    {9} {6}

If I try to write them separately {40} {25}. -- just try to map this to the problem which we solved for 2 sorted arrays find the no of pairs.
                                    l.  r 
                                    40 is not greater than 2*25  
                                    {40}    {25}   
                                         l   r          0 pairs for 40

                                    Pls note that this is a different step and not the same as merge. Once you have done this, then you will do the normal step of merging.
                                    This merging is a completely different step (pls remember that)

                                    {40} {25}
                               temp {25,40}     -- change it back in arr 

                                                    {40,25,19,12,9,6,2}
                                              {40,25,19,12}         {9,6,2}       
                                          {25,40}  {19,12}            {9,6} {2}
                                      {40}{25}          {19}{12}    {9} {6}


                            {19}, {12}
                            l      r    
                            {19}, {12}
                                 l  r   
                            19 is not greater than 2*12. So 0 pairs for 19 and l++

                            Now merge this 2 sorted arrays, this gives us temp: {12,19}. Update it back in arr 

                                                        {40,25,19,12,9,6,2}
                                              {40,25,19,12}         {9,6,2}       
                                          {25,40}  {12,19}         {9,6} {2}
                                      {40}{25}          {19}{12}   {9} {6}

                            {25,40}  {12,19}   I have again 2 sorted arrays, lets try to find the count of pairs 
                            i.        j 
                            25 > 2 * 12  yes move j

                            {25,40}  {12,19}   
                             i.           j 
                            25 is not greater than 2*19. so 1 pair for 25 and do i++

                            {25,40}  {12,19}   
                                i.        j 
                            40 > 2 * 19 yes move j 

                             {25,40}  {12,19}   
                                i.            j
                            so basically for 40, we have 2 pairs  

                            Now lets merge this 2 sorted arrays {25,40}  {12,19}   
                            {25,40}  {12,19}   
                            l.         r
                            since 12 < 25 temp = {12}
                            {25,40}  {12,19}   
                            l.            r
                            since 19 < 25 temp = {12,19}
                            {25,40}  {12,19}   
                            l.               r 
                            since arr2 is exhausted, copy the remaining elements from arr1 in temp 
                            temp = {12,19,25,40}
                            Now update in the original arr. 
                            {12,19,25,40} 

                                                    {2,6,9,12,19,25,40}
                                            {12,19,25,40}             {2,6,9}       
                                          {25,40}  {12,19}          {6,9} {2}
                                      {40}{25}      {19}{12}       {9} {6}


l                        r       
[6, 13, 21, 25]     [1,2,3,4,4,5,9,11,13]
lo           m      m+1                hi   

    l                            r       
[6, 13, 21, 25]     [1,2,3,4,4,5,9,11,13]
lo           m      m+1                hi   
        l                           r       
[6, 13, 21, 25]     [1,2,3,4,4,5,9,11,13]
lo           m      m+1                hi  

            l                          r       
[6, 13, 21, 25]     [1,2,3,4,4,5,9,11,13]
lo           m      m+1                hi 

int j = m+1;
for(int i = lo; i <= m; i++){ // for each i , I have to find the # of pairs 
    while(j<=hi and arr[i] > 2*arr[j]) j++;
    cnt += (j - m - 1);         // #of ele between m+1 to j-1 = (j-1) - (m+1) + 1 = j - m - 1

}

For 6, you will stop at 3. So your no of elements will be essentially #of ele from m+1 to r-1 which is r - m - 1

class Solution {
public:
    void countPairs(vector<int>& arr, int lo, int m, int hi, int &cnt){
        int right = m+1;
        for(int i = lo; i <= m; i++){ // for each i , I have to find the # of pairs 
            while(right <= hi and (long long)arr[i] > (long long)2*arr[right]) right++;
            cnt += (right - m - 1);         // #of ele between m+1 to j-1 = (j-1) - (m+1) + 1 = j - m - 1
        }
    }

    void mergeSortedArrays(vector<int>& arr, int lo, int m, int hi){
        // here you will be given 2 sorted arrays and you need to merge them 
        // arr[lo..m] & arr[m+1..hi] 

        // then perform the standard step of merging the 2 sorted arrays
        // arr[lo..m]
        // arr[m+1..hi]
        vector<int> temp;
        int left = lo; 
        int right = m+1;
        while(left <= m && right <= hi){
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                right++;
            }
        }
        while(left <= m){
            temp.push_back(arr[left]);
            left++;
        }
        while(right <= hi){
            temp.push_back(arr[right]);
            right++;
        }
        for(int i = lo; i <= hi; i++){
            arr[i] = temp[i - lo];
        }

    }
    void mergeSort(vector<int> &arr, int lo, int hi, int &cnt){
        if(lo >= hi) return;
        int m = (lo + hi)/2;
        mergeSort(arr, lo, m, cnt) ;
        mergeSort(arr, m + 1, hi, cnt) ;
        countPairs(arr, lo, m, hi, cnt);     // could have written this inside merge step as well, but to improve the code quality
        mergeSortedArrays(arr, lo, m, hi);

    }
    int reversePairs(vector<int>& arr) {
        int cnt = 0;        // pass by reference
        mergeSort(arr, 0, arr.size() - 1, cnt);    
        return cnt;
    }
};


//  Could have used a global cnt variable as well --> not a good practise, hence created a cnt variable and passed it by refernce.
// Next step to improve the code could be, instead of passing by reference, lets make the function return the value
// This merge sort is going to distort your input array. This will sort your input array. If the interviewer has a problem with it, I can take a copy and solve this.
Please mention this to your interviewer. -- VVIMP 


// REFER STRIVER ARTICLES TO CHECK THE CODE QUALITY
// NOTE: THIS IS A GOOD PROBLEM & YOU NEED TO KNOW THIS BEFOREHAND. THERE IS A HIGH CHANCE THAT YOU WONT BE ABLE TO INVENT THIS ALGO IN THE INTERVIEW ITSELF
// YOU HAVE TO SOLVE THIS KIND OF PROBLEMS BEFOREHAND

TC: O(logn) since we are dividing the array each time into 2 halves and then O(n) during merge + O(N) during counting pairs 
So overall tc becomes O(2*nlogn)

We optimised the countPairs function -- by making sure that for each i, we are not starting comparisons from the first ele in arr[m+1..hi]
This basically reduces the complexity to O(n)


SC: O(n): using O(n) space while performing the merge operation 



// Best code quality solution:

class Solution {
public:
    int countPairs(vector<int>& arr, int lo, int m, int hi){
        int right = m+1;
        int cnt = 0;
        for(int i = lo; i <= m; i++){ // for each i , I have to find the # of pairs 
            while(right <= hi and (long long)arr[i] > (long long)2*arr[right]) right++;
            cnt += (right - m - 1);         // #of ele between m+1 to j-1 = (j-1) - (m+1) + 1 = j - m - 1
        }
        return cnt;
    }

    void mergeSortedArrays(vector<int>& arr, int lo, int m, int hi){
        // here you will be given 2 sorted arrays and you need to merge them 
        // arr[lo..m] & arr[m+1..hi] 

        // then perform the standard step of merging the 2 sorted arrays
        // arr[lo..m]
        // arr[m+1..hi]
        vector<int> temp;
        int left = lo; 
        int right = m+1;
        while(left <= m && right <= hi){
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                right++;
            }
        }
        while(left <= m){
            temp.push_back(arr[left]);
            left++;
        }
        while(right <= hi){
            temp.push_back(arr[right]);
            right++;
        }
        for(int i = lo; i <= hi; i++){
            arr[i] = temp[i - lo];
        }

    }
    int mergeSort(vector<int> &arr, int lo, int hi, int &cnt){
        int cnt = 0;
        if(lo >= hi) return cnt;
        int m = (lo + hi)/2;
        cnt += mergeSort(arr, lo, m, cnt) ;         // consider pairs in arr[lo..m]
        cnt += mergeSort(arr, m + 1, hi, cnt) ;     // consider pairs in arr[m+1..hi]
        // countPair() considers pairs between arr[lo..m] and arr[m+1..hi]
        cnt += countPairs(arr, lo, m, hi, cnt);     // could have written this inside merge step as well, but to improve the code quality
        mergeSortedArrays(arr, lo, m, hi);
        return cnt;

    }
    int reversePairs(vector<int>& arr) {
        return mergeSort(arr, 0, arr.size() - 1);    
    }
};