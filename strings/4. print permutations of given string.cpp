Time complexity: O(N! * N) +O(N! Log N!)
Reason:  The recursion takes O(N!)  time because we generate every possible permutation and another O(N)  time is required to make a deep copy and store every sequence in the data structure. Also, O(N! Log N!)  time required to sort the data structure. The factorial are not generated in a sorted order, that’s why we need to sort the vector
Space complexity: O(N) 
Reason: Result stored in a vector, we are auxiliary space taken by recursion

void solve(int idx, string s, vector<string>& res){
    if(idx==s.length()-1){
        res.push_back(s); return;
    }
    
    for(int i=idx;i<s.length();i++){
        swap(s[i],s[idx]);
        solve(idx+1,s,res);
        swap(s[i],s[idx]);
    }
}

vector<string>find_permutation(string s)
{
    vector<string> res;
    solve(0,s,res);
    sort(res.begin(),res.end());
    return res;
    
}





// solution2

If we need to print unique permutations only
// For strings with duplicates s: AABB -> 6 permutations
	void solve(map<char,int>& mp,string& ans,vector<string>& res,int n){
    	  if (ans.length()==n){
    	      res.push_back(ans); return;
    	  }
    	  for(auto it=mp.begin();it!=mp.end();it++){
    	      if (it->second > 0){
    	          ans.push_back(it->first); 
    	          it->second--;
    	          solve(mp,ans,res,n);
    	          it->second++;
    	          ans.pop_back();
    	      }
    	  }
    	  
	}
	
	
		vector<string>find_permutation(string s)
		{
		    map<char,int> mp;
		    
		    for(int i=0;i<s.length();i++) mp[s[i]]++;
		      
		    vector<string> res;
		    string ans="";
		    solve(mp,ans,res,s.length());
		    return res;
		    
		}

