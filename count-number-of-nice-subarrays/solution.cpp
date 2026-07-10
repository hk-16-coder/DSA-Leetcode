class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int cnt = 0;
        int odd = 0;
        int left = 0;
        int right = 0;
        int n = nums.size();
        while(right<n){
            if(nums[right]%2 == 1){
                odd++;
                right++;
            }
            else right++;
            while(odd > k){
                if(nums[left]%2 == 1){
                    left++;
                    odd--;
                }
                else left++;
            }
            if(odd == k){ 
                cnt++;
                int start = left;
                while(start<right && nums[start]%2 == 0){
                    start++;
                    cnt++;
                }
            }
        }
       
        return cnt;
    }
};