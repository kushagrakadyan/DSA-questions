class Solution {
public:
    // int solve(vector<vector<int>>&grid ,int i,int j,vector<vector<int>> &dp){
    //     int m=grid.size();
    //     int n=grid[0].size();

    //     if(i<0 || i>=m || j<0 || j>=n){
    //         return INT_MAX;
    //     }
       
    //     if(i==m-1 && j==n-1){
    //         return grid[i][j];
    //     }
        
    //     if(dp[i][j]!=-1){
    //         return dp[i][j];
    //     }
    //     int bottom=solve(grid,i+1,j,dp);
    //     int right=solve(grid,i,j+1,dp);

    //     return dp[i][j]=grid[i][j]+min(bottom,right);
    // }    
    // int minPathSum(vector<vector<int>>& grid) {
    //     int m=grid.size();
    //     int n=grid[0].size();
    //     vector<vector<int>> dp(m,vector<int>(n,-1));
    //     return solve(grid,0,0,dp);
    // }

    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
               
       
                if(i==m-1 && j==n-1) {
                    dp[i][j] = grid[i][j];
                    continue;
                }    
                
                int bottom=INT_MAX;
                int right=INT_MAX;
                if(i+1<m){
                    bottom=dp[i+1][j];
                }
                if(j+1<n){
                    right=dp[i][j+1];
                }
                dp[i][j]=grid[i][j]+min(bottom,right);


            }
        }
        return dp[0][0];

    }    

};