// void solve(string s, int i, int par, int& ans, vector<string>& temp){
//     if (i>=s.length()){
//         if (temp.size() == par){
//             // evaluate cost;
//             int cost = 0;
//             for(int j=0;j<temp.size();j++){
//                 int w=0;
//                 for(int p=0;p<temp[j].length();p++){
//                     if(temp[j][p] == 'W') w++;
//                 }
//                 cost += w*(temp[j].size()-w);
//             }

//             ans = min(ans, cost);
//         }
//         return;
//     }

//     for(int k=i;k<s.length();k++){
//         if (temp.size() < k){
//             temp.push_back(s.substr(i,k-i+1)); // s[i..k]
//             solve(s,k+1,par,ans,temp);
//             temp.pop_back();
//         }
//     }


// }
int findCost(string s){
    int wt=0;
    for(int k=0;k<s.length();k++){
        if (s[k]=='W')wt++;
    }

    return wt*(s.length()-wt);
}


int solve(string s, int i, int par, vector<vector<int> >& t){
    if (i>=s.length()) return 0;
    if (par==1){
        // evaluate cost for s;
        return findCost(s.substr(i));
    }
    if (t[i][par] !=-1) return t[i][par];

    int ans=INT_MAX;
    for(int k=i;k<s.length();k++){
        cout<<findCost(s.substr(i,k-i+1))<<" "<<solve(s,k+1,par-1,t)<<endl;
        int tans =  findCost(s.substr(i,k-i+1)) + solve(s,k+1,par-1,t);
     
        ans = min(ans, tans);
    }

    return t[i][par] = ans;
}

int Solution::arrange(string A, int B) {
    int n=A.length();
    if (n==B) return 0;
    if(B > n) return -1;

    int ans=INT_MAX;
    vector<vector<int> > t(n+1,vector<int> (B+1, -1));

    return solve(A,0,B,t);
    
    // similar to palindrome partitioning II problem of leetcode 
}
