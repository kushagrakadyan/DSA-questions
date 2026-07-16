class Solution {
public:
    int solve(vector<vector<int>>& triangle,int i,int j,vector<vector<int>> &dp){
        int m=triangle.size();
        if(i>=m || j<0){
            return 0;
        }
        int n=triangle[i].size();
        if(i<0 || j>=n){
            return 0;
        } 
        
        if(i==m-1){
            return triangle[i][j];
        }
        if(dp[i][j]!=INT_MAX){
            return dp[i][j];
        }
        int bottom=solve(triangle,i+1,j,dp);
        int diagonal=solve(triangle,i+1,j+1,dp);

        return dp[i][j]=triangle[i][j]+min(bottom,diagonal);


    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        vector<vector<int>> dp;
        for(int i = 0; i < m; i++){
        dp.push_back(vector<int>(triangle[i].size(), INT_MAX));
        }
        return solve(triangle,0,0,dp);
    }
};