wants to test his knowledge.
A string is called a complete string if every prefix of this string is also present in the array ‘A’. Ninja is challenged to find the longest complete string in the array ‘A’.If there are multiple strings with the same length, return the lexicographically smallest one and if no string exists, return "None".
Note :
String ‘P’ is lexicographically smaller than string ‘Q’, if : 

1. There exists some index ‘i’ such that for all ‘j’ < ‘i’ , ‘P[j] = Q[j]’ and ‘P[i] < Q[i]’. E.g. “ninja” < “noder”.

2. If ‘P’ is a prefix of string ‘Q’, e.g. “code” < “coder”.


class TrieNode{
    public:
    char data;
    TrieNode** children;
    bool isTerminal;
    TrieNode(char ch){
        data = ch;
        children = new TrieNode*[26];
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal = false;
    }
};

class Trie{
    public:
    TrieNode* root;
    Trie(){
        root = new TrieNode('\0');
    }

    void insertWordUtil(TrieNode* root, string word){
        if (word.length()==0){
            root->isTerminal = true;
            return;
        }
        // assuming word contains smallcase letters
        int index = word[0]-'a';
        TrieNode* child;
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertWordUtil(child,word.substr(1));
    }

    void insertWord(string word){
        insertWordUtil(root,word);
    }


    bool checkIsCompleteUtil(TrieNode* root, string word){
        if(word.length()==0){
            return root->isTerminal;
        }
        // assuming that word contains smallcase char
        int index=word[0]-'a';
        TrieNode* child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            return false;
        }
        if(child->isTerminal == false) return false;
        return checkIsCompleteUtil(child,word.substr(1));
    }

    bool checkIsComplete(string word){
        return checkIsCompleteUtil(root,word);
    }
};

string completeString(int n, vector<string> &a){
    Trie* t = new Trie();
    for(int i=0;i<a.size();i++){
        t->insertWord(a[i]);
    }
    string ans="";
    for(int i=0;i<a.size();i++){
        if(t->checkIsComplete(a[i])){
            if(a[i].length() > ans.length()){
                ans = a[i];
            }
            else if(a[i].length()==ans.length() and a[i].compare(ans) < 0){
                // of same length as ans, but is lexicographically smaller
                ans = a[i];
            }
        }
    }
    
    if(ans=="") return "None";
    
    return ans;
}