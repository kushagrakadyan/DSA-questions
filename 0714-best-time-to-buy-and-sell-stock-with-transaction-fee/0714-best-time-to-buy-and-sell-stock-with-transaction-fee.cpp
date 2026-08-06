class Solution {
public:
    int solve(vector<int>& prices, int fee,int i,int buy,vector<vector<int>> &dp){
        if(i>=prices.size()){
            return 0;
        }
        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }
        if(buy){
            int take=-prices[i]+solve(prices,fee,i+1,0,dp);
            int skip=solve(prices,fee,i+1,1,dp);
            return dp[i][buy]=max(take,skip);
        }
        int sell=prices[i]-fee+solve(prices,fee,i+1,1,dp);
        int hold=solve(prices,fee,i+1,0,dp);
        return dp[i][buy]=max(sell,hold);
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return solve(prices,fee,0,1,dp);
    }
};