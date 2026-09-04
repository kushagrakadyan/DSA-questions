class Solution {
public:
    
    void dfs(vector<vector<char>>& grid,int i,int j,vector<vector<bool>> &vis,int& m,int& n){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]!='1' || vis[i][j]) return;

        vis[i][j]=true;
        dfs(grid,i+1,j,vis,m,n);
        dfs(grid,i-1,j,vis,m,n);
        dfs(grid,i,j+1,vis,m,n);
        dfs(grid,i,j-1,vis,m,n);
    }
    int numIslands(vector<vector<char>>& grid) {
        int islands=0;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    dfs(grid,i,j,vis,m,n);
                    islands++;
                }
            }
        }
        return islands;
    }
};