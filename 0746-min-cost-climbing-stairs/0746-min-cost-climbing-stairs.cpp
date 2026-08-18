class Solution {
public:
    int climb(int ind , vector<int>& dp , vector<int>& cost){
        if(ind == 0 || ind == 1) return 0;
        if(dp[ind] != -1) return dp[ind];

        int left = climb(ind-1,dp,cost) + cost[ind-1];
        int right = INT_MAX;
        if(ind>1) right = climb(ind-2,dp,cost) + cost[ind-2];

        return dp[ind] = min(left,right);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);

        return climb(n,dp,cost);
    }
};