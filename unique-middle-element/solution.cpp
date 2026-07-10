class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int idx = nums.size()/2;
        for(int i = 0 ; i<nums.size() ; i++){
            if(nums[i] == nums[idx] && i!=idx) return false;
        }
        return true;
    }
};