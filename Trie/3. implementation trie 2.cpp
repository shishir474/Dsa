Ninja has to implement a data structure ”TRIE” from scratch. Ninja has to complete some functions.
1) Trie(): Ninja has to initialize the object of this “TRIE” data structure.

2) insert(“WORD”): Ninja has to insert the string “WORD”  into this “TRIE” data structure.

3) countWordsEqualTo(“WORD”): Ninja has to return how many times this “WORD” is present in this “TRIE”.

4) countWordsStartingWith(“PREFIX”): Ninjas have to return how many words are there in this “TRIE” that have the string “PREFIX” as a prefix.

5) erase(“WORD”): Ninja has to delete one occurrence of the string “WORD” from the “TRIE”.



solution:
INSERT
added two more members in our trienode clase countprefix which indicates no. of prefix at this char and countend which indicates no. of strings which ends at this char.
during insert for each char do countprefix++ and at the end increase countend by 1 which means one word ends at this char.
ERASE
During erase, do countprefix-- and at end decrease countend by 1
countWordsEqualTo
traverse the entire word and at last return countend
countWordsStartingWith
traverse the entire prefix and at last return countprefix








class TrieNode{
  public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    int countprefix;
    int countend;
    TrieNode(char ch){
        data = ch;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        isTerminal=false;
        countprefix=0;
        // countend
    }
};

class Trie{

    public:
    TrieNode* root;
    Trie(){
        root = new TrieNode('\0');
    }
     
    void insertUtil(TrieNode* root,string word){
        if(word.length()==0){
            root->isTerminal=true;
            root->countend++;
            return;
        }
        int index=word[0]-'a';
        TrieNode* child;
        if(root->children[index] != NULL){
            child = root->children[index];  
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        child->countprefix++;
        insertUtil(child,word.substr(1));
    }
    void insert(string &word){
        insertUtil(root,word);
    }
    
    
     int countWordsEqualToUtil(TrieNode* root, string word){
        if(word.length()==0){
            return root->countend;
        }
        // assuming that word contains smallcase char
        int index=word[0]-'a';
        TrieNode* child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            return 0;
        }
        
        return countWordsEqualToUtil(child,word.substr(1));
    }
    int countWordsEqualTo(string &word){
       return countWordsEqualToUtil(root,word); 
    }


     
    int countWordsStartingWithUtil(string prefix){
        TrieNode* prev=root;
        for(int i=0;i<prefix.length();i++){
            int lastch=prefix[i];
            TrieNode* curr = prev->children[lastch-'a'];
            if (curr!=NULL){
                prev = curr;
            }
            else{
                return 0;
            }
        }
        
        return prev->countprefix;
    }
    int countWordsStartingWith(string &word){
        // Write your code here.
        return countWordsStartingWithUtil(word);
    }
    


    void eraseUtil(TrieNode* root,string word){
        if(word.length()==0){
            root->isTerminal = false;
            root->countend--;
            return;
        }
        int index=word[0]-'a';
        TrieNode* child;
        if(root->children[index] != NULL){
            child = root->children[index]; 
            child->countprefix--;
            eraseUtil(child,word.substr(1));
        }else{
            return;
        }
    }
    void erase(string &word){
        eraseUtil(root,word);
    }
};


