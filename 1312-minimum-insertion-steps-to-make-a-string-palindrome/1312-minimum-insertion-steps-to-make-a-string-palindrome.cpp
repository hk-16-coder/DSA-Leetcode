class Solution {
public:
    int minInsertions(string s) {
        int n  = s.size();
        vector<vector<int>> dp(n+1 , vector<int>(n+1));

        for(int i = 0 ; i<n ; i++) dp[i][i+1] = 1; // single character
     
        for(int i = n-1 ; i>=0 ; i--){
            for(int j = i+2 ; j<=n ; j++){
                if(s[i] == s[j-1]) dp[i][j] = 2 + dp[i+1][j-1];
                else dp[i][j] = max(dp[i+1][j] , dp[i][j-1]);
            }
        }
        return n - dp[0][n];
    }
};