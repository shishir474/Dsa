Given a string S and a string T, find the minimum window in S which will contain all the characters in T in linear time complexity.

Note that when the count of a character C in T is N, then the count of C in minimum window in S should be at least N.

Example :

S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC"

Note:

If there is no such window in S that covers all characters in T, return the empty string ''.
If there are multiple such windows, return the first occurring minimum window ( with minimum start index ).

bool isGreater(map<char,int>& mp, map<char,int>& tmp){
    for(auto it=tmp.begin();it!=tmp.end();it++){
        if (it->second > mp[it->first]) return false;
    }
    return true;
}
string Solution::minWindow(string s, string t) {
    map<char,int> tmp;
    for(int i=0;i<t.length();i++){
        tmp[t[i]]++;
    }

    string ans="";
    int len = INT_MAX;

    map<char,int> mp;
    int i=0,j=0;
    while(j<s.length()){
        mp[s[j]]++;
        if (isGreater(mp,tmp)){
            // if(j-i+1 < len){   // isko nai likhoge toh bhi chalega
            //     len = j-i+1; 
            //     ans = s.substr(i,j-i+1);
            // } 
            while(mp[s[i]] > tmp[s[i]]){
                mp[s[i]]--;
                i++;
            }
            if (j-i+1 < len){
                len = j-i+1; ans = s.substr(i,j-i+1);
            }
            
        }
        j++;
    }

    return ans;
}
