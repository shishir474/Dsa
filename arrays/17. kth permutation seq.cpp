 string getPermutation(int n, int k) {
        vector<int> digits;
        for(int i=1;i<=n;i++) digits.push_back(i);
        vector<int> fact(11);
        fact[0]=fact[1]=1;
        for(int i=2;i<11;i++){
            fact[i] = i*fact[i-1];
        }
        string ans="";
        for(int i=0;i<n;i++){
            int bs=fact[n-i-1];
            int idx = ceil(k/(bs*1.0)) - 1;
            ans.push_back(digits[idx]+'0');
            digits.erase(digits.begin()+idx);
            k-=(bs*idx);
        }
        
        return ans;
    }