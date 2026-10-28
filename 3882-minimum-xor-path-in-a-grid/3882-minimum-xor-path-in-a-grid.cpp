class Solution {
public:
    int f(int i , int j , int val , vector<vector<int>>& grid , vector<vector<vector<int>>>& dp){
        int m = grid.size();
        int n = grid[0].size();

        if(i>m-1 || j>n-1) return INT_MAX;

        val ^= grid[i][j];
        if(i == m-1 && j == n-1){
            return val;
        }

        if(dp[i][j][val] != -1) return dp[i][j][val];
        
        int right = f(i , j+1 , val , grid , dp);
        int down = f(i+1 , j , val , grid , dp);

        return dp[i][j][val] = min(right , down);
    }
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(m , vector<vector<int>>(n , vector<int>(1024,-1)));
        return f(0 , 0 , 0 , grid , dp);
    }
};