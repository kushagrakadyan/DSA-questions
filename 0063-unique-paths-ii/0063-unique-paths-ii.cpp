class Solution {
public:
    // int solve(vector<vector<int>>& obstacleGrid,int i,int j,vector<vector<int>> &dp){
    //     int m=obstacleGrid.size();
    //     int n=obstacleGrid[0].size();
        

    //     if(i<0 || i>=m || j<0 || j>=n){
    //         return 0;
    //     }
    //     if(i>=m && j>=n){
    //         return 0;
    //     }
    //     if(obstacleGrid[i][j]==1) return 0;
    //     if(dp[i][j]!=-1){
    //         return dp[i][j];
    //     }
    //     if(i==m-1 && j==n-1) return 1;
    //     int right=solve(obstacleGrid,i,j+1,dp);
    //     int bottom=solve(obstacleGrid,i+1,j,dp);
    //     return dp[i][j]=right+bottom;

    // }
    // int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    //     int m=obstacleGrid.size();
    //     int n=obstacleGrid[0].size();
    //     vector<vector<int>> dp(m,vector<int>(n,-1));
    //     return solve(obstacleGrid,0,0,dp);
    // }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int> (n,0));
        if(obstacleGrid[0][0]==1){
            return 0;
        }
        dp[0][0]=1;
        for(int i=1;i<m;i++){
            if(obstacleGrid[i][0]==0){
            dp[i][0]=dp[i-1][0];
            }
        }
        for(int j=1;j<n;j++){
            if(obstacleGrid[0][j]==0){
            dp[0][j]=dp[0][j-1];
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                }
                else{
                int right=dp[i-1][j];
                int bottom=dp[i][j-1];
                dp[i][j]=right+bottom;
                }
            }
        }
        return dp[m-1][n-1];
    }
};