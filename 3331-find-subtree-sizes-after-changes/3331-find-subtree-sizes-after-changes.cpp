class Solution {
public:
    vector<int> answer;
    void dfs(int node, vector<vector<int>>& adj, string& s,
             vector<int>& last, vector<int>& newParent) {
        int c = s[node] - 'a';
        int prev = last[c];
        if (node != 0 && prev != -1)
            newParent[node] = prev;
        last[c] = node;
        for (int child : adj[node]) {
            dfs(child, adj, s, last, newParent);
        }
        last[c] = prev;
    }
    int calc(int node, vector<vector<int>>& adj) {
        int size = 1;
        for (int child : adj[node]) {
            size += calc(child, adj);
        }
        answer[node] = size;
        return size;
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }
        vector<int> last(26, -1);
        vector<int> newParent = parent;
        dfs(0, adj, s, last, newParent);
        vector<vector<int>> finalTree(n);
        for (int i = 1; i < n; i++) {
            finalTree[newParent[i]].push_back(i);
        }
        answer.resize(n);
        calc(0, finalTree);
        return answer;
    }
};