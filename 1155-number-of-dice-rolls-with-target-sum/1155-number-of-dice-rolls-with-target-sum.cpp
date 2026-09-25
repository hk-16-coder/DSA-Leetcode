class Solution {
public:
    int MOD = 1e9 + 7;
    int f(int n , int k , int target , vector<vector<int>>& dp){
        if(target == 0 && n == 0) return 1;
        if(target <= 0 || n == 0) return 0;
        if(dp[n][target] != -1) return dp[n][target];
        long long ans = 0;

        for(int i = 1 ; i<=k ; i++){
           ans += f(n-1 , k , target - i , dp) % MOD;
        }

        return dp[n][target] = ans % MOD;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1 , vector<int>(target + 1 , -1));

        return f(n , k , target , dp) % MOD;
    }
};