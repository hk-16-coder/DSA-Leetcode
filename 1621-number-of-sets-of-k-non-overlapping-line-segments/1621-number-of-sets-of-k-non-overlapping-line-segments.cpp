class Solution {
public:
    int MOD = 1e9 + 7;
    int f(int idx , int start , int n , int k , vector<vector<vector<int>>>& dp){
        if(k == 0) return 1;
        if(idx == n) return 0;

        if(dp[idx][start][k] != -1) return dp[idx][start][k];
       
        long long ans = 0;
        if(start == 1){
           ans += f(idx , 0 , n , k-1 , dp) % MOD;
           ans += f(idx+1 , 1 , n , k , dp) % MOD;
        }
        else{
            ans += f(idx+1 , 1 , n , k , dp) % MOD;
            ans += f(idx+1 , 0 , n , k , dp) % MOD;
        }

        return dp[idx][start][k] =  ans % MOD;
    }
    int numberOfSets(int n, int k) {
        vector<vector<vector<int>>> dp(n , vector<vector<int>>(2 , vector<int>(k+1 , -1)));
        return f(0 , 0 , n , k , dp);
    }
};