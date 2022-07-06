Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]







class Solution {
public:        
    vector<string> solve(string s, map<char,vector<string> >& mp){
        if (s.length()==1){
            return mp[s[0]];    
        }
        vector<string> v = solve(s.substr(1), mp);
        vector<string> nv;
        
        for(int i=0;i<mp[s[0]].size();i++){
            string t = mp[s[0]][i];
            for(int j=0;j<v.size();j++){
                nv.push_back(t+v[j]);
            }        
        }
        
        return nv;
    }
    
    vector<string> letterCombinations(string digits) {
        
        if (digits.length()==0) return {};
        
        map<char,vector<string> > mp;
        mp['2'] = {"a","b","c"};
        mp['3'] = {"d","e","f"};
        mp['4'] = {"g","h","i"};
        mp['5'] = {"j","k","l"};       
        mp['6'] = {"m","n","o"};
        mp['7'] = {"p","q","r","s"};
        mp['8'] = {"t","u","v"};
        mp['9'] = {"w","x","y","z"};
        
        return solve(digits,mp);
      

        
    }
};