class Solution {
public:
    multiset<long long> low, high;
    long long sumLow = 0, sumHigh = 0;

    void balance() {
        while (low.size() > high.size() + 1) {
            long long val = *low.rbegin();
            low.erase(low.find(val));
            sumLow -= val;
            high.insert(val);
            sumHigh += val;
        }
        while (low.size() < high.size()) {
            long long val = *high.begin();
            high.erase(high.find(val));
            sumHigh -= val;
            low.insert(val);
            sumLow += val;
        }
    }

    void add(int val) {
        if (low.empty() || val <= *low.rbegin()) {
            low.insert(val);
            sumLow += val;
        } else {
            high.insert(val);
            sumHigh += val;
        }
        balance();
    }

    void remove(int val) {
        auto it = low.find(val);
        if (it != low.end()) {
            low.erase(it);
            sumLow -= val;
        } else {
            it = high.find(val);
            high.erase(it);
            sumHigh -= val;
        }
        balance();
    }

    long long getCost() {
        long long median = *low.rbegin();
        return median * low.size() - sumLow +
               sumHigh - median * high.size();
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        vector<long long> cost(n - x + 1);

        for (int i = 0; i < n; i++) {
            add(nums[i]);

            if (i >= x) {
                remove(nums[i - x]);
            }

            if (i >= x - 1) {
                cost[i - x + 1] = getCost();
            }
        }

        const long long INF = 1e18;

        vector<long long> prev(n + 1, 0);
        vector<long long> curr(n + 1, INF);

        for (int j = 1; j <= k; j++) {
            fill(curr.begin(), curr.end(), INF);

            for (int i = 1; i <= n; i++) {
                curr[i] = curr[i - 1];

                if (i >= x && prev[i - x] != INF) {
                    curr[i] = min(curr[i],
                    prev[i - x] + cost[i - x]);
                }
            }

            prev.swap(curr);
        }

        return prev[n];
    }
};