class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        int maxi = 1;

        vector<int> cnt(n,1);
        for(int idx = 0 ; idx<n ; idx++){
            for(int prev = 0 ; prev<idx ; prev++){
                if(nums[prev] < nums[idx]){
                    if(1 + dp[prev] > dp[idx]){
                        cnt[idx] = cnt[prev];
                        dp[idx] = 1 + dp[prev];
                        maxi = max(maxi , dp[idx]);
                    }
                    else if(1 + dp[prev] == dp[idx]){
                        cnt[idx]+=cnt[prev];
                    }
                }
            }
        }
        
        int sum = 0;
        for(int i = 0 ; i<n ; i++){
            if(dp[i] == maxi){
                sum+=cnt[i];
            }
        }
      
        return sum;
    }
};