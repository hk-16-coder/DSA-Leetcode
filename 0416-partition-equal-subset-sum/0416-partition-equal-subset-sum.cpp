class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0 ;
        int n = nums.size();
        for(int x : nums){
            sum+=x;
        }
        if(sum%2 == 1) return false;

        int k = sum/2;
        
        vector<vector<bool>> dp(n,vector<bool>(sum+1,0));

        for(int i = 0 ; i<n; i++){
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;

        for(int idx = 1 ; idx<n ; idx++){
            for(int target = 1 ; target<=k ; target++){
                bool notPick = dp[idx-1][target];
                bool pick = false;
                if(nums[idx] <= target) pick = dp[idx-1][target - nums[idx]];

                dp[idx][target] = notPick || pick;
            }
        }

        return dp[n-1][k];
    }
};