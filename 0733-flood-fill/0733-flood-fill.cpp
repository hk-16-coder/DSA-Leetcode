class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int old_color = image[sr][sc];

        dfs(sr,sc,old_color,color,image,vis);
        return image;
    }

    void dfs(int i , int j , int old_color , int color , vector<vector<int>>& image , vector<vector<int>>& vis){
        int n = image.size();
        int m = image[0].size();
        vis[i][j] = 1;
        image[i][j] = color;
        if(i>0 && image[i-1][j] == old_color && !vis[i-1][j]) dfs(i-1,j,old_color,color,image,vis);
        if(i<n-1 && image[i+1][j] == old_color && !vis[i+1][j]) dfs(i+1,j,old_color,color,image,vis);
        if(j>0 && image[i][j-1] == old_color && !vis[i][j-1]) dfs(i,j-1,old_color,color,image,vis);
        if(j<m-1 && image[i][j+1] == old_color && !vis[i][j+1]) dfs(i,j+1,old_color,color,image,vis);
    }
};