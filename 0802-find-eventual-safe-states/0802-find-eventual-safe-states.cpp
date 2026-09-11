class Solution {
public:
    bool iscycle(int src,vector<bool>& vis,vector<bool> &recpath,vector<vector<int>>& graph,vector<bool>& safe){
        vis[src]=true;
        recpath[src]=true;

        for (auto v : graph[src]) {
            
                if(!vis[v]){
                    if(iscycle(v,vis,recpath,graph,safe)){
                        return true;
                    }
                }
                else if(recpath[v]){
                    return true;
                }
            
        }
        recpath[src]=false;
        safe[src]=true;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
       
        int n=graph.size();
        vector<bool> vis(n,false);
        vector<bool> recpath(n,false);
        vector<bool> safe(n, false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                iscycle(i,vis,recpath,graph,safe);
            }
        }
        vector<int> safenode;
        for(int i=0;i<n;i++){
            if(safe[i]){
            safenode.push_back(i);
            }
        }
        return safenode;
    }
};