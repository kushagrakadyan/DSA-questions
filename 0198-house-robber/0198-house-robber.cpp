class Solution {
public:
    // int count(vector<int>& nums,int i,int n,vector<int> &dp){
    //     if(i>=n) return 0;

    //     if(dp[i]!=-1){
    //         return dp[i];
    //     }

    //     int skip=count(nums,i+1,n,dp);
    //     int steal=nums[i]+count(nums,i+2,n,dp);
    //     return dp[i]=max(steal,skip);

    // }
    // int rob(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<int> dp(n,-1);
    //     return count(nums,0,n,dp);
    // }
    int rob(vector<int>& nums) {
        int n=nums.size();
       
        vector<int> dp(n);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            int steal=nums[i];
            if(i>1){
                steal=nums[i]+dp[i-2];
            }
            int skip=dp[i-1];
            dp[i]=max(steal,skip);
        }
        return dp[n-1];
    }    
};