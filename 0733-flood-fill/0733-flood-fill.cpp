class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc,int oldcolor, int color){
        int m=image.size();
        int n=image[0].size();
        if(sr<0 || sc<0 || sr>=m || sc>=n || image[sr][sc]!=oldcolor || image[sr][sc]==color){
            return;
        }
        image[sr][sc]=color;
        dfs(image,sr-1,sc,oldcolor,color);
        dfs(image,sr+1,sc,oldcolor,color);
        dfs(image,sr,sc-1,oldcolor,color);
        dfs(image,sr,sc+1,oldcolor,color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image,sr,sc,image[sr][sc],color);
        return image;
        
    }
};