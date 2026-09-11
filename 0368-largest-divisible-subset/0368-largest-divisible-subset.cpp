class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1 , vector<int>(n+1));
        sort(nums.begin() , nums.end());

        for(int idx = n-1 ; idx>=0 ; idx--){
            for(int prev_idx = -1 ; prev_idx < idx ; prev_idx++){
                int notTake = dp[idx+1][prev_idx+1];
                int take = 0;
                if(prev_idx == -1 ||  nums[idx] % nums[prev_idx] == 0){
                    take = 1 + dp[idx+1][idx+1];
                }

                dp[idx][prev_idx+1] = max(take , notTake);
            }
        }
        int max_len = dp[0][0];
        vector<int> ans;
        int idx = 0;
        int prev_idx = -1;

        while(idx<n){
            int notTake = dp[idx+1][prev_idx+1];
            int take = 0;

            if(prev_idx == -1 ||  nums[idx] % nums[prev_idx] == 0){
                take = 1 + dp[idx+1][idx+1];
            }
            if(take > notTake){
                ans.push_back(nums[idx]);
                prev_idx = idx;
            }
            idx++;
        }
        return ans;
    }
};