You are given a string S of 2N characters consisting of N ‘[‘ brackets and N ‘]’ brackets. A string is considered balanced if it can be represented in the for S2[S1] where S1 and S2 are balanced strings. We can make an unbalanced string balanced by swapping adjacent characters. Calculate the minimum number of swaps necessary to make a string balanced.
Note - Strings S1 and S2 can be empty.

You have to return the minimum number of swaps required to make string balanaced. You can swao only adjacent characters
 

Example 1:

Input  : []][][
Output : 2
Explanation :
First swap: Position 3 and 4
[][]][
Second swap: Position 5 and 6
[][][]

 

Example 2:

Input : [[][]]
Output : 0 
Explanation:
String is already balanced.
 

vector<int> v;
for (int i=0;i<S.length();i++){
    if (S[i] == '[') v.push_back(i);
}
// idx is used for iterating over v.. v[idx] stores the index of the next opening bracket
int ans=0, idx = 0, count = 0;
for (int i=0;i<S.length();i++){
    if (S[i] == '['){
        count++;
        idx++;
    }
    else{
        count--;
        if (count < 0){
            // imbalance state: fault bracket
            ans+=(v[idx] - i);  // no. of swaps
            swap(S[i], S[v[idx]]);
            count = 1;
            idx++; // have utilized opening bracket of that index so move idx ahead
        }
    }
}

return ans;


