class Solution {
public:
    int dfs(int i , int j , vector<vector<int>>& grid , vector<vector<int>>& vis){
        int m = grid.size();
        int n = grid[0].size();
        vis[i][j] = 1;

        int left = 0 , right = 0 , up = 0 ,down = 0;

        if(i-1 >= 0 && grid[i-1][j] == 1 && !vis[i-1][j]) up = 1 + dfs(i-1 , j , grid , vis);
        if(j-1 >= 0 && grid[i][j-1] == 1 && !vis[i][j-1]) left = 1 + dfs(i , j-1 , grid , vis);
        if(i+1 < m && grid[i+1][j] == 1 && !vis[i+1][j]) down = 1 + dfs(i+1 , j , grid , vis);
        if(j+1 < n && grid[i][j+1] == 1 && !vis[i][j+1]) right = 1 + dfs(i , j+1 , grid , vis);

        return up + down + left + right;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m , vector<int>(n));
        int maxi = 0;
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    int area = 1 + dfs(i , j , grid , vis);
                    maxi = max(maxi , area);
                }
            }
        }
        return maxi;
    }
};