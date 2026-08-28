class Solution {
private:    
       void dfs(int node,vector<vector<int>>& isConnected,vector<int>& visited){
            visited[node]=1;
            for(int j=0;j<isConnected.size();j++){
                if(isConnected[node][j]==1 && !visited[j]){
                    dfs(j,isConnected,visited);
                }
            }
       }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v=isConnected.size();
        vector<int> visited(v,0);
        int province=0;
        for(int i=0;i<v;i++){
            if(!visited[i]){
                dfs(i,isConnected,visited);
                province++;
            }
        }
        return province;
    }
};