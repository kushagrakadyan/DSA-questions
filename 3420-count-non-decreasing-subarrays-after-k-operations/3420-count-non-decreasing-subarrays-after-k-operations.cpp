class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int LOG=18;
        vector<long long> pref(n+1,0);
        for(int i=0;i<n;i++){
            pref[i+1]=pref[i]+nums[i];
        }
        vector<int> nxt(n,n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i]) st.pop();
            if(!st.empty()) nxt[i]=st.top();
            st.push(i);
        }
        vector<vector<int>> jump(LOG,vector<int>(n+1,n));
        vector<vector<long long>> cost(LOG, vector<long long>(n+1,0));
        for (int i = 0; i < n; i++) {
            jump[0][i] = nxt[i];

            cost[0][i] = 1LL * nums[i] * (nxt[i] - i)
                       - (pref[nxt[i]] - pref[i]);
        }

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                int mid = jump[j - 1][i];

                jump[j][i] = jump[j - 1][mid];

                cost[j][i] = cost[j - 1][i]
                           + cost[j - 1][mid];
            }
        }

        auto getCost = [&](int l, int r) {
            int R = r + 1;
            long long ans = 0;

            for (int j = LOG - 1; j >= 0; j--) {
                if (jump[j][l] <= R) {
                    ans += cost[j][l];
                    l = jump[j][l];
                }
            }

            if (l < R) {
                ans += 1LL * nums[l] * (R - l)
                     - (pref[R] - pref[l]);
            }

            return ans;
        };

        long long ans = 0;

        for (int r = 0; r < n; r++) {
            int low = 0, high = r;

            while (low < high) {
                int mid = low + (high - low) / 2;

                if (getCost(mid, r) <= k)
                    high = mid;
                else
                    low = mid + 1;
            }

            ans += r - low + 1;
        }

        return ans;
    }
};