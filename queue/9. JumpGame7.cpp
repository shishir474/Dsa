// https://leetcode.com/problems/jump-game-vii/description/

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        queue<int> q;
        q.push(0);
        for (int i=1;i<s.length();i++){
            if (i > q.front()+maxJump){
                q.pop(); // pop indicating that we have gone out of bounds of q.front();
                if (q.empty()) return false; // if the queue becomes empty at any point, it means we were not able to reach any 0 in the curr range
            }
            if (s[i]=='0' and i>=q.front()+minJump and i<=q.front()+maxJump){
                q.push(i);
                if (i==s.length()-1) return true;
            }
        }

        //  "01101100" - from the second last 0 we cannot reach the last zero bcoz it does not lie in the range of its minJump and maxJump. Hence there is no way we were able to reach the last index
        return false;
        
    }
};

// TC: O(n) solution
// SC: O(n) in the worst case

// Initially wrote a O(n^2) solution, using recursion+dp, but the complexity was n^2 and n can go upto 1e5


