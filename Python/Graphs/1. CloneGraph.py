# 133. Clone Graph

"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional
class Solution:
    def __init__(self):
        self.vis = set() # visited set
        self.mp = {} # old node -> new node mapping

    def createNewNodes(self, node):
        #mark the node vis
        self.vis.add(node)
        #create a new node
        newnode = Node(node.val)
        # add old to new map 
        self.mp[node]= newnode
        # explore all its neighbours
        for i in node.neighbors:
            if i not in self.vis:
                self.createNewNodes(i)

    
    def createNewConnections(self,node):
        # mark the node vis
        self.vis.add(node)
        # create edges in the new graph
        for nb in node.neighbors:  # node -> nb
            self.mp[node].neighbors.append(self.mp[nb])
        # explore all the unvisited neighbours and add edges for them        
        for i in node.neighbors:
            if i not in self.vis:
                self.createNewConnections(i)


    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if node is None:
            return None
        
        self.createNewNodes(node)
        self.vis.clear()
        self.createNewConnections(node)

        return self.mp[node]