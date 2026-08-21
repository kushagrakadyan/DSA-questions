class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr1;
        vector<int> arr2;
        
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        for(int i=2;i<n;i++){
            if(arr2.back()>arr1.back()){
                arr2.push_back(nums[i]);
            }
            else{
                arr1.push_back(nums[i]);
            }
        }  
        vector<int> result;  
        result.reserve(n);
        result.insert(result.end(),arr1.begin(),arr1.end());
        result.insert(result.end(),arr2.begin(),arr2.end());
        
    return result;
    }
    
};