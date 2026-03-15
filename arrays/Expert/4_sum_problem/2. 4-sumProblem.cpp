Extremely Brute Force 

generate all quadruplets 

set<vector<int>> ans;               // ans set to keep track of unique quaduplets

for(int i = 0; i <n ;i++){
    for(int j = i+1; j<n; j++){
        for(int k = j+1; k < n; k++){
            for(int l = k+1; l < n; l++){
                // could have written the sum in a single line as well -- but we dont want to exceed the integer limit
                long long sum = arr[i] + arr[j];
                sum += arr[k];
                sum += arr[l];      
                // this is one of my quads
                if(sum == target){
                    vector<int> temp = {arr[i],arr[j], arr[l], arr[r]};
                    sort(temp.begin(), temp.end());
                    ans.insert(temp);
                }
            }
        }
    }
}

vector<vector<int>> res(ans.begin(), ans.end());

return ans;

TC: O(n^4)
SC: O(num_of_unique_quads) for the set
// NOTE: if you write long long sum = arr[i] + arr[j] + arr[k] + arr[l], this might exceed the integer limit and the typecasting would fail
// the way this is computed is long long sum = arr[i] + arr[j] + arr[k] + arr[l]. -- first the sum is calculated and then the value is typecasted into long long
// But we need to make sure that while the sum is being calculated, it does not cross the integer limit 


----------------------------------------------------------------------------
Better solution

can probably bring down the complexity to O(n^3) by using hashing. IN order to acheive this we need to trim down the last for loop.

I can run 3 loops and will lookup the 4th value in the arr. This can be efficiently done using hashsets

In the 3 sum, we kept i and j constant and inserted everything between them into a set {0,1,2,-1} 
arr[] = {-1, 0, 1, 2, -1, 4}
          i.              j            

Similarly here we will keep i,j,l constant and insert everthign between j and l into the set (this will be my potential 4th value)
arr[] = {-1, 0, 1, 2, -1, 4} & target = 0
         i.  j.  l
elements = {}
target - (arr[i] + arr[j] + arr[l]) = 0 - (-1+0+1) =  0
does 0 exist in the set? No 

arr[] = {-1, 0, 1, 2, -1, 4}
         i.  j.    l
elements = {1}
target - (arr[i] + arr[j] + arr[l]) = 0 - (-1+0+2) =  -1
does -1 exist in the set? No 

arr[] = {-1, 0, 1, 2, -1, 4}
         i.  j.        l
elements = {1,2}
target - (arr[i] + arr[j] + arr[l]) = 0 - (-1+0-1) =  2
does 2 exist in the set? Yes -- found 1 quad {-1,0,2,-1} ==> sort this {-1,-1,0,2} and store it into the ans set 

arr[] = {-1, 0, 1, 2, -1, 4}
         i.  j.           l
elements = {1,2,-1}
target - (arr[i] + arr[j] + arr[l]) = 0 - (-1+0+4) =  -3
does -3 exist in the set? No 

clear the set 

arr[] = {-1, 0, 1, 2, -1, 4}
         i.     j. l
elements = {}
target - (arr[i] + arr[j] + arr[l]) = 0 - (-1+1+2) =  -2
does -2 exist in the set? No 

arr[] = {-1, 0, 1, 2, -1, 4}
         i.     j.     l
elements = {2}
target - (arr[i] + arr[j] + arr[l]) = 0 - (-1+1-1) =  1
does 1 exist in the set? No 

arr[] = {-1, 0, 1, 2, -1, 4}
         i.     j.        l
elements = {2,-1}
target - (arr[i] + arr[j] + arr[l]) = 0 - (-1+1+4) =  -4
does -4 exist in the set? No 


Essentially We are only looking for the 4th value between j and k. 

But why not look into the entire array 
for ex: arr = {1, 2, -1, -2, 2, 0, -1}
               i.     j.        k
            fourth_val = 0 - (1 - 1 + 0)= 0
            and if you look for 0 you will end up using kth 0 which is incorrect because (i != j != k != l) of this constraint 
            Thus it is important that you only look for the 4th value between j and k

Initially i,j,k will be placed like this & hashset = {}
arr = {1, 2, -1, -2, 2, 0, -1}
       i. j.  k

hashset = {-1}
arr = {1, 2, -1, -2, 2, 0, -1}
       i. j.      k

hashset = {-1,-2}
arr = {1, 2, -1, -2, 2, 0, -1}
       i. j.         k

and so on and so forth 


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        int n = arr.size();

        set<vector<int>> ans;               // ans set to keep track of unique quaduplets
        
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                set<long long> hashset;
                for(int k = j+1; k < n; k++){
                    // we are looking for val = target - (arr[i] + arr[j] + arr[l])
                    long long tripletSum = arr[i] + arr[j];             // wrote the sum in 2 lines to make sure that the sum doesnt exceed integer limits
                    tripletSum +=  arr[k]; 
                    // this will be my 4th value
                    long long fourth = target - tripletSum;
                    // found 1 quad
                    if(hashset.count(fourth)){
                        vector<int> temp = {arr[i], arr[j], arr[k], (int)fourth};   // make sure to typecast fourth bcoz vector is of type integer
                        sort(temp.begin(), temp.end());
                        ans.insert(temp);
                    }

                    hashset.insert(arr[k]);
                }
            }
        }

        vector<vector<int>> res(ans.begin(), ans.end());

        return res;
    }
};

