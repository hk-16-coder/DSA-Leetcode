class Solution {
public:
    const long long MOD = 1e9 + 7;
    int f(int row , int col , int moves , int m , int n , vector<vector<vector<int>>>& dp){
        if(row<0 || row>=m || col<0 || col>=n) return 1;
        if(moves == 0) return 0;
        
        if(dp[moves][row][col] != -1) return dp[moves][row][col];

        long long up = f(row-1,col,moves-1,m,n,dp);
        long long down = f(row+1,col,moves-1,m,n,dp);
        long long right = f(row,col+1,moves-1,m,n,dp);
        long long left = f(row,col-1,moves-1,m,n,dp);

        return dp[moves][row][col] = (up+down+right+left) % MOD;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(maxMove+1 , vector<vector<int>>(m,vector<int>(n,-1)));
        return f(startRow,startColumn,maxMove,m,n,dp);
    }
};