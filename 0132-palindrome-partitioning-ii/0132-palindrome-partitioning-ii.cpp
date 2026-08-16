class Solution {
public:
    
    int solve(string s,int i,int n,vector<int> &dp,vector<vector<bool>>& pal){
        if(i==n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int mincost=INT_MAX;
        for(int j=i;j<n;j++){
            if(pal[i][j]){
            int cost=1+solve(s,j+1,n,dp,pal);
            mincost=min(mincost,cost);
            }
        }
        return dp[i]=mincost;
    }
    int minCut(string s) {
        int n=s.size();
        vector<vector<bool>> pal(n, vector<bool>(n, false));
         for(int i = n - 1; i >= 0; i--) {
            for(int j = i; j < n; j++) {

                if(s[i] == s[j] &&
                   (j - i <= 1 || pal[i + 1][j - 1])) {

                    pal[i][j] = true;
                }
            }
        }

        vector<int> dp(n,-1);
        return solve(s,0,n,dp,pal)-1;
    }
};