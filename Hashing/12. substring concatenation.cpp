You are given a string, S, and a list of words, L, that are all of the same length.

Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

Example :

S: "barfoothefoobarman"
L: ["foo", "bar"]
You should return the indices: [0,9].

(order does not matter).



vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    int len = B[0].length();
    if (A.length() < len*B.size()) return {};
    
    vector<int> res;

    map<string,int> mp;
    for(int i=0;i<B.size();i++){
        mp[B[i]]++;
    }

    int m = len*B.size();
    int j;

    for(int i=0;i<=A.length()-m;i++){
        
        map<string, int> newMap;

        for(j=i;j<i+m;j+=len){
            string substring = A.substr(j,len);
            if (mp.count(substring)){
                newMap[substring]++;
                if (newMap[substring] > mp[substring]) break;
            }else{
                break;
            }
        }

        if (mp==newMap) res.push_back(i);

    }


    return res;
}
