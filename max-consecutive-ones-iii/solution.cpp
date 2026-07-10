class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int max_len = 0;
        int zeroes = 0;
        while(right<n){
            if(nums[right] == 1)right++;
            else{
                right++;
                zeroes++;
            }
            if(zeroes>k){
                if(nums[left] == 1) left++;
                else {
                    left++;
                    zeroes--;
                }
            }
            max_len = max(max_len,right-left);
        }
        return max_len;
    }
};