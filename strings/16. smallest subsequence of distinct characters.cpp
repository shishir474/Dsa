    solution:
    we need exact one occurence of every character, so kept visited to keep track of visited characters
        lets take the 0th character as part of our ans oas of now, we wil start from 1st index
    Now if s[i] > prev character(which was s[0]) and !visited[s[i]] we can keep take it
        But if s[i] < prevCharacter, then we will check if the prevCharacter has an occurence anywhere after i, If its present then we can use that occurence of prev char
            so we will remove it from stack and also unvisit it(bcoz now we have removed it from the ans)
            BUt if its not present after i, then we will have to take that occurence only
                
        So I need last occurence of every character, to determine if its present after any index i or not. -> use map


    PSUEDO CODE:    
       stack<char> st;
       st.push(s[0]);
            
        for(int i=1; i<s.length();i++){
            if(!visited[s[i]-'a']){
                if(s[i] > st.top()){
                    // ans+=s[i] ; dont include in ans yet, will do that later
                    visited[s[i]-'a']=true;
                    st.push(s[i])
                }
                else{ // st.top() > s[i];
                    if(lastindex[st.top()] > i){
                        while(!st.empty() and st.top()>s[i] and lastindex[st.top()] > i){
                            st.pop();
                        }
                        st.push(s[i]);
                        visited[s[i]-'a']=true;
                    }
                    else{
                         st.push(s[i]);
                        visited[s[i]-'a']=true;
                    }
                }
            }
            else{
                continue;
            }
        }
    
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    
    reverse(ans.begin(),ans.end());
    return ans;



SIMILAR QUESTION FOR subSTRING: There we can use sliding window, but here sliding window will not work

SOLUTION:

    class Solution {
public:
    string smallestSubsequence(string s) {
         map<char,int> lastIndex;
        int size = s.length();
        
        for(int i=0;i<size;i++){
            lastIndex[s[i]] = i;
        }
     
        
        stack<char> stack;
        set<char> vis;
        
        stack.push(s[0]);
        vis.insert(s[0]);
        
       // "cbacdcbc"
        
        for(int i=1;i<size;i++){
            if (vis.count(s[i]) == 0){
                if (stack.top() > s[i]){
                    if (lastIndex[stack.top()] > i){
                        
                        while(!stack.empty() && stack.top() > s[i] && lastIndex[stack.top()] > i){
                             vis.erase(stack.top());
                             stack.pop();
                        }
                        
                        stack.push(s[i]);
                        vis.insert(s[i]); 
                    }
                    else{
                        stack.push(s[i]);
                        vis.insert(s[i]); 
                    }
                } 
                else{
                     stack.push(s[i]);
                     vis.insert(s[i]);   
                }
            }
        }
        
        string res="";
        while(!stack.empty()){
            res+=stack.top();
            stack.pop();
        }
        
         reverse(res.begin(), res.end());
        
        return res;
       
    }
};