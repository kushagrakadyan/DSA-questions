class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n=nums.size();
        int ans=0;

        for(int i=0;i<n;i++){
            bool valid=true;

            for(int j=i;j<n;j++){
                if(j-i>=2){
                    for(int k=i;k<j;k++){
                        if(gcd(nums[k],nums[j])!=1){
                            valid=false;
                            break;
                        }
                    }

                    if(j==i+2 && gcd(nums[i],nums[i+1])!=1){
                        valid=false;
                    }
                }

                if(!valid) break;

                ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};