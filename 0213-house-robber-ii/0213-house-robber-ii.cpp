class Solution {
public:
    // int count(vector<int>& nums,int i,int end,vector<int> &dp){
        
    //     if(i>end){
    //         return 0;
    //     }
    //     if(dp[i]!=-1){
    //         return dp[i];
    //     }   
    //     int steal=nums[i]+count(nums,i+2,end,dp);
    //     int skip=count(nums,i+1,end,dp);

       
    //     return dp[i]=max(steal,skip);
    // }
    // int rob(vector<int>& nums) {
    //     int n=nums.size();
    //     if(n==1){
    //         return nums[0];
    //     }
    //     vector<int> dp1(n,-1);
    //     vector<int> dp2(n,-1);

    //     int c1=count(nums,0,n-2,dp1);
    //     int c2=count(nums,1,n-1,dp2);
        
    //     return max(c1,c2);
        
    // }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        vector<int> dp1(n);
            dp1[0]=nums[0];
            dp1[1]=max(nums[0],nums[1]);
            for(int i=2;i<n;i++){
                int take=nums[i];
                if(i>1){
                    take=nums[i]+dp1[i-2];
                }
                int skip=dp1[i-1];

                dp1[i]=max(take,skip);
           
            }
        vector<int> dp2(n);
            dp2[1]=nums[1];
            dp2[2]=max(nums[1],nums[2]);
            for(int i=3;i<n;i++){
                int take=nums[i];
                if(i>1){
                    take=nums[i]+dp2[i-2];
                }
                int skip=dp2[i-1];

                dp2[i]=max(take,skip);
           
            }
        
    return max(dp1[n-2],dp2[n-1]);
    }
};