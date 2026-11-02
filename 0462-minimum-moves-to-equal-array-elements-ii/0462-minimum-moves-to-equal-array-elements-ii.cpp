class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        sort(nums.begin(),nums.end());
        int mid=n/2;
        int median=nums[mid];
        for(int i=0;i<n;i++){
            if(nums[i]<median){
            sum+=median-nums[i];
            }
            else{
                sum+=nums[i]-median;
            }
        }
        return sum;
    }
};