class Solution {
public:
    bool iscycle(int curr, vector<bool>& vis,vector<vector<int>>& adj,vector<bool>& recpath){
        vis[curr]=true;
        recpath[curr]=true;
        

        for(int v: adj[curr]){
            if(!vis[v]){
                if(iscycle(v,vis,adj,recpath)){
                return true;
                }
            }
            else if(recpath[v]){
                return true;
            }
        }
        recpath[curr]=false;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto edge:edges){
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> vis(n,false);
        vector<bool> recpath(n,false);
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(iscycle(i,vis,adj,recpath)) return false;
            }
        }
        return true;
    }
};