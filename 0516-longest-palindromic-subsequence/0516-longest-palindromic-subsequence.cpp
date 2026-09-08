class Solution {
public:
    // int f(int idx1 , int idx2 , string& s , vector<vector<int>>& dp){
    //     if(idx1 == s.size() || idx2 < 0) return 0;
    //     if(dp[idx1][idx2] != -1) return dp[idx1][idx2];

    //     if(s[idx1] == s[idx2]) return dp[idx1][idx2] =  1 + f(idx1  + 1 , idx2 - 1 , s , dp);

    //     return dp[idx1][idx2] =  max(f(idx1+1 , idx2 , s , dp) , f(idx1 , idx2 - 1 , s , dp));
    // }
    int longestPalindromeSubseq(string s) {
        int n  = s.size();
        vector<vector<int>> dp(n+1 , vector<int>(n+1));

        for(int i = 0 ; i<n ; i++) dp[i][i+1] = 1; // single character
     
        for(int i = n-1 ; i>=0 ; i--){
            for(int j = i+2 ; j<=n ; j++){
                if(s[i] == s[j-1]) dp[i][j] = 2 + dp[i+1][j-1];
                else dp[i][j] = max(dp[i+1][j] , dp[i][j-1]);
            }
        }
        return dp[0][n];
    }
};