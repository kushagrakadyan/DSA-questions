class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> dist(m,vector<int>(n,-1));
        queue<pair<int,int>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    dist[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            if(x-1>=0 && dist[x-1][y]==-1){
                dist[x-1][y]=dist[x][y]+1;
                q.push({x-1,y});
            }
            if(x+1<m && dist[x+1][y]==-1){
                dist[x+1][y]=dist[x][y]+1;
                q.push({x+1,y});
            }
            if(y-1>=0 && dist[x][y-1]==-1){
                dist[x][y-1]=dist[x][y]+1;
                q.push({x,y-1});
            }
            if(y+1<n && dist[x][y+1]==-1){
                dist[x][y+1]=dist[x][y]+1;
                q.push({x,y+1});
            }
        }
        return dist;
    }
};