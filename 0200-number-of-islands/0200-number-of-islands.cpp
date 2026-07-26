class Solution {
public:
    void dfs(int i , int j , vector<vector<char>>& grid , vector<vector<int>>& vis){
        int n = grid.size();
        int m = grid[0].size();
        vis[i][j] = 1;
        if(j<m-1 && grid[i][j+1] == '1' && !vis[i][j+1]) dfs(i,j+1,grid,vis); // RIGHT
        if(i<n-1 && grid[i+1][j] == '1' && !vis[i+1][j]) dfs(i+1,j,grid,vis); // DOWN
        if(j>0 && grid[i][j-1] == '1' && !vis[i][j-1]) dfs(i,j-1,grid,vis); // LEFT
        if(i>0 && grid[i-1][j] == '1' && !vis[i-1][j]) dfs(i-1,j,grid,vis); // UP
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n , vector<int>(m,0));
        int cnt = 0;
        for(int i = 0 ; i<n ;  i++){
            for(int j = 0 ; j<m ; j++){
                if(grid[i][j] == '1' &&  vis[i][j] == 0){
                    cnt++;
                    dfs(i,j,grid,vis);
                }
            }
        }
        return cnt;
    }
};