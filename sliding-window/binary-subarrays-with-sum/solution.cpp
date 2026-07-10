class Solution {
public:
    int count(vector<int>& nums, int goal){
        // counts subarrays less than equal to goal
        if(goal<0) return 0;
        int sum = 0;
        int left = 0;
        int right = 0;
        int n = nums.size();
        int cnt = 0;
        while(right<n){ 
            sum+=nums[right];
            while(sum>goal){
                sum = sum - nums[left];
                left++;
            }
            if(sum<=goal) cnt+=right-left+1;
            right++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return count(nums,goal) - count(nums,goal-1);
    }
};