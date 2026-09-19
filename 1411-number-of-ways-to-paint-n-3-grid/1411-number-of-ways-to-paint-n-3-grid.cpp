class Solution {
public:
    int MOD = 1e9 + 7;
    long long f(int idx , int prev1 , int prev2 , int prev3 , int n , vector<vector<vector<vector<int>>>>& dp){
        if(idx == n) return 1;
        if(dp[idx][prev1][prev2][prev3] != -1) return dp[idx][prev1][prev2][prev3];
        long long ans = 0;
 
        for(int col1 = 1 ; col1<=3 ; col1++){
            if(col1 == prev1) continue;
            for(int col2 = 1 ; col2<= 3 ; col2++){
                if(col2 == prev2 || col2 == col1) continue;
                for(int col3 = 1 ; col3 <= 3 ; col3++){
                    if(col3 == prev3 || col3 == col2) continue;
                    
                    ans += f(idx+1 , col1 , col2 , col3 , n , dp) % MOD;
                }
            }
        }
        return dp[idx][prev1][prev2][prev3] = ans % MOD;
    }
    int numOfWays(int n) {
        vector<vector<vector<vector<int>>>> dp(n , vector<vector<vector<int>>>(4 , vector<vector<int>>(4 , vector<int>(4 , -1))));
        return f(0 , 0 , 0 , 0 , n , dp);
    }
};