DIVIDE AND CONQUER PROBLEM

Given a sequence of N (1 ≤ N ≤ 34) numbers S1, ..., SN (-20,000,000 ≤ Si ≤ 20,000,000), determine how many subsets of S (including the empty one) have a sum between A and B (-500,000,000 ≤ A ≤ B ≤ 500,000,000), inclusive.

Input
The first line of standard input contains the three integers N, A, and B. The following N lines contain S1 through SN, in order.

Output
Print a single integer to standard output representing the number of subsets satisfying the above property. Note that the answer may overflow a 32-bit integer.

solution:
Brute force to generate all subsequecnes TLE, N<=34
But if we use divide and conquer sapproach then we can determine the subsequences sum
Find the subset sums that are possible(dp wala sol subset sum ka kaam nhi krega coz sum bahut bada hoga toh utne size ka table nhi declare kr payoge)
Use the brute force way of storing the subsequence wala tareka
Get the subsequence for both the halfs and then sort any one array and iterate over other to determine the count of subsequences. that have sum betwen a and b;



#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll getsubsequence(ll temp[], ll n, ll output[]){

if (n==0){
    output[0] = 0;
    return 1;
 }
 
 ll size = getsubsequence(temp+1, n-1, output);
 for (int i=0;i<size;i++){
     output[i+size] = temp[0] + output[i];
 }
 
 return 2*size;
}

int main(){
    ll n, a, b;
    cin>>n>>a>>b;
    ll arr[n];
    for (int i=0;i<n;i++) cin>>arr[i];
    
    ll temp1[n/2], temp2[n-n/2];
    ll k=0;
    for (int i=0;i<n/2;i++){
        temp1[i] = arr[k++];
    }
    
   
    for (int i=0;i<(n-(n/2)) ;i++){
        temp2[i] = arr[k++];
    }

    
    ll v1[1<<(n/2)], v2[1<<(n-(n/2))];
    ll size1 = getsubsequence(temp1, n/2, v1);
    ll size2 = getsubsequence(temp2, n-(n/2), v2);
    
    sort(v2, v2+size2);
    
    
    
    ll c=0;
 
    
    for (int i=0;i<size1;i++){
        ll indx1 = lower_bound(v2, v2+size2, a-v1[i]) - v2;
        ll indx2 = upper_bound(v2, v2+size2, b-v1[i]) - v2;
        c+=(indx2 - indx1);
    }
    
    cout<<c<<"\n";
    
    
    
}