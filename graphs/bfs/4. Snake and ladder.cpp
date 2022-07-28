https://practice.geeksforgeeks.org/problems/snake-and-ladder-problem4816/1
Given a 5x6 snakes and ladders board, find the minimum number of dice throws required to reach the destination or last cell (30th cell) from the source (1st cell).

You are given an integer N denoting the total number of snakes and ladders and an array arr[] of 2*N size where 2*i and (2*i + 1)th values denote the starting and ending point respectively of ith snake or ladder. The board looks like the following.


                                   

Example 1:

Input:
N = 8
arr[] = {3, 22, 5, 8, 11, 26, 20, 29, 
       17, 4, 19, 7, 27, 1, 21, 9}
Output: 3
Explanation:
The given board is the board shown
in the figure. For the above board 
output will be 3. 
a) For 1st throw get a 2. 
b) For 2nd throw get a 6.
c) For 3rd throw get a 2.





struct cell{
    int vertex, dist;
    cell(int v, int d){
        vertex=v;
        dist=d;
    }
};
    int minThrow(int N, int arr[]){
        map<int,int> ladder;
        map<int,int> snake;
        for(int i=0;i<2*N;i+=2){
            int u=arr[i], v=arr[i+1];
            if(u < v){  // u->v snake
                ladder.insert({u,v});
            }
            else{
                snake.insert({u,v});
            }
        }
        
      
     // Create Graph
        vector<int> adj[31];
        
        for(int i=1;i<=30;i++){
            for(int j=i+1;j<=min(i+6,30);j++){
                if(ladder.count(j)){
                    adj[i].push_back(ladder[j]); 
                }
                else if(snake.count(j)){
                    adj[i].push_back(snake[j]);  
                }
                else
                    adj[i].push_back(j); // i->j
            }
        }
        
        
        set<int> vis;
        
        queue<cell> q;
        
        q.push(cell(1,0));
        
        vis.insert(1);
        
        while(!q.empty()){
            cell f=q.front();
            q.pop();
            
            int v=f.vertex, d=f.dist;
            
            if(v==30) return d;
            
            for(int i: adj[v]){
                if(vis.count(i) == 0){
                    vis.insert(i);
                    q.push(cell(i,d+1));
                }
            }
            
            
        }
        
        return 0;
        
        
    }