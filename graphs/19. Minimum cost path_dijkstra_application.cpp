Given a square grid of size N, each cell of which contains integer cost which represents a cost to traverse through that cell, we need to find a path from top left cell to bottom right cell by which the total cost incurred is minimum.
From the cell (i,j) we can go (i,j-1), (i, j+1), (i-1, j), (i+1, j). 

Note: It is assumed that negative cost cycles do not exist in the input matrix.
 

Expected Time Compelxity: O(n2*log(n)), while loop will run n^2 times(n^2 elements) and logn operation for priority queue
Expected Auxiliary Space: O(n2) size of priority queue


SOlUTION1: USING BFS -> TLE, Many redundent calls,  Dry run below example will understand

SOlution 2: Since we have to determine shortest path, Dijkstra helps us do that using priority queue
CRUX: In comparator function, for priority queue reverse order me sign likhna hota hai


Example 1:

Input: grid = {{9,4,9,9},{6,7,6,4},
{8,3,3,7},{7,4,9,10}}
Output: 43
Explanation: The grid is-
9 4 9 9
6 7 6 4
8 3 3 7
7 4 9 10
The minimum cost is-
9 + 4 + 7 + 3 + 3 + 7 + 10 = 43.

class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
	int X[4]={-1,0,1,0};
    int Y[4]={0,1,0,-1};
    struct cell{
        int dist, i, j;
        cell(int d, int r, int c){
            dist=d;
            i=r;
            j=c;
        }
    };
    struct compare{
        bool operator()(cell a, cell b){
            if(a.dist==b.dist){
                if(a.i!=b.i) return a.i > b.i;
                else return a.j > b.j;
            }
            return a.dist > b.dist;
        }
    };
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        
        int n=grid.size(), m=grid[0].size();
        
        vector<vector<int> > dist(n, vector<int>(m,INT_MAX));
        
        priority_queue<cell, vector<cell>, compare> pq;
        
        pq.push(cell(grid[0][0],0,0));
        
        dist[0][0]=grid[0][0];
        
        while(!pq.empty()){
            cell p=pq.top();
            pq.pop();
            int d=p.dist, i=p.i, j=p.j;
            
            for(int k=0;k<4;k++){
                int newi=i+X[k], newj=j+Y[k];
                if(newi>=0 and newi<n and newj>=0 and newj<m){
                    if(dist[i][j]+grid[newi][newj] < dist[newi][newj]){
                        dist[newi][newj] = dist[i][j]+grid[newi][newj];
                        pq.push(cell(dist[newi][newj],newi,newj));
                    }
                }
            }
    
        }
        
        return dist[n-1][m-1];
        
        
    }
};