class Solution {
public:
    int solve(vector<int>& prices,int i,int buy,vector<vector<int>> &dp){
        if(i>=prices.size()){
            return 0;
        }
        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }
        if(buy){
            int take=-prices[i]+solve(prices,i+1,0,dp);
            int skip=solve(prices,i+1,1,dp);
            return dp[i][buy]=max(take,skip);
        }
        int sell=prices[i]+solve(prices,i+2,1,dp);
        int hold=solve(prices,i+1,0,dp);
        return dp[i][buy]=max(sell,hold);
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(3,-1));
        return solve(prices,0,1,dp);
    }
};