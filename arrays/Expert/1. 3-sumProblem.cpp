3 sum problem

Find out all the triplets that sum up to 0

arr[i] + arr[j] + arr[k] = 0  (i != j != k)

You have to return all the unique triplets

arr[] = {-1,0,1,2a,2b,-1,-4}
ex: [-1,-1,2a] is same as [-1,2b,-1]. (ensure that ans set only contains unique triplets)

brute  -- better -- optimal

Extremely brute force 

set<vector<int>> ans;       // this will store all your triplets

for(int i = 0; i < n;  i++){
    for(int j = i+1; j < n;  j++){
        for(int k = j + 1; k < n; k++){
            if(arr[i] + arr[j] + arr[k] == 0){
                vector<int> temp = {arr[i],arr[j],arr[k]}
                sort(temp.begin(), temp.end());
                // insert this triplet -- no need to check if this triplets exists because set always stores unique (once you have sorted [-1,-1,2] & [-1,2,-1] both  represents the same [-1,-1,2])
                ans.insert(temp);
            }
        }
    }
}

vector<vector<int>> res(ans.begin(), ans.end());
return res;

TC: O(n^3 * log(num_of_unique_triplets))

Will I consider time for sorting -- NO we should not. its hardly 3 elements & the time will be constant
But inserting the triplet is O(log(num_of_unique_triplets)) if we are using an set.
Can bring this down to O(1) if we use unordered_set 

SC: O(num_of_unique_triplets)

----------------------------------------------------------------------------------------------------------------------------

-- Strivers better solution. using hashing 

In order to optimise the n^3, we will somehow need to eliminate the 3rd loop 

arr[i] + arr[j] + arr[k] = 0
arr[k] = -(arr[i] + arr[j])
& the best way to look for arr[k] in the array is hashing (using this you could do this in logn or constant time)

          0 1 2 3  4  5
arr[] = {-1,0,1,2,-1,-4}
          
elements = {}
i=0,j=1 looking for -(-1+0) = 1
is 1 present in the elements set? No its not 
Insert arr[j] into elements set 

elements = {0}
i=0,j=2 looking for -(-1+1) = 0
is 0 present in the elements set? Yes it is -- found a triplet(-1,0,1) sorting it (-1,0,1) and store in ans  = {[-1,0,1]}
Insert arr[j] into elements set 

elements = {0,1}
i=0,j=3 looking for -(-1+2) = 1
is -1 present in the elements set? No its not
Insert arr[j] into elements set 

elements = {0,1,2}
i=0,j=4 looking for -(-1-1) = 2
is 2 present in the elements set? Yes it is -- found a triplet(-1,-1,2) sorting it (-1,-1,2) and store in ans  = {[-1,0,1], [-1,-1,2]}
Insert arr[j] into elements set

elements = {0,1,2,-1}
i=0,j=5 looking for -(-1-4) = 5
is 5 present in the elements set? No its not
Insert arr[j] into elements set

elements = {0,1,2,-1,-4}
i=0,j=6 j is exhausted 

clear the elements set
elemetns = {}, ans = {[-1,0,1], [-1,-1,2]}
i=1, j=2 looking for -(0 + 1) = -1
is -1 present in the elements set? No its not
Insert arr[j] into elements set 

elements = {1}
i=1, j=3 looking for -(0 + 2) = -2
is -2 present in the elements set? No its not
Insert arr[j] into elements set 

elements = {1,2}
i=1, j=4 looking for -(0 - 1) = 1
is 1 present in the elements set? yes it is {0,1,-1} sorting it {-1,0,1} -- this already exists in ans set 
Insert arr[j] into elements set 

elements = {1,2,-1}
i=1, j=5 looking for -(0 - 4) = 4
is 4 present in the elements set? No its not
Insert arr[j] into elements set 

clear the elemetns set 
elements = {}
i = 2, j = 3 looking for -(1 + 2) = -3
is -3 present in the elements set? No its not
Insert arr[j] into elements set 

elements = {2}
i = 2, j = 4 looking for -(1 - 1) = 0
is 0 present in the elements set? No its not
Insert arr[j] into elements set 




set<vector<int>> ans;           // ans set ensures that we store only unique triplets. Before storing the triplet sort it and then store

for(int i = 0; i< n; i++){
    set<int> hashset;
    for(int j = i+1; j < n; j++){
        if(hashset.count(-(arr[i] + arr[j]))){
            vector<int> temp = {arr[i], arr[j], -(arr[i] + arr[j])};
            sort(temp.begin(), temp.end());                     // sorting the temp vector ensures we only store unique triplets in set
            ans.insert(temp);           
        }
        hashset.insert(arr[j]);
    }
}

