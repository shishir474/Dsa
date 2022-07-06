int expandFromMiddle(int l,int r,string s){
      while(l>=0 and r<s.length() and s[l]==s[r]){
          l--; r++;
      }
      return r-l-1;
  }
  
string longestPalin (string S) {
    // code here
    int len=0,st=0,end=0;
    for(int i=0;i<S.length()-1;i++){
        int len1=expandFromMiddle(i,i,S);
        int len2=expandFromMiddle(i,i+1,S);
        if(max(len1,len2) > len){
            len = max(len1,len2);
            st = i-((len-1)/2);
            end = i+(len/2);
        }
    }
    
    
    return S.substr(st,end-st+1);
    
}

// time complexity: o(n^2), sc: O(1)

// solution 2: using dp: TC: O(n^2), sc: O(1)