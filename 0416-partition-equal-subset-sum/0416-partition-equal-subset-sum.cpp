class Solution {
public://sort(nums.begin(),nums.end()); wrong
        // for(int i=0;i<nums.size();i++){
        //     int sum=0;
        //     for(int k=0;k<=i;k++){
        //         sum+=nums[k];
        //     }
        //     int reversesum=0;
        //     for(int j=nums.size()-1;j>i;j--){
        //         reversesum+=nums[j];
        //         if(sum==reversesum){
        //            return true;
        //         }
        //     }
        // }
        // return false;

    bool solve(vector<int>& nums,int x,int i,vector<vector<int>> &dp){
        if(x==0) return true;
        if(i>=nums.size()){
            return false;
        }
        if(dp[i][x]!=-1){
            return dp[i][x];
        }
        bool take=false;
        bool not_take=solve(nums,x,i+1,dp);
        if(x>=nums[i]){
            take=solve(nums,x-nums[i],i+1,dp);
            
        }
        return dp[i][x]=take || not_take;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        

        int s=accumulate(begin(nums),end(nums),0);
        if(s%2!=0){
            return false;
        }
        int x=s/2;
        vector<vector<int>> dp(n,vector<int>(x+1,-1));
        return solve(nums,x,0,dp);
    }
};