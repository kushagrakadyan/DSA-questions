class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        int positiveindex=0;
        int negativeindex=1;
        vector<int> result(n);
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                result[positiveindex]=nums[i];
                positiveindex+=2;
            }
            else{
                result[negativeindex]=nums[i];
                negativeindex+=2;
            }
        
        }
        return result;
    }
};