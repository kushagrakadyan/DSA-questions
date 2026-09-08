class Solution {
public:
    bool dfs(int src,vector<bool>& vis,vector<vector<int>>& edges,vector<bool>& recpath){
        vis[src]=true;
        recpath[src]=true;
        for(int i=0;i<edges.size();i++){
            int v=edges[i][0];
            int u=edges[i][1];

            if(src==u){
                if(!vis[v]){
                    if(dfs(v,vis,edges,recpath)){
                        return true;
                    }
                }
                else if(recpath[v]){
                    return true;
                }
                
            }
        }
        recpath[src]=false;
        return false;
    }
    void topo(int src,vector<bool>& vis,stack<int>& s,vector<vector<int>>& edges,vector<bool>& recpath) {
        vis[src]=true;
        for(int i=0;i<edges.size();i++){
            int v=edges[i][0];
            int u=edges[i][1];

            if(src==u){
                if(!vis[v]){
                    topo(v,vis,s,edges,recpath);
                }
            }
        }
        s.push(src);
    }

    vector<int> findOrder(int n,vector<vector<int>>& edges) {
        vector<bool> vis(n,false);
        vector<bool> recpath(n,false);
        vector<int> ans;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,vis,edges,recpath)){
                    return ans;
                }    
            }
        }
        stack<int> s;
        vis.assign(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                topo(i,vis,s,edges,recpath);
            }
        }
        while(s.size()>0){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    
    }
};