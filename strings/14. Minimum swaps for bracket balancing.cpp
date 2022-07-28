class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        int close = 0, open = 0;
        for(int i=0;i<s.length();i++){
            if (s[i]=='['){
                st.push(s[i]);
            }else{
                if (!st.empty()){
                    st.pop();
                }else{
                    close++;
                }
            }
        }
        
        open = st.size();
        int ans = (ceil(close/2.0) + ceil(open/2.0))/2;
        return ans;
    }
};