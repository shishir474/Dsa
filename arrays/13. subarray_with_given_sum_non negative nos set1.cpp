//   Given an unsorted array A of size N that contains only non-negative integers, find a continuous sub-array which adds to a given number S.
// In case of multiple subarrays, return the subarray which comes first on moving from left to right.
// N = 5, S = 12
// A[] = {1,2,3,7,5}
// Output: 2 4

// SOlution 1: Sliding window solution
  vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
        int st=-1,end=-1;
        ll i=0,j=0,sum=0;
        while(j<n){
            sum+=arr[j];
            if (sum==s) { 
                st=i; end=j;
                break;
            }
            if(sum > s){
                while(sum > s) sum-=arr[i++];
                if (sum==s) { 
                    st=i; end=j;
                    break;
                }   
            }
            
            j++;
        }
        
        if (st==-1) return {-1};
        
        return {st+1,end+1};
    }

    // solution 2: hashmaps based solution, 

    // maintain a map<int,int> denoting prefixsum and its freq
    // if the current prefix is x, check if there exists any prefix with sum x-s, then it implies, found a subarray with given subarraySum
    // corner case: if the prefixsum==X

    // NOTE: sliding window sol. only works for non negative nos. If negative nos are present sliding window doesn't work