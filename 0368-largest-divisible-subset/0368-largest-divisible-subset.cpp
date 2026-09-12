class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n = nums.size();

        vector<int> dp(n,1) , hash(n);
        int maxi = 1 , lastIdx = 0;
        for(int i = 0 ; i<n ; i++){
            hash[i] = i;
            for(int j = 0 ; j<i ; j++){
                if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                lastIdx = i;
            }
        }

        vector<int> ans;
        while(hash[lastIdx] != lastIdx){
            ans.push_back(nums[lastIdx]);
            lastIdx = hash[lastIdx];
        }
        
        ans.push_back(nums[lastIdx]);
        return ans;
    }
};