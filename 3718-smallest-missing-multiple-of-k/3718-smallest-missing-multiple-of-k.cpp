class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        // sort(nums.begin(),nums.end());
        // int ans=0;
        // for(int j=n-1;j>=0;j--){
        //     if(nums[j]==k){
        //         return k;
        //     }
        //     if(nums[j]%k==0){
        //         ans=nums[j]+k;
        //     }
        //     else{
        //         j--;
        //     }
        // }
        // return ans;
        unordered_set<int> st;
        
        for(int i=0;i<n;i++){
        st.insert(nums[i]);
        }
        int ans=k;
        while(st.find(ans)!=st.end()){
            ans+=k;
        }
        return ans;
    }
};