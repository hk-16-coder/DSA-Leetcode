class Solution {
public:
    int f(int idx , int holding , vector<int>&prices , vector<vector<int>>& dp){
            if(idx == prices.size()) return 0;
            if(dp[idx][holding] != -1) return dp[idx][holding];
           
            if(holding == 0){
                // buy or dont buy
                int skip = f(idx+1 , 0 , prices , dp);
                int buy = -prices[idx] + f(idx+1 , 1 , prices, dp);
                return dp[idx][holding] =  max(buy,skip);
            }
            else{
                int skip = f(idx+1,  1 , prices , dp);
                int sell = prices[idx] + f(idx+1 , 0 , prices , dp);
                return dp[idx][holding] = max(skip,sell);
            }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1 , vector<int>(2,-1));
        return f(0 , 0 , prices , dp);
    }
};