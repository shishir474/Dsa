# Design Add and Search Words DataStructure Leetcode 211

# https://www.youtube.com/watch?v=BTf05gs_8iU&list=PLot-Xpze53ldVwtstag2TL4HQhAnC8ATf&index=72

class TrieNode:
    def __init__(self) -> None:
        self.children = {}
        self.isTerminal = False

class WordDictionary:

    def __init__(self):
        self.root = TrieNode()

    def addWord(self, word: str) -> None:
        curr = self.root
        for c in word:
            if c not in curr.children:
                curr.children[c] = TrieNode()
            curr = curr.children[c]
        curr.isTerminal=  True
        
    def searchHelper(self, curr, i, word):
        if i==len(word):
            return curr.isTerminal
        if word[i]!='.':
            if word[i] not in curr.children: 
                return False
            return self.searchHelper(curr.children[word[i]], i+1, word)
        else:
            for c in curr.children:
                if self.searchHelper(curr.children[c], i+1, word):
                    return True
            return False

    def search(self, word: str) -> bool:
        return self.searchHelper(self.root, 0, word)
        