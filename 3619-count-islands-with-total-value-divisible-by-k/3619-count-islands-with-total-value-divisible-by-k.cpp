class Solution {
public:
    long long dfs(int i , int j , vector<vector<int>>& grid , vector<vector<int>>& vis){
        int m = grid.size();
        int n = grid[0].size();

        vis[i][j] = 1;
        long long sum = grid[i][j];

        if(j<n-1 && grid[i][j+1] > 0 && !vis[i][j+1]) sum += dfs(i,j+1,grid,vis); // RIGHT
        if(i<m-1 && grid[i+1][j] > 0 && !vis[i+1][j]) sum += dfs(i+1,j,grid,vis); // DOWN
        if(j>0 && grid[i][j-1] > 0 && !vis[i][j-1]) sum += dfs(i,j-1,grid,vis); // LEFT
        if(i>0 && grid[i-1][j] > 0 && !vis[i-1][j]) sum += dfs(i-1,j,grid,vis); // UP

        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m , vector<int>(n,0));
        int cnt = 0;

        for(int i = 0 ; i<m; i++){
            for(int j = 0 ; j<n ; j++){
                if(grid[i][j] > 0 && !vis[i][j]){
                    long long score = dfs(i , j , grid , vis);
                    if(score % k == 0) cnt++;
                }
            }
        }

        return cnt;
    }
};