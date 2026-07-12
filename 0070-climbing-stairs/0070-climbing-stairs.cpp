class Solution {
public:
    //int count(int n)
    int count(int n,vector<int> &dp){
        if(n==1 || n==2 ){
            return n;
        }
        if(dp[n] != -1) return dp[n];
        return dp[n]=count(n-1,dp)+count(n-2,dp);
    }    
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return count(n,dp);
    }
};