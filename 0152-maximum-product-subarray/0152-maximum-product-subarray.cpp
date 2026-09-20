class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[0];
        int mini = nums[0];
        int ans = nums[0];
        
        for(int i = 1 ; i<n ; i++){
            int newMaxi = max(nums[i] , max(nums[i]*maxi , nums[i]*mini));

            int newMini = min(nums[i] , min(nums[i]*maxi , nums[i]*mini));
            maxi = newMaxi;
            mini = newMini;
            ans = max(ans , maxi);
        }

        return ans;
    }
};