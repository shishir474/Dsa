Minimum Cost to cut a board into squares
A board of length M and width N is given. The task is to break this board into M * N squares such that cost of breaking is minimum. The cutting cost for each edge will be given for the board in two arrays X[] and Y[]. In short, you need to choose such a sequence of cutting such that cost is minimized. Return the minimized cost.

Example 1:

Input:
M = 6. N = 4
X[] = {2, 1, 3, 1, 4}
Y[] = {4, 1, 2}
Output: 42
Explanation: 

For above board optimal way to cut into square is:
Total minimum cost in above case is 42. It is 
evaluated using following steps.
Initial Value : Total_cost = 0
Total_cost = Total_cost + edge_cost * total_pieces
Cost 4 Horizontal cut:      Cost = 0 + 4*1 = 4
Cost 4 Vertical cut:        Cost = 4 + 4*2 = 12
Cost 3 Vertical cut:        Cost = 12 + 3*2 = 18
Cost 2 Horizontal cut:      Cost = 18 + 2*3 = 24
Cost 2 Vertical cut:        Cost = 24 + 2*3 = 30
Cost 1 Horizontal cut:      Cost = 30 + 1*4 = 34
Cost 1 Vertical cut:        Cost = 34 + 1*4 = 38
Cost 1 Vertical cut:        Cost = 38 + 1*4 = 42


int minimumCostOfBreaking(vector<int> X, vector<int> Y, int M, int N){
        sort(X.begin(),X.end(),greater<int>());
        sort(Y.begin(),Y.end(),greater<int>());
       
        int hp=1,vp=1,ans=0;
        
        int i=0,j=0;
        while(i<M and j<N){
            if(Y[j] >= X[i]){
                ans+=(Y[j]*hp);
                vp++;
                j++;
            }
            else{
                ans+=(X[i]*vp);
                hp++;
                i++;
            }
        }
        
        while(i<M){
            ans+=(X[i]*vp);
            hp++;
            i++;
        }
        
        while(j<N){
            ans+=(Y[j]*hp);
            vp++;
            j++;
        }
        
        return ans;
}