class Solution {
public:
    int f(int i , int sum , vector<int>& stones , vector<vector<int>>& dp ,int total){
        if(i == stones.size()) return abs(sum);
        if(dp[i][sum + total] != -1) return dp[i][sum+total];

        int plus = f(i+1 , sum + stones[i] , stones , dp , total);
        int minus = f(i+1, sum - stones[i] , stones , dp , total);
        
       
        return dp[i][sum+total] = min(plus , minus);
    }
    int lastStoneWeightII(vector<int>& stones) {
        int total = 0;
        int n = stones.size();
        for(int x : stones){
            total += x;
        }

        vector<vector<int>> dp(n , vector<int>(2*total + 1 , -1));
        return f(0 , 0 , stones , dp , total);
    }
};