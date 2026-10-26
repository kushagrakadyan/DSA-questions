class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n=numRows;
        vector<vector<int>> result;
        for(int i=0;i<n;i++){
            vector<int> results(i+1,1);
            for(int j=1;j<i;j++){
                results[j]=result[i-1][j-1]+result[i-1][j];
            }
            result.push_back(results
            );
        }
        return result;
    }
};