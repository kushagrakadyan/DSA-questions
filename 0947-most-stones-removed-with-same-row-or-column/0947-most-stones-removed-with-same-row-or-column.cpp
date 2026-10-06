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

        int maxRow = 0;
        int maxCol = 0;

        for (auto it : stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        // Row: 0 ... maxRow
        // Col: maxRow+1 ... maxRow+1+maxCol

        DisjointSet ds(maxRow + maxCol + 1);

        unordered_map<int, int> stoneNodes;

        for (auto it : stones) {

            int nodeRow = it[0];

            int nodeCol = it[1] + maxRow + 1;

            ds.unionBySize(nodeRow, nodeCol);

            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }

        int cnt = 0;

        for (auto it : stoneNodes) {

            if (ds.findParent(it.first) == it.first) {
                cnt++;
            }
        }

        return n - cnt;
    }
};