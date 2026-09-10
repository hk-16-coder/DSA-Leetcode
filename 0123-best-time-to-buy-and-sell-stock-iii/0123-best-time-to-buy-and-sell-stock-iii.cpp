class Solution {
public:
    int f(int idx , int buy , int trans , vector<int>&prices , vector<vector<vector<int>>>& dp){
        if(idx == prices.size()) return 0;
        if(trans == 2) return 0;
        if(dp[idx][buy][trans] != -1) return dp[idx][buy][trans];
        
        if(buy){
            int buy0 = -prices[idx] + f(idx+1 , 0 , trans , prices, dp);
            int dontBuy = f(idx+1 , 1 , trans , prices , dp);
            return dp[idx][buy][trans] = max(buy0 , dontBuy);
        }

        else{
            int sell = prices[idx] + f(idx+1 , 1 , trans+1 , prices , dp);
            int dontSell = f(idx+1 , 0 , trans , prices , dp);
            return dp[idx][buy][trans] = max(sell , dontSell);
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1 , vector<vector<int>> ( 2 , vector<int>(2,-1)));
        return f(0 , 1 , 0 , prices , dp);
    }
};