// Greedy Problem

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // greedy approach
        sort(g.begin(), g.end());
        multiset<int> ms(s.begin(), s.end());

        int cnt = 0;
        for(int i=0;i<g.size();i++){
            auto it = lower_bound(ms.begin(), ms.end(), g[i]);
            if(it != ms.end()){
                cnt++; 
                ms.erase(it);
            }
        }
        return cnt;
    }
};

TC: O(nlogn) + O(nlogn)
SC: O(n)
// TLE 21/25 pass

----------------------------------------------------------------

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // greedy approach
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        // Take 2 pointers: Keep on updating the jth pointer until s[j] < g[i]
        int j = 0, cnt = 0;
        for(int i = 0; i < g.size(); i++){
            while(j < s.size() and s[j] < g[i]) j++;
            if(j == s.size()) break;
            cnt++; j++;
        }

        return cnt;
    }
};

TC: O(nlogn) + O(mlogm) + O(n+m)
SC: O(1). -- no extra space used just 2 pointers i and j 
// Accepted

----------------------------------------------------------------

class Solution {
public:
// took two pointers i for cookies and j for greedy.
// Idea is to iterate over cookies, if you are able to satisfy the greed of g[j], increment cnt and j = j+1 (move to next child)
// if not, just move to the next cookie
// added j < g.size() just to make sure that don't access out of bounds for g[]
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int i = 0, j = 0;   // i --> s and j --> g
        while(i < s.size() and j < g.size()){
            if(s[i] >= g[j]){
                j++;
            }
            i++;
        }
        return j;               // dont need to maintain cnt. return j (that's what your ans will be)
    }
};

TC: O(nlogn) + O(mlogm) + O(n+m)
SC: O(1). -- no extra space used just 2 pointers i and j 

// fastest solution (runtime)
// Accepted