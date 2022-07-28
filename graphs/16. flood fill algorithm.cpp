An image is represented by a 2-D array of integers, each integer representing the pixel value of the image.

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

Example 1:

Input: image = {{1,1,1},{1,1,0},{1,0,1}},
sr = 1, sc = 1, newColor = 2.
Output: {{2,2,2},{2,2,0},{2,0,1}}


Expected Time Compelxity: O(n*m)
Expected Space Complexity: O(n*m)

NOTE: matrix me dfs ki complexity m*n hoti hai

int X[4]={-1,0,1,0};
int Y[4]={0,1,0,-1};
public:

void dfs(int i, int j, vector<vector<int>>& image, vector<vector<int>>& vis, int nc, int oc){
    int n=image.size(), m=image[0].size();
    vis[i][j]=1;
    image[i][j]=nc;
    for(int k=0;k<4;k++){
        int newi=i+X[k], newj=j+Y[k];
        if(newi>=0 and newi<n and newj>=0 and newj<m and !vis[newi][newj] and image[newi][newj]==oc){
            dfs(newi,newj,image,vis,nc,oc);
        }
    }
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int n=image.size(), m=image[0].size();
    vector<vector<int> > vis(n,vector<int>(m,false));
    dfs(sr,sc,image,vis,newColor, image[sr][sc]);
    return image;
    
}


