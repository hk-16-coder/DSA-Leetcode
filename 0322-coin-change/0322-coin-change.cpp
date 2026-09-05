class Solution {
public:
    int f(int idx , int amount  , vector<int>& coins , vector<vector<int>>& dp){
        int n = coins.size();
        
        if(amount == 0){
            return 0;
        }

        if(idx == n || amount < 0) return INT_MAX;
        if(dp[idx][amount] != -1) return dp[idx][amount];

        int notPick = f(idx+1 , amount  , coins , dp); // not pick
        int pick = f(idx  , amount - coins[idx] , coins , dp);  // pick
     
        if(pick != INT_MAX){
            pick++;
        }

        return dp[idx][amount] = min(pick,notPick);
    }
    int coinChange(vector<int>& coins, int amount) {  
        int n = coins.size();       
        vector<vector<int>> dp(n , vector<int>(amount+1 , -1));

        int ans = f(0,amount,coins,dp);

        if(ans == INT_MAX) return -1;
        return ans;
    }
};