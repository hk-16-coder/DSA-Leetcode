class Solution {
public:
    int MOD = 1e9 + 7;
    int dfs(int i , int j , bool flag , vector<vector<int>>& grid , vector<vector<vector<int>>>& dp){
        // flag = true (right) , flag = false(down)
        int m = grid.size();
        int n = grid[0].size();

        if(i == m-1 && j == n-1) return 1;
        if(i>=m || j>=n) return 0;
        if(dp[i][j][flag] != -1) return dp[i][j][flag];

        long long right = 0 , down = 0;
        if(grid[i][j] == 1){
            if(flag){
                down += dfs(i+1 , j , false , grid , dp);
            }
            else{
                right += dfs(i , j+1 , true , grid , dp);
            }
        }

        else{
            down += dfs(i+1 , j , false , grid , dp);
            right += dfs(i , j+1 , true , grid , dp);
        }

        return dp[i][j][flag] =  (down + right) % MOD;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(m , vector<vector<int>>(n , vector<int>(2 , -1))); 
        return dfs(0 , 0 , true , grid , dp);
    }
};