class Solution {
public:
     long long t[100002][2];
    
     long long solve(vector<int>& a, int i, int f){
        if (i>=a.size()) return 0;
        
        if (t[i][f] != -1) return t[i][f];
        
        long long s1 =0;
        if (f==0){
            s1 = a[i] + solve(a,i+1,f^1);
        }else{
            s1 = -a[i] + solve(a,i+1,f^1);
        }
        
        long long s2 = solve(a,i+1,f);
        
        return t[i][f] = max(s1,s2);
    }
    long long maxAlternatingSum(vector<int>& a) {
        memset(t,-1,sizeof(t));
        return solve(a,0,0);
        
    }
};

// Now depending on if we are considering picking the current element & if it an even index eleement of our subsequence, we will add that element or if it's an odd index element, we will subtract that element
// If we are considering dropping the current element, just move on to the next one 
// In order to find out the if the current element is an even or odd index element, we will use a flag. flag 0 means it's an even index element and 1 means odd index element in our subsequence

// Recurrence relation
// solve(i,f)
// flag 0 means it's an even index element of our subsequence 
// flag 1 means it's an odd index element of our subsequence
// If I pick current index, now depending on f(flag) value if it is 0, then we will add a[i], if it is 1 we will subtract a[i]
//     if(f==0) 
//         a[i] + solve(i+1, f^1)
//     else 
//         -a[i] + solve(i+1, f^1)

// If I ignore current index - just call i+1 with the same flag value because we haven't considered the current flag
    // solve(i+1,f)
