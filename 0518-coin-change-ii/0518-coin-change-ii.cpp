class Solution {
public:
    int f(int idx , int amount , vector<int>& coins , vector<vector<int>>& dp){
        int n = coins.size();
        
        if(amount == 0){
            return 1;
        }

        if(idx == n || amount < 0) return 0 ;
        if(dp[idx][amount] != -1) return dp[idx][amount] ;

        int notPick = f(idx+1 , amount  , coins , dp); // not pick
        int pick = f(idx  , amount - coins[idx] , coins , dp);  // pick
        
        return dp[idx][amount] = pick + notPick;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();       
        vector<vector<int>> dp(n , vector<int>(amount+1 , -1));
        
        return f(0,amount,coins,dp);
    }
};