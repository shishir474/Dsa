
Two ﬁnite, strictly increasing, integer sequences are given. Any common integer between the two sequences constitute an intersection point. Take for example the following two sequences where intersection points are
printed in bold:

First= 3 5 7 9 20 25 30 40 55 56 57 60 62
Second= 1 4 7 11 14 25 44 47 55 57 100
You can ‘walk” over these two sequences in the following way:

You may start at the beginning of any of the two sequences. Now start moving forward.
At each intersection point, you have the choice of either continuing with the same sequence you’re currently on, or switching to the other sequence.
The objective is ﬁnding a path that produces the maximum sum of data you walked over. In the above example, the largest possible sum is 450, which is the result of adding 3, 5, 7, 9, 20, 25, 44, 47, 55, 56, 57, 60, and 62

Input
Your program will be tested on a number of test cases. Each test case will be speciﬁed on two separate lines. Each line denotes a sequence and is speciﬁed using the following format:

n v1 v2 ... vn
Where n is the length of the sequence and vi is the ith element in that sequence. Each sequence will have at least one element but no more than 10,000. All elements are between -10,000 and 10,000 (inclusive).
The last line of the input includes a single zero, which is not part of the test cases.

Output
For each test case, write on a separate line, the largest possible sum that can be produced.





Note: instructions for taking input
Run an infinite while loop for in which each testcase is handled. As soon as a 0 is obtained as the size of the array (this is the last 0 which they have mentioned is not a part of input), break out of the while loop. there are no more testcases after this




#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
 
    while (true){
        ll n;
        cin>>n;
        
        if (n==0) break;
        
        ll arr1[n];
        for (int i=0;i<n;i++) cin>>arr1[i];
        ll m;
        cin>>m;
        ll arr2[m];
        for (int i=0;i<m;i++) cin>>arr2[i];
        
        ll i=0, j=0, ans = 0, sum1=0, sum2=0;
        while (i < n && j < m){
          if (arr1[i] < arr2[j]){
              sum1+=arr1[i];
              i++;
          } 
          else if (arr2[j] < arr1[i]){
              sum2+=arr2[j];
              j++;
          }
          else{
              ans+= (max(sum1, sum2)+arr1[i]);
              sum1=0;
              sum2=0;
              i++;
              j++;
          }
        }
        
        while (i < n){
            sum1+=arr1[i];
            i++;
        }
        while (j < m){
            sum2+=arr2[j];
            j++;
        }
        
        ans+= max(sum1, sum2);
        
        cout<<ans<<"\n";
    
    }
}