vector<vector<int>> res(ans.begin(), ans.end());
return res;

TC: O(n^2 * logn) if using an ordered_set. If we use an unordered_set, then the tc reduces to O(n^2)
SC: O(n) for elements set and O(num_of_unique_triplets * 2) for ans set and res vector



-------------------------------------------------------------------------------------------------------



brute:
why not try out all the triplets and we will store all those which gives sum 0.
For uniqueness we can use a set to make sure that triplets are unique
or instead adjust the uniqueness within the for loops itself ( this is better )

3 nested for loops 

vector<vector<int>> res;

sort(arr.begin(), arr.end());   // in order to bring the equivalent elements together I need to sort the array

// [-4,-1,-1,0,1,2]
for(int i = 0; i < n;  ){
    cout<<"i "<<i<<" ";
    for(int j = i+1; j < n;  ){
        cout<<"j "<<j<<" ";
        for(int k = j + 1; k < n;  ){
            cout<<"k "<<k<<" ";
            if(arr[i] + arr[j] + arr[k] == 0){
                res.push_back({arr[i],arr[j],arr[k]});
            }
            int val = arr[k];
            while(k < n and val == arr[k]) k++;
        }
        int valj = arr[j];
        while(j < n  and valj == arr[j]) j++;
    }
    int vali = arr[i];
    while(i < n and vali == arr[i]) i++;
}

return res;

TC: O(n^3) + O(nlogn)
SC: O(1)


-------------------------------------------------------------------
Optimal solution  

NOTE: The way we were keeping track of triplets uniqueness was using sets, but each time we found a triplet, we used to sort it and then store it in the hashset.
If you dont sort the triplet you will endup with duplicates

ex: [-1,2,-1] first triplet 
If you dont sort ans = {[-1,2,-1]}
then later you got [-1,-1,2]
and if you try to store this again, it will be inserted in your hashset because hashset treats [-1,2-1] & [-1,-1,2] different
Hence its crucial that you sort triplets and then store 

** Interviewer might not be happy with the extra space and here's where you will explain the below solution.
Now instead of sorting the triplets each time, I will sort the input array. This will allow me to get rid of the extra space for set which we used for keeping track of unique triplets 


Algorithm will follow the 2pointer approach :

after sorting arr will look something like 
arr[] = {-2, -2, -2, -1, -1, -1, 0, 0, 0, 2, 2, 2, 2}
          i.  j                                    k

I know onething for sure, arr is sorted. Initially i = 0, j = 1, and k = n-1 
in order to arr[i] + arr[j] + arr[k] == 0
if arr[j] + arr[k] < -arr[i] --> I will need to increase j to increse my (arr[j] + arr[k]) sum 
else if arr[j] + arr[k] > -arr[i]. --> I will need to decrease my sum so decrease k 


sorting + 2 nested for loops  

vector<vector<int>> res;

sort(arr.begin(), arr.end());   // in order to bring the equivalent elements together I need to sort the array
// also the below 2 pointer technique only works in case the array is sorted

// [-4,-1,-1,0,1,2]
for(int i = 0; i < n; ){
    int j = i+1, k = n-1;
    while(j < k){
        if(arr[i] + arr[j] + arr[k] == 0){
            res.push_back({arr[i], arr[j], arr[k]});
            // this ensures that we are only checking unique triplets
            j++;
            k--;
            while(j < k and arr[j] == arr[j-1]) j++;                // skipping duplicates of arr[j]
            while(j < k and arr[k] == arr[k+1]) k--;                // skipping duplicates of arr[k]
        }
        else if(arr[j] + arr[k] < -arr[i]){ // sum < X -- need to increase the sum
            j++;
        }
        else{       // sum is greater --- need to decrease the sum 
            k--;
        }
    }
    i++;                      // skipping duplicates of arr[i]
    while(i < n and arr[i] == arr[i-1]) i++;
}

return res;

TC: O(nlogn) + O(n^2)
SC: O(1) -- not using any extra space apart from the res[]


NOTE: If you dont sort the array, there is no way you will be able to skip the duplicates without using any extra space. Then you will need to use a set to keep track of the triplets
Sorting gives us the advantage to skip the duplicate elements in the list 

If you are using a set to track unique triplets, sort the triplets before storing it in sets 
----------------------------------