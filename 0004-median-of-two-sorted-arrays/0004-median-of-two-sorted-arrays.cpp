class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int m = nums1.size();
        int n = nums2.size();
        int low = 0, high = m;
        while(low <= high) {
            int cut1 = (low + high) / 2;
            int cut2 = (m+n+1)/2 - cut1;
            int l1;
            if(cut1 == 0)
                l1 = INT_MIN;
            else
                l1 = nums1[cut1-1];
            int l2;    
            if(cut2 == 0)
                l2 = INT_MIN;
            else
                l2 = nums2[cut2-1];
            int r1;
            if(cut1 == m)
                r1 = INT_MAX;
            else
                r1 = nums1[cut1];
            int r2;
            if(cut2 == n)
             r2 = INT_MAX;
            else
            r2 = nums2[cut2];

            if(l1 <= r2 && l2 <= r1) {

                if((m+n)%2 == 0)
                    return (max(l1,l2) + min(r1,r2))/2.0;

                return max(l1,l2);
            }
            else if(l1 > r2) {
                high = cut1-1;
            }

            else {
                low = cut1+1;
            }
        }

        return 0.0;
    }
};