class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0,  j = 0;
        int min_len = INT_MAX;
        long long sum = 0;
        while(j<nums.size() && i<=j){
            sum+=nums[j];
            while(sum >= target && i<=j){
                min_len = min(min_len , j-i+1);
                sum-=nums[i];
                i++;
            }
            j++;
        }
       
        if(min_len != INT_MAX) return min_len;
        return 0;
    }
};