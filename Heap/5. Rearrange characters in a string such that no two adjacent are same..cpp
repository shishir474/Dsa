767. Reorganize String(Rearrange characters in a string such that no two adjacent are same.)

Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.
Example 1:

Input: s = "aab"
Output: "aba"
Example 2:

Input: s = "aaab"
Output: ""
 

Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.



SOlUTION:
PICK top two most frequent characters, add them to ans, again push them into priority queue after decreasing their freq by 1(OFFCOURSE IF FREQ BECOMES 0 DONT PUSH)
CONTINUE THIS PROCESS UNTIL PQ.SIZE()>1;
noW iF PQ.SIZE==1 CHECK PQ.TOP CHAR FREQ SHOULD BE 1 THEN ONLY IT CAN BE ADDED OTHERWIESE ANS NOT POSSIBLE

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> mp;
        int maxf = INT_MIN;
        for (int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        
        priority_queue<pair<int,char>> pq;
        for (auto it = mp.begin();it!=mp.end();it++){
            pq.push({it->second, it->first});
        }
                
        string ans="";
        while (pq.size()>1){
            int n1 = pq.top().first;
            char c1 = pq.top().second;
            pq.pop();
            int n2 = pq.top().first;
            char c2 = pq.top().second;
            pq.pop();
            
            ans+=c1;
            ans+=c2;
            n1--;
            n2--;
            if (n1!=0){
                pq.push({n1,c1});
            }
            if (n2!=0){
                pq.push({n2,c2});
            }
       
        }
        if (!pq.empty()){
            if (pq.top().first > 1){ // there is no other char to seperate the last char
                return "";
            }
            ans+=pq.top().second;
        }
     
        return ans;
        
        


    }
};