class Solution {
public:
    int f(int idx , int buy , int cooldown , vector<int>& prices , vector<vector<vector<int>>>& dp){
        if(idx == prices.size()) return 0;
        if(dp[idx][buy][cooldown] != -1) return dp[idx][buy][cooldown];

        if(buy){
            if(cooldown == 0){
                return dp[idx][buy][cooldown] = max(-prices[idx] + f(idx+1 , 0, 0 , prices, dp) , f(idx+1 ,1 , 0 , prices,dp));
            }
            else return dp[idx][buy][cooldown] = f(idx+1 , 1 , 0 , prices , dp);
        }

        else{
            return dp[idx][buy][cooldown] = max(prices[idx] + f(idx+1 , 1 , 1 , prices ,dp) , f(idx+1 , 0  , 0 , prices ,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n , vector<vector<int>>(2 , vector<int>(2,-1)));

        return f(0 , 1 , 0 , prices , dp);
    }
};