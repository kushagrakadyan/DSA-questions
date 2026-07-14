class Solution {
public:
    int count(vector<int>& nums,int i,int end,vector<int> &dp){
        
        if(i>end){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }   
        

        int steal=nums[i]+count(nums,i+2,end,dp);
        int skip=count(nums,i+1,end,dp);

       
        return dp[i]=max(steal,skip);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);

        int c1=count(nums,0,n-2,dp1);
        int c2=count(nums,1,n-1,dp2);
        
        return max(c1,c2);
        
    }
};