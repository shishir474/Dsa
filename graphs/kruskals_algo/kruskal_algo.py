#User function Template for python3
from typing import List

class Solution:
    def kruskalsMST(self, V: int, edges: List[List[int]]) -> int:
        edges.sort(key=lambda x: x[2])
        print(edges)