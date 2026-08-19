class Solution {
public:
        int countSquares(vector<vector<int>>& matrix) {
        if(matrix.empty()) return 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        vector<vector<int>> dp(rows,vector<int>(cols,0));
        int ans=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]==1){ 
                    if(i==0 || j==0){
                        dp[i][j]=1;
                    }
                    else{
                        dp[i][j]=1+min({dp[i-1][j-1],dp[i][j-1],dp[i-1][j]});
                    }
                }
                ans+=dp[i][j];
            }
            
            
        }return ans;
    }
};