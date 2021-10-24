/*
You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.
*/



int xArr[]={1,-1,0,0};
int yArr[]={0,0,1,-1};
class Solution {
public:
    bool isPossible(int x,int y,vector<vector<int>>& grid,vector <vector <bool>> &vis){
        if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size() && grid[x][y]==1 && vis[x][y]==false){
            return true;
        }
        return false;
    }
    int dfs(int x,int y,vector<vector<int>>& grid,vector <vector <bool>> &vis){
        vis[x][y]=true;
        int ans=1;
        for(int i=0;i<4;i++){
            if(isPossible(x+xArr[i],y+yArr[i],grid,vis)){
                ans+=dfs(x+xArr[i],y+yArr[i],grid,vis);
            }
        }
        
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        
        vector <vector <bool>> vis(n,vector <bool> (m,false));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==false){
                    int ans1=dfs(i,j,grid,vis);
                    ans=max(ans,ans1);
                }
            }
        }
        return ans;
    }
};
