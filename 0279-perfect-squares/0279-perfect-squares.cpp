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
        int nums = sqrt(n);
        vector<vector<int>> dp(nums + 1, vector<int>(n+1));
    
        for(int i = 1 ; i<=n ; i++){
            dp[0][i] = 1e9;
        }

        for(int idx = 1 ; idx<=nums ; idx++){
            for(int T = 1 ; T<=n ; T++){
                int notTake = dp[idx-1][T];
                int take = 1e9;
                if(idx*idx <= T){
                     take = 1 + dp[idx][T - idx*idx];
                }

               dp[idx][T] = min(take,notTake);
            }
        }
        return dp[nums][n];
    }
};