class Solution {
public:
    // int solve(int i,int j,int m,int n,vector<vector<int>> &dp){

    //     if(i<0 || i>=m || j<0 || j>=n){
    //         return 0;
    //     }
    //     if(i==m-1 && j==n-1){
    //         return 1;
    //     }
    //     if(dp[i][j]!=-1){
    //         return dp[i][j];
    //     }
    //     int right=solve(i,j+1,m,n,dp);
    //     int bottom=solve(i+1,j,m,n,dp);

    //     return dp[i][j]=right+bottom;

    // }
    // int uniquePaths(int m, int n) {
    //     vector<vector<int>> dp(m,vector<int>(n,-1));
    //     return solve(0,0,m,n,dp);
    // }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n,0));
        for(int i=0;i<m;i++){
            dp[i][0]=1;
        }
        for(int j=0;j<n;j++){
            dp[0][j]=1;
        }
       

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                int right=dp[i-1][j];
                int bottom=dp[i][j-1];

                dp[i][j]=right+bottom;
            }
        }
        return dp[m-1][n-1];

    }
};