class Solution {
public:
    int f(int idx , int target , vector<int>& nums , vector<vector<int>>& dp , int sum){
        if(idx == nums.size()) return target == 0;

        if(target > sum || target + sum < 0) return 0;

        if(dp[idx][target+sum] != -1) return dp[idx][target + sum];

        int plus = f(idx+1 , target - nums[idx] , nums , dp , sum);
        int minus = f(idx+1,target + nums[idx] , nums , dp , sum);

        return dp[idx][target+sum] = plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(int x : nums){
            sum+=x;
        }

        if(abs(target) > sum) return 0; // not possible;
        vector<vector<int>> dp(n , vector<int>(2*sum+1,-1));

        return f(0,target,nums,dp, sum);
    }
};