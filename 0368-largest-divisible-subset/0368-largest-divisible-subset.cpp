class Solution {
public:
    int solve(vector<int>& nums, int i, int j, vector<vector<int>> &dp) {
        if (i == nums.size()) return 0;

        if (dp[i][j + 1] != -1) {
            return dp[i][j + 1];
        }

        int skip = solve(nums, i + 1, j, dp);

        int take = 0;
        if (j == -1 || nums[i] % nums[j] == 0) { 
            take = 1 + solve(nums, i + 1, i, dp);
        }

        return dp[i][j + 1] = max(take, skip);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};

        sort(nums.begin(), nums.end());

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        solve(nums, 0, -1, dp);
        vector<int> result;
        int j = -1;

        for (int i = 0; i < n; ++i) {
            if (j == -1 || nums[i] % nums[j] == 0) {
                int takeLength = 1 + solve( nums,i + 1, i, dp);
                int skipLength = solve(nums,i + 1, j, dp);

                if (takeLength >= skipLength && takeLength == dp[i][j + 1]) {
                    result.push_back(nums[i]);
                    j = i;
                }
            }
        }
        return result;
    }
};