class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int len=2;len<n;len++){
            for(int left=0;left+len<n;left++){
                int right=left+len;

                for(int k=left+1;k<right;k++){

                    int coins=dp[left][k]+dp[k][right]+nums[left]*nums[k]*nums[right];

                    dp[left][right]=max(dp[left][right],coins);
                }
            }
        }
        return dp[0][n-1];
    }
};