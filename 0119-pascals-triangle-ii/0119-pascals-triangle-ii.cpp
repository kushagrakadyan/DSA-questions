class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> results={1};
        for(int i=1;i<=rowIndex;i++){
            vector<int> result(i+1,1);
            for(int j=1;j<i;j++){
                result[j]=results[j-1]+results[j];
            }
            results=result;
        }
        return results;
     
    }
};