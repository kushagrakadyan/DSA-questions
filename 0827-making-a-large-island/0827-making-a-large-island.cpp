class Solution {
public:
    int n;
    int dfs(int i,int j,vector<vector<int>>& grid,int id){
        if(i<0 || i>=n || j<0 ||j>=n) return 0;
        if(grid[i][j]!=1) return 0;

        grid[i][j]=id;
        int size=1;
        size+=dfs(i+1,j,grid,id);
        size+=dfs(i-1,j,grid,id);
        size+=dfs(i,j+1,grid,id);
        size+=dfs(i,j-1,grid,id);

        return size;

    }
    int largestIsland(vector<vector<int>>& grid) {
        n=grid.size();
        vector<int> islandSize(n*n+2,0);
        int id=2;
        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                   int size = dfs(i,j,grid,id);
                    islandSize[id] = size;
                    ans = max(ans, size);   
                    id++;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    set<int> uniqueIslands;
                    if(i>0 && grid[i-1][j]>1){
                        uniqueIslands.insert(grid[i-1][j]);
                    }
                    if(i<n-1 && grid[i+1][j]>1){
                        uniqueIslands.insert(grid[i+1][j]);
                    }
                    if(j>0 && grid[i][j-1]>1){
                        uniqueIslands.insert(grid[i][j-1]);
                    }
                    if(j<n-1 && grid[i][j+1]>1){
                        uniqueIslands.insert(grid[i][j+1]);
                    }
                    int size=1;
                    for(int islandID:uniqueIslands){
                        size+=islandSize[islandID];
                    }
                   
                    ans=max(ans,size);
                }
            }
        }
        return ans;
    }
    
};