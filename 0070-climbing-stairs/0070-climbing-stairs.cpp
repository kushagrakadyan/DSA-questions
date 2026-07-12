class Solution {
public:
    //memoisation se

    // int count(int n,vector<int> &dp){
    //     if(n==1 || n==2 ){
    //         return n;
    //     }
    //     if(dp[n] != -1) return dp[n];
    //     return dp[n]=count(n-1,dp)+count(n-2,dp);
    // }    
    // int climbStairs(int n) {
    //     vector<int> dp(n+1,-1); // 1 ke baad se suru hone ke liye
    //     return count(n,dp);
    // }


    //tablulation se
    int climbStairs(int n){
        if(n==1){
            return n;
        }
        vector<int> dp(n+1);
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};