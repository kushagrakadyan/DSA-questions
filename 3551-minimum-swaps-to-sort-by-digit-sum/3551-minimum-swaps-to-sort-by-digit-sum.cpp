class Solution {
public:
    int digitsum(int nums){
       
        int sum=0;
        while(nums>0){
            sum+=nums%10;
            nums/=10;
        }return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int swapcount = 0;
        vector<vector<int>> arr(n, vector<int>(3));
        for (int i = 0; i < n; i++){
            arr[i] = {digitsum(nums[i]), nums[i], i};
        }
        sort(arr.begin(), arr.end());
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++){
            if (visited[i] || arr[i][2] == i){
                continue;
                }
                int j = i;
                int cycleSize = 0;
                while (!visited[j]) { 
                    visited[j] = true;
                    j = arr[j][2];
                    cycleSize++;
                } 
                    swapcount += cycleSize - 1; 
        }
        return swapcount;
        
    }
};