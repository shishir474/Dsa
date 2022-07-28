Given two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. Find the length of the shortest transformation sequence from startWord to targetWord.
Keep the following conditions in mind:

A word can only consist of lowercase characters.
Only one letter can be changed in each transformation.
Each transformed word must exist in the wordList including the targetWord.
startWord may or may not be part of the wordList.
The second part of this problem can be found here.


Example 1:

Input:
wordList = {"des","der","dfr","dgt","dfs"}
startWord = "der", targetWord= "dfs",
Output:
3
Explanation:
The length of the smallest transformation
sequence from "der" to "dfs" is 3
i,e "der" -> "dfr" -> "dfs".




class Solution {
public:

TC: O(n*len*26) where n is the number of words
SC: O(n) -> used set
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord.compare(endWord) == 0)return 0;
        
        int steps=0;
        
        set<string> set(wordList.begin(),wordList.end());
        //min steps - shortest path hence bfs
        queue<string> q;
        q.push(beginWord);

        set.erase(beginWord); //marked visited;
        
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                string s=q.front();
                q.pop();
                if(s.compare(endWord)==0) return steps+1;
                // explore all neighbours
                for(int i=0;i<s.length();i++){
                    char tc=s[i];
                    for(char ch='a';ch<='z';ch++){
                        s[i]=ch;
                        if(set.count(s)){ // if neighbour exists
                            set.erase(s); // mark neighbor visited
                            q.push(s);    // & push it into queue
                        }
                    }
                    s[i]=tc;
                }
                
            }
            
            steps++;
        }
        
        
        return 0;
    }
};