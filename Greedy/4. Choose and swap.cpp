Choose and Swap 
You are given a string s of lower case english alphabets. You can choose any two characters in the string and replace all the occurences of the first character with the second character and replace all the occurences of the second character with the first character. Your aim is to find the lexicographically smallest string that can be obtained by doing this operation at most once.

Example 1:

Input:
A = "ccad"
Output: "aacd"
Explanation:
In ccad, we choose a and c and after 
doing the replacement operation once we get, 
aacd and this is the lexicographically
smallest string possible. 

 string chooseandswap(string a){
        // Code Here
        set<char> s;
        vector<char> v;
        for(int i=0;i<a.length();i++) {
            if(s.count(a[i])==0){
                v.push_back(a[i]);
            }
            s.insert(a[i]);
        }
        
        sort(v.begin(),v.end());

        char c1='$',c2='$';
        int i=0,j=0;
        while(i<a.length() and j<v.size()){
            if(a[i]==v[j]){
                while(i<a.length() and a[i]==v[j]) i++;
                j++;
            }
            else if(a[i] < v[j]){
                // abcdefghijklabcdefghijklopo
                 i++; continue;
            }
            else{// swapping is performed if c1 > c2
                c1=a[i];
                c2=v[j];
                break;
            }
        }
        if(c1!='$'){
            for(int i=0;i<a.length();i++){
                if(a[i]==c1){
                    a[i] = c2;
                }
                else if(a[i]==c2){
                    a[i]=c1;
                }
            }
        }
        
        return a;
    }