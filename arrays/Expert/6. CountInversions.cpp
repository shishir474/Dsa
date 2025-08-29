Given an array, we have to count the no of inversions

if (arr[i] > arr[j] and i < j) then this considerd as an inversion

arr[] = {7, 2, 3, 3, 1, 5}
inversions: (7,2), (7,3), (7,3) (7,1), (3,1), (3,1), (2,1), (7,5)


Brute force: check all pairs and evaluate if it satisfies the criteria of inversions.

long long cnt = 0;
for(int i = 1; i < n; i++){
    for(int j = 0; j < i; j++){
        if(arr[j] > arr[i]) cnt++;
    }
}

return cnt;

TC: O(n^2)
SC: O(1)



-------------------------------------------------------

Better solution:

If we are trying to optimise the above n^2 solution, then we are essentialy looking towards O(n) or O(nlogn) solution 

FYI : n <= 1e5

If we break the input arr into 2 parts & get the count of inversions in both 
arr[] = {7, 2, 3, 3, 1, 5}

{7, 2, 3,} {3, 1, 5}
(7,2), (7,3)  + (3,1). = 3 inversions 

if we have both the arrays sorted after the recursion call its going to look something like
{2,3,7} {1,3,5}
Now the no of inversion in combining these 2 arrays will be 


I will merge this 2 sorted arrays to create a final sorted array . FOr that I will take 2 pointers left= lo, right = m + 1
and will start comparing 

left       right
{2, 3, 7}  {1, 3, 5}
lo.    m   m+1.   hi

1 < 2 -- yes so all the elements after 2 will also be lower than 1 -- got 3 inversions (2,1), (3,1), (7,1)

left          right
{2, 3, 7}  {1, 3, 5}
temp: <1>

2 < 3 -- yes

   left       right
{2, 3, 7}  {1, 3, 5}
temp: <1,2>

3<=3 -- yes 

      left    right
{2, 3, 7}  {1, 3, 5}
temp: <1,2,3>

3 <  7 -- yes -- so all the elements including 7 and after 7 will also be greater than 3 - found 1 inversion (7,3)

      left       right
{2, 3, 7}  {1, 3, 5}
temp: <1,2,3,3>

5 < 7 -- yes -- so all the elements including 7 and after 7 will also be greater than 5 - found 1 inversion (7,5)


      left          right
{2, 3, 7}  {1, 3, 5}
temp: <1,2,3,3,5>

temp: <1,2,3,3,5,7>
now copy the elements from temp to arr 


long long mergeTwoSortedArrays(vector<int> &arr, int lo, int m, int hi){
    vector<int> temp;
    long long cnt = 0;
    int left = lo, right = m + 1;

    // we will run the loop until one of them is exhausted and then copy the remaining elements from the left or right arr
    while(left <= m  &&  right <= hi){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            cnt += (m - left + 1);
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

    // imp: copy the elements back to arr from temp -- temp is 0 based, whereas arr[lo..hi]
    for(int i = lo; i<= hi; i++){
        arr[i] = temp[i-lo];
    }

    return cnt;
}

// helper functoin to count the no of inversions in arr[lo..hi]
long long helper(vector<int> &arr, int lo, int hi){
    if(lo >= hi) return 0;      // single or empty arr -- no inversion
    // arr[lo .. m]
    // arr[m+1..hi]
    int m = (lo + hi) / 2;
    long long cnt = 0;
    cnt += helper(arr, lo, m);
    cnt += helper(arr, m + 1, hi);
    cnt += mergeTwoSortedArrays(arr, lo, m, hi);

    return cnt;
}

long long getInversions(long long *arr, int n){
    return helper(arr, 0, n - 1);
}

Time Complexity: at each stage we are breaking our array into 2 halves -- so this is going to be log2n
and then the merge operation which will take around O(n) time 
so TC becomes O(n * logn)

SC: O(n) + O(log2n) -- recursive stack space (in worst case the depth of the recursion tree will be O(log2n))
 for temp array used during the merge operation. Apart from this we are not using any extra space. We are just playing aroung with the indexes, not actually dividing the array.

