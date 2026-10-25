class Solution {
public:
    bool dfs(int i , int j , vector<vector<int>>& grid , vector<vector<int>>& vis){
        int n = grid.size();
        int m = grid[0].size();
        vis[i][j] = 1;

        bool flag = (i>0 && i< n-1 && j>0 && j<m-1);

        if(j<m-1 && grid[i][j+1] == 0 && !vis[i][j+1]) flag &= dfs(i,j+1,grid,vis); // RIGHT
        if(i<n-1 && grid[i+1][j] == 0 && !vis[i+1][j]) flag &= dfs(i+1,j,grid,vis); // DOWN
        if(j>0 && grid[i][j-1] == 0 && !vis[i][j-1]) flag &= dfs(i,j-1,grid,vis); // LEFT
        if(i>0 && grid[i-1][j] == 0 && !vis[i-1][j]) flag &= dfs(i-1,j,grid,vis); // UP
    
        return flag;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n , vector<int>(m,0));
        int cnt = 0;
        for(int i = 0 ; i<n ;  i++){
            for(int j = 0 ; j<m ; j++){
                if(grid[i][j] == 0 &&  vis[i][j] == 0){    
                    if(dfs(i,j,grid,vis)) cnt++;
                }
            }
        }
        return cnt;
    }
};