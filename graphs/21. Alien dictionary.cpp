Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.
Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.
 

Example 1:

Input: 
N = 5, K = 4
dict = {"baa","abcd","abca","cab","cad"}
Output:
1
Explanation:
Here order of characters is 
'b', 'd', 'a', 'c' Note that words are sorted 
and in the given language "baa" comes before 
"abcd", therefore 'b' is before 'a' in output.
Similarly we can find other orders.
Example 2:

Input: 
N = 3, K = 3
dict = {"caa","aaa","aab"}
Output:
1
Explanation:
Here order of characters is
'c', 'a', 'b' Note that words are sorted
and in the given language "caa" comes before
"aaa", therefore 'c' is before 'a' in output.
Similarly we can find other orders.


Expected Time Complexity: O(N * |S| + K) , where |S| denotes length of the longest string.
Expected Space Compelxity: O(K)


class Solution{
    public:
    
    void dfs(int sv, vector<int> adj[],  vector<int>& vis, stack<int>& s ){
        vis[sv] = true;
        for(int it: adj[sv]){
            if(!vis[it]){
                dfs(it,adj,vis,s);
            }
        }
        s.push(sv);
    }
    
    
    string findOrder(string dict[], int N, int k) {
        //code here
        // we are given k starting alphabets only so adj list size is k
        vector<int> adj[k];
        
        for(int i=0;i<N-1;i++){
            string s=dict[i], t=dict[i+1];
            
            int n=s.length(), m=t.length();
             
            for(int j=0;j<min(n,m); j++)
            {
                if(s[j]!=t[j]){
                    adj[s[j]-'a'].push_back(t[j]-'a');
                    break;
                }
            }
            
        }
        
        
        stack<int> s;
        
        // k starting alphabets are given in i/p
        vector<int> vis(k,0);
        
        for(int i=0;i<k;i++){
            if(!vis[i]){
                dfs(i,adj,vis,s);
            }
        }
        
        string res="";
        
        while(!s.empty()){
            res.push_back(s.top()+'a');
            s.pop();
        }
        
        return res;
    }