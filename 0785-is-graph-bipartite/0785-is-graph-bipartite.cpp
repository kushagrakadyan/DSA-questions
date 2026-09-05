class Solution {
public:
    bool bfs(int node,vector<vector<int>>& graph,vector<int>& vis){
        for(int neighbour : graph[node]){
            //neighbour ko group(vis) nhi mila 
            if(vis[neighbour]==-1){
                vis[neighbour]=1-vis[node];

                if(!bfs(neighbour,graph,vis)) return false;
            }
            //neighbour ko group mila hua hai
            else if(vis[neighbour]==vis[node]){
                return false;
            }
        }
        return true;
        
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                    vis[i]=0;
                    if(!bfs(i,graph,vis)) return false;
            }
        }    
        return true;
    }
};