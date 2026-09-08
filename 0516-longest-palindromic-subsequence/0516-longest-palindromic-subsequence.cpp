class Solution {
public:
    int f(int idx1 , int idx2 , string& s , vector<vector<int>>& dp){
        if(idx1 == s.size() || idx2 < 0) return 0;
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];

        if(s[idx1] == s[idx2]) return dp[idx1][idx2] =  1 + f(idx1  + 1 , idx2 - 1 , s , dp);

        return dp[idx1][idx2] =  max(f(idx1+1 , idx2 , s , dp) , f(idx1 , idx2 - 1 , s , dp));
    }
    int longestPalindromeSubseq(string s) {
        int n  = s.size();
        vector<vector<int>> dp(n , vector<int>(n,-1));
        return f(0 , n - 1 , s , dp);
    }
};