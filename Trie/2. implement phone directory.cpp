Implement a phone directory
Difficulty: HARD

Problem Statement
You are given a list/array of strings which denotes the contacts that exist in your phone directory.
The search query on a string ‘str’ which is a query string displays all the contacts which are present in the 
given directory with the prefix as ‘str’. One special property of the search function is that when a user 
searches for a contact from the contact list then suggestions (contacts with prefix as the string entered so for) 
are shown after the user enters each character.

Sample Input 1 :
2
5
cod coding codding code coly
coding
2
ninjas coding
ninja

Sample Output 1 :
cod coding codding code coly
cod coding codding code coly
cod coding codding code coly
coding
coding
coding
ninjas
ninjas
ninjas
ninjas
ninjas


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
    
      bool searchUtil(TrieNode* root, string word){
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
        
        return searchUtil(child,word.substr(1));
    }

    bool search(string word){
        return searchUtil(root,word);
    }
    
    
    
void printSuggestions(TrieNode* curr, string prefix, vector<string>& temp){
        if(curr->isTerminal){
            temp.push_back(prefix);
        }
        
        for(char ch='a';ch<='z';ch++){
            TrieNode* next = curr->children[ch-'a'];
            if(next!=NULL){
                prefix.push_back(ch);
                printSuggestions(next,prefix,temp);
                prefix.pop_back();
            }
        }
    }
    
vector<vector<string>> getSuggestions(string s){
        vector<vector<string> > res;
        TrieNode* prev=root;
        string prefix="";
        
        for(int i=0;i<s.length();i++){
            char lastch=s[i];
            
            prefix.push_back(s[i]);
            
            TrieNode* curr=prev->children[lastch-'a'];
            
            if(curr==NULL) break;
            
            vector<string> temp;
            printSuggestions(curr,prefix,temp);
            res.push_back(temp);
            
            prev=curr;
        }
        
        return res;
    }
    
};

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
        Trie* t = new Trie;
        for(int i=0;i<contactList.size();i++) t->insertWord(contactList[i]);
  
        return t->getSuggestions(queryStr);
}