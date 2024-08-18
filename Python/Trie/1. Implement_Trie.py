# Leetcode 208

# Trie Implementation

# Trie or Prefix Tree is a data structure that helps you to determine whether a word exists or a word with certain prefix exists efficiently like the startsWith functionality
# Assume you are given a million words in list, and you want to determine if there exists any word with a given prefix. You will have to check each word in the worst case, but using trie this can be done very efficiently
# TC: will be length of the word in the worst case

# Trie's are used for autosearch, search implmentation

# Trie supports basically 3 functionalitites
# 1. Insert a word in Trie. TC of inserting a word is O(len(word))
# 2. Search a word in Trie. TC is O(len(word))
# 3. Search for a prefix. TC is O(len(prefix))

class TrieNode:
    def __init__(self, c="") -> None:
        self.val = c
        self.children = [None]*(26)
        self.isTerminal = False

class Trie:
    def __init__(self):
        # creates the root node of your trie
        self.root = TrieNode()
    
    def insert(self, word):
        # intialise curr with root(starting point)
        curr = self.root
        
        for c in word:
            if curr.children[ord(c)-ord('a')] is None:
                # created a new childnode with this c char and placed it into the children's array
                curr.children[ord(c)-ord('a')] = TrieNode(c)
            # update curr
            curr = curr.children[ord(c)-ord('a')] 
        
        #set curr.isTerminal to true to mark the end of word
        curr.isTerminal = True
    
    def search(self, word):
        curr = self.root
        for c in word:
            if curr.children[ord(c)-ord('a')] is None:
                return False
            curr = curr.children[ord(c)-ord('a')] 
        return curr.isTerminal
            
    
    def startsWith(self, word):
        curr = self.root
        for c in word:
            if curr.children[ord(c)-ord('a')] is None:
                return False
            curr = curr.children[ord(c)-ord('a')] 
        return True
    


# Neetcode's solution
# Using dictionaries: simple implementation:
# Each node will have a children hashmap that will store char -> TrieNode mapping
class TrieNode:
    def __init__(self) -> None:
        self.children = {}
        self.isTerminal = False

class Trie:
    def __init__(self):
        # creates the root node of your trie
        self.root = TrieNode()
    
    def insert(self, word):
        curr = self.root
        for c in word:
            if c not in curr.children:
                curr.children[c] = TrieNode()
            curr = curr.children[c] 
        curr.isTerminal = True
    
    def search(self, word):
        curr = self.root
        for c in word:
            if c not in curr.children:
                return False
            curr = curr.children[c] 
        return curr.isTerminal
            
    def startsWith(self, word):
        curr = self.root
        for c in word:
            if c not in curr.children:
                return False
            curr = curr.children[c] 
        return True