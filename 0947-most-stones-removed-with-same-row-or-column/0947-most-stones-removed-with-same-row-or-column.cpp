class DisjointSet {
    vector<int> parent, size;

public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv)
            return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        int OFFSET = 10001;
        int MAXN = 20005;

        DisjointSet ds(MAXN);

        unordered_set<int> nodes;

        for (auto &stone : stones) {
            int row = stone[0];
            int col = stone[1] + OFFSET;

            ds.unionBySize(row, col);

            nodes.insert(row);
            nodes.insert(col);
        }

        int components = 0;

        for (int node : nodes) {
            if (ds.findParent(node) == node)
                components++;
        }

        return n - components;
    }
};