Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
Output: ["cats and dog","cat sand dog"]

class Solution {
public:
    vector<string> solve(string s, int i, set<string>& set, map<int,vector<string> >& mp){
        if (i>=s.length()){
            vector<string> ans(1);
            ans[0]="";
            return ans;
        }
        if (mp.count(i)) return mp[i];


        vector<string> ans;

        for(int j=i;j<s.length();j++){
           if (set.count(s.substr(i,j-i+1))){

                vector<string> v = solve(s,j+1,set,mp);

                if (v.size() > 0){
                    string temp = s.substr(i,j-i+1);
                    for(int k=0;k<v.size();k++){
                        if (v[k].size() > 0){  
                            string p = temp + " " + v[k];
                            ans.push_back(p);
                        }
                        else{ans.push_back(temp); }
                    }
                }


            }
        }

        return mp[i] = ans;
    }

    vector<string> wordBreak(string A, vector<string>& B) {
            map<int, vector<string> > mp;
        set<string> set;
        for(int i=0;i<B.size();i++) set.insert(B[i]);
        return solve(A,0,set,mp);
    }
};