class Solution {
public:

    bool iscycle(int src, vector<bool>& vis,vector<bool>& recpath,vector<vector<int>>& edges) {

        vis[src] = true;
        recpath[src] = true;

        for(int i = 0; i < edges.size(); i++) {

            int v = edges[i][0];
            int u = edges[i][1];

            if(u == src) {

                if(!vis[v]) {
                    if(iscycle(v, vis, recpath, edges)) {
                        return true;
                    }
                }
                else if(recpath[v]) {
                    return true;
                }
            }
        }

        recpath[src] = false;
        return false;
    }

    void topo(int src,vector<bool>& vis,stack<int>& s,vector<vector<int>>& edges) {

        vis[src] = true;

        for(int i = 0; i < edges.size(); i++) {

            int v = edges[i][0];
            int u = edges[i][1];

            if(u == src) {

                if(!vis[v]) {
                    topo(v, vis, s, edges);
                }
            }
        }

        s.push(src);
    }

    vector<int> findOrder(int numCourses,
                          vector<vector<int>>& prerequisites) {

        vector<bool> vis(numCourses, false);
        vector<bool> recpath(numCourses, false);

        vector<int> ans;

        for(int i = 0; i < numCourses; i++) {

            if(!vis[i]) {

                if(iscycle(i, vis, recpath, prerequisites)) {
                    return {};
                }
            }
        }
        stack<int> s;

        vis.assign(numCourses, false);

        for(int i = 0; i < numCourses; i++) {

            if(!vis[i]) {
                topo(i, vis, s, prerequisites);
            }
        }

        while(!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};