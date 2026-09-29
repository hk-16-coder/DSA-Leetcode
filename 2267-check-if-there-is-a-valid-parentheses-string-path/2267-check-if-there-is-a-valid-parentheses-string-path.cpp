class Solution {
public:
    bool f(int i , int j , int score , vector<vector<char>>& grid ,  vector<vector<vector<int>>>& dp){
        int m = grid.size();
        int n = grid[0].size();
        
        if(grid[i][j] == '(') score += 1;
        else score -= 1;

        if(score < 0) return false;
        if(i == m-1 && j == n-1){
            if(score == 0) return true;
            return false;
        }

        if(dp[i][j][score] != -1) return dp[i][j][score];
        bool down = false , right = false;
        if(i<m-1) down = f(i+1 , j , score , grid , dp);
        if(j < n-1) right = f(i , j+1 , score , grid , dp);

        return dp[i][j][score] = down || right;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(m , vector<vector<int>>(n , vector<int>(m+n , -1)));
        return f(0 , 0 , 0 , grid , dp);
    }
};