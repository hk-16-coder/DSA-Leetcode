class Solution {
public:
    int f(int idx , int n , vector<vector<int>>& dp){
        if(idx == 1){
            return n;
        }
        
        if(dp[idx][n] != -1) return dp[idx][n];

        int notTake = f(idx-1 , n , dp);
        int take = 1e9;
        if(idx*idx <= n){
            take = 1 + f(idx , n - idx*idx , dp);
        }

        return dp[idx][n] = min(take,notTake);
    }
    int numSquares(int n) {
        int idx = sqrt(n);
        vector<vector<int>> dp(idx + 1, vector<int>(n+1,-1));
        return f(idx,n,dp); 
    }
};