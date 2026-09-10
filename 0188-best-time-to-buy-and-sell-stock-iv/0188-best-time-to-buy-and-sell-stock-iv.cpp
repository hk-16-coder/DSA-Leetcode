class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
         int n = prices.size();
        vector<vector<vector<int>>> dp(n+1 , vector<vector<int>> ( 2 , vector<int>(k+1)));
        //return f(0 , 1 , 0 , prices , dp);

        for(int idx = n-1 ; idx>=0 ; idx--){
            for(int buy = 0 ; buy<=1 ; buy++){
                for(int trans = 0 ; trans<k ; trans++){
                    long long profit = 0;
                    if(buy){
                        profit = max(-prices[idx] + dp[idx+1][0][trans] , dp[idx+1][1][trans]);
                    }

                    else{
                        profit = max(prices[idx] + dp[idx+1][1][trans+1] , dp[idx+1][0][trans]);
                    }
                    dp[idx][buy][trans] = profit;
                }
            }
        }
        return dp[0][1][0];
    }
};