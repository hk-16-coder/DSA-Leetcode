class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt0 = 0;
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i = 0 ; i<nums.size(); i++){
            if(nums[i] == 0)cnt0++;
            else if(nums[i] == 1)cnt1++;
            else cnt2++;
        }
        for(int i = 0; i< nums.size() ; i++){
            if(i<cnt0) nums[i] = 0;
            else if (i>=cnt0 && i<cnt0+cnt1) nums[i] = 1;
            else nums[i] = 2;
        }
    }
};