TC: O(n^3 * logn)
SC: O(n) for hashset + O(num_of_unique_quads * 2) for ans set and res vector 

Interviewer will not be happy with 2 things:
1st we are using the hashset to look for the 4th value 
2nd we are using a set to keep track of unique quads

-----------------------------------------------------------------------------

Optimal Solution -- tracking the duplicates without any extra space & TC of O(n^3)

If we sort the array then we can use the 2 pointer technique to look for the target sum 
arr = {1, 2, -1, -2, 2, 0, -1}

After sorting 
arr = {-2, -1, -1, 0, 1, 2, 2}
        i.  j. l            r
        
        long long sum = arr[i] + arr[j];
        sum += arr[l];
        sum += arr[r];
        if(sum == target) -- found 1 quad 
        else if (sum < target) -- we need to increase the sum so do l++ 
        else -- we need to decrese the sum so do r--
        
        Essentially we are replacing the 3rd loop in the hashing solution with the 2pointer loop l & r 
        Now in order to get rid of ans set -- since we know that the array is sorted, we will skip processing the duplicate elements for arr[l],arr[r],arr[j],arr[i]


target = 8
arr = [1,1,1,2,2,2,3,3,3,4,4,4,5,5]
       i j k                     l
(1 + 1 + 1 + 5 == 8) yes -- {1,1,1,5}

arr = [1,1,1,2,2,2,3,3,3,4,4,4,5,5]
       i j   k                 l
    shall I take this 5 is my question?
    I have already used 5 to get an answer. When I used 5 I required 1, so I know one thing for sure, if I use this 5 and 2 I will never get an answer because for 5 I require 1.
    So there is no point in using this 5 
Therefore I will try to avoid the duplicates 

arr = [1,1,1,2,2,2,3,3,3,4,4,4,5,5]
       i j   k               l
(1+ 1+2+4 == 8) yes. -{1,1,2,4}

arr = [1,1,1,2,2,2,3,3,3,4,4,4,5,5]
       i j     k           l
to avoid getting the same quad I will keep on incrementing k until arr[k] == arr[k-1]
and decrementing l until arr[l] == arr[l+1]

arr = [1,1,1,2,2,2,3,3,3,4,4,4,5,5]
       i j         k   l
(1+1+3+3 == 8) yes - {1,1,3,3}

arr = [1,1,1,2,2,2,3,3,3,4,4,4,5,5]
       i j             l k

arr = [1,1,1,2,2,2,3,3,3,4,4,4,5,5]
       i   j k                   l
I have already processed 1,1 at i,j so there is no point in processing them again 
so keep on incrementing j unitl arr[j] == arr[j-1]

arr = [1,1,1,2,2,2,3,3,3,4,4,4,5,5]
       i     j k                 l
arr = [1,1,1,2,2,2,3,3,3,4,4,4,5,5]
       i     j k               l
arr = [1,1,1,2,2,2,3,3,3,4,4,4,5,5]
       i     j k             l
arr = [1,1,1,2,2,2,3,3,3,4,4,4,5,5]
       i     j k           l
arr = [1,1,1,2,2,2,3,3,3,4,4,4,5,5]
       i     j k         l
arr = [1,1,1,2,2,2,3,3,3,4,4,4,5,5]
       i     j k       l
(1+2+2+3 == 8). -{1,2,2,3}

arr = [1,1,1,2,2,2,3,3,3,4,4,4,5,5]
       i     j   k   l
again to avoid duplicate quads keep on increasing k and decreasing l until arr[k] == arr[k-1] and arr[r] == arr[r+1]

arr = [1,1,1,2,2,2,3,3,3,4,4,4,5,5]
       i     j   l k 

arr = [1,1,1,2,2,2,3,3,3,4,4,4,5,5]
       i       j k                l  

To avoid processing the same j, keep on incrementing j until arr[j] == arr[j-1]
arr = [1,1,1,2,2,2,3,3,3,4,4,4,5,5]
       i           j k           l

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> res;
        // 2 nested for loops + 2pointer
        sort(arr.begin(), arr.end());
        // [-2,-1,0,0,1,2]
        for(int i = 0; i < n;  ){
            for(int j = i + 1; j < n;  ){
                long long x = arr[i] + arr[j];
                int l = j + 1, r = n - 1;
                while(l < r){
                    long long tempSum = arr[l] + arr[r];
                    if(tempSum == target - x){
                        res.push_back({arr[i],arr[j],arr[l],arr[r]});
                        l++; 
                        r--;
                        while(l < r && arr[l] == arr[l-1]) l++;     // skip duplicates of arr[l]
                        while(l < r && arr[r] == arr[r+1]) r--;     // skip duplicates of arr[r]
                    } 
                    else if(tempSum < target - x){
                        l++;
                    }
                    else{
                        r--;
                    }   
                }
                j++;
                while(j < n && arr[j] == arr[j-1]) j++;             // skip duplicates of arr[j]
            }
            i++;
            while(i < n && arr[i] == arr[i-1]) i++;             // skip duplicates of arr[j]
        }

        return res;
    }
};

TC: O(n^3) + O(nlogn) for 2 nested for and 1 nested while loop 
SC: O(1) -- not using any extra space apart from the res[]