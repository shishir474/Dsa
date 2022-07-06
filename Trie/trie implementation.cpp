#include <bits/stdc++.h>
using namespace std;

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


    void removeUtil(TrieNode* root, string word){
        if(word.length()==0){
            root->isTerminal = false;
            return ;
        }
        int index=word[0]-'a';
        TrieNode* child = root->children[index];
        removeUtil(child,word.substr(1));
    }

    void remove(string word){
        // assumes that word exists in trie
        removeUtil(root,word);
    }
    
};

int main(){
    Trie t;
    t.insertWord("arm");
    t.insertWord("do");
    t.insertWord("time");
    cout<<t.search("tim");
}


// Complexity:
// insert,search,remove -> O(L), where L is the length of the word
// Reason: processing all char of the word. hence O(L)