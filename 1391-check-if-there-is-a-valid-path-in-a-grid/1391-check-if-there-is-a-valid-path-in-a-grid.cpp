class Solution {
public:
    bool f(int i , int j , vector<vector<int>>& grid , vector<vector<int>>& dp , vector<vector<int>>& vis){
        int m = grid.size();
        int n = grid[0].size();

        if(i == m-1 && j == n-1) return true;
        if(vis[i][j] == 1) return false;  // cycle is detected
        if(vis[i][j] == 2) return dp[i][j];  // vis = 1 means the node is being processed , while 2 means it is already produced
        
        vis[i][j] = 1;
        bool path1 = false , path2 = false;

        if(grid[i][j] == 1){
            if(j-1>=0 && (grid[i][j-1] == 1 || grid[i][j-1] == 4 || grid[i][j-1] == 6)) path1 = f(i , j-1 , grid , dp , vis);
            if(j+1<n && (grid[i][j+1] == 1 || grid[i][j+1] == 3 || grid[i][j+1] == 5)) path2 = f(i , j+1 , grid , dp , vis);
        }

        else if(grid[i][j] == 2){
            if(i-1>=0 && (grid[i-1][j] == 2 || grid[i-1][j] == 3 || grid[i-1][j] == 4)) path1 = f(i-1 , j , grid , dp , vis);
            if(i+1<m && (grid[i+1][j] == 2 || grid[i+1][j] == 5 || grid[i+1][j] == 6)) path2 = f(i+1 , j , grid , dp , vis);
        }

        else if(grid[i][j] == 3){
            if(j-1>=0 && (grid[i][j-1] == 1 || grid[i][j-1] == 4 || grid[i][j-1] == 6)) path1 = f(i , j-1 , grid , dp , vis);
            if(i+1<m && (grid[i+1][j] == 2 || grid[i+1][j] == 5 || grid[i+1][j] == 6)) path2 = f(i+1 , j , grid , dp , vis);
        }

        else if(grid[i][j] == 4){
            if(j+1 < n && (grid[i][j+1] == 1 || grid[i][j+1] == 3 || grid[i][j+1] == 5)) path1 = f(i , j+1 , grid , dp , vis);
            if(i+1<m && (grid[i+1][j] == 2 || grid[i+1][j] == 5 || grid[i+1][j] == 6)) path2 = f(i+1 , j , grid , dp , vis);
        }

        else if(grid[i][j] == 5){
            if(j-1>=0 && (grid[i][j-1] == 1 || grid[i][j-1] == 4 || grid[i][j-1] == 6)) path1 = f(i , j-1 , grid , dp , vis);
            if(i-1>=0 && (grid[i-1][j] == 2 || grid[i-1][j] == 3 || grid[i-1][j] == 4)) path2 = f(i-1 , j , grid , dp , vis);
        }

         else if(grid[i][j] == 6){
            if(j+1<n && (grid[i][j+1] == 1 || grid[i][j+1] == 3 || grid[i][j+1] == 5)) path1 = f(i , j+1 , grid , dp , vis);
            if(i-1>=0 && (grid[i-1][j] == 2 || grid[i-1][j] == 3 || grid[i-1][j] == 4)) path2 = f(i-1 , j , grid , dp , vis);
        }
        
        vis[i][j] = 2;
        return dp[i][j] = path1 || path2;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m , vector<int>(n,-1));
        vector<vector<int>> vis(m , vector<int>(n));
        return f(0 , 0 , grid , dp , vis);
    }
};