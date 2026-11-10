class Solution {
public:
    int f(int i , vector<int>& costs , vector<int>& dp){
        int n = costs.size();
        if(i == 0) return 0;
        if(dp[i] != -1) return dp[i];
    
        int s1 = INT_MAX , s2 = INT_MAX, s3 = INT_MAX;
        if(i-1 >= 0) s1 = costs[i-1] + 1 + f(i-1 , costs , dp);
        if(i-2 >= 0) s2 = costs[i-1] + 4 + f(i-2 , costs , dp);
        if(i-3 >= 0) s3 = costs[i-1] + 9 + f(i-3 , costs , dp);

        return dp[i] = min(s1 , min(s2,s3));
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1,-1);
        return f(n , costs , dp);
    }
};