class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
vector<int> sa(n), rank(n), temp(n);

    iota(sa.begin(), sa.end(), 0);

    sort(sa.begin(), sa.end(), [&](int a, int b) {
        return nums[a] < nums[b];
    });

    for(int i = 0; i < n; i++) {
        if(i > 0 && nums[sa[i]] == nums[sa[i-1]])
            rank[sa[i]] = rank[sa[i-1]];
        else
            rank[sa[i]] = i;
    }

    for(int k = 1; k < n; k *= 2) {
        sort(sa.begin(), sa.end(), [&](int a, int b) {
            if(rank[a] != rank[b])
                return rank[a] < rank[b];

            int x = (a + k < n) ? rank[a+k] : -1;
            int y = (b + k < n) ? rank[b+k] : -1;

            return x < y;
        });

        temp[sa[0]] = 0;

        for(int i = 1; i < n; i++) {
            int a = sa[i-1], b = sa[i];

            int x1 = rank[a], x2 = rank[b];
            int y1 = (a+k < n) ? rank[a+k] : -1;
            int y2 = (b+k < n) ? rank[b+k] : -1;

            temp[b] = temp[a] + (x1 != x2 || y1 != y2);
        }

        rank = temp;

        if(rank[sa[n-1]] == n-1)
            break;
    }

    vector<int> lcp(n, 0);
    vector<int> pos(n);

    for(int i = 0; i < n; i++)
        pos[sa[i]] = i;

    int h = 0;

    for(int i = 0; i < n; i++) {
        if(pos[i] == 0) continue;

        int j = sa[pos[i]-1];

        while(i+h < n && j+h < n && nums[i+h] == nums[j+h])
            h++;

        lcp[pos[i]] = h;

        if(h > 0) h--;
    }

    int ans = n;

    for(int i = 0; i < n; i++) {
        int p = pos[i];

        int mx = lcp[p];

        if(p+1 < n)
            mx = max(mx, lcp[p+1]);

        if(mx < n-i)
            ans = min(ans, mx+1);
    }

    return ans;
    }
};