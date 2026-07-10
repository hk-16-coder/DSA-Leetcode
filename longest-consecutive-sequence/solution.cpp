class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int cnt = 1;
        int max_cnt = 1;
        int n = nums.size();
        if(n==0) return 0;
        sort(nums.begin(),nums.end());
        for(int i = 0 ; i<n-1  ; i++){
                if(nums[i] == nums[i+1] - 1){
                    cnt++;
                    max_cnt = max(max_cnt,cnt);
                }
                else if (nums[i] == nums[i+1]) continue;
                else cnt = 1;
        }
        return max_cnt;
    }
};