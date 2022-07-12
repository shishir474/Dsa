Given a square chessboard, the initial position of Knight and position of a target. Find out the minimum steps a Knight will take to reach the target position.

Note:
The initial and the target position coordinates of Knight have been given according to 1-base indexing.

int X[]={-2,-1,1,2,2,1,-1,-2};
int Y[]={1,2,2,1,-1,-2,-2,-1};

//Function to find out minimum steps Knight needs to reach target position.
bool isSafe(int i, int j, int n, vector<vector<bool> >& vis){
    if(i>=0 and i<n and j>=0 and j<n and !vis[i][j]) return true;
    return false;
}
int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
{
    if(KnightPos[0]==TargetPos[0] and KnightPos[1]==TargetPos[1])  return 0;
    
    vector<vector<bool> > vis(N, vector<bool>(N,false));
    
    queue<pair<int,int> > q;
    
    q.push({KnightPos[0]-1 ,KnightPos[1]-1});
    
    vis[KnightPos[0]-1][KnightPos[1]-1]=true;
    
    int steps=0;
    
    while(!q.empty()){
        int sz=q.size();
        while(sz--){
            pair<int,int> p=q.front();
            q.pop();
            int i=p.first, j=p.second;
            if(i==TargetPos[0]-1 and j==TargetPos[1]-1) return steps;
            
            for(int k=0;k<8;k++){
                if(isSafe(i+X[k],j+Y[k],N,vis)){
                    vis[i+X[k]][j+Y[k]]=true;
                    q.push({i+X[k], j+Y[k]});
                }
            }
        }
        steps++;
    }
    
    return 0;
    
}