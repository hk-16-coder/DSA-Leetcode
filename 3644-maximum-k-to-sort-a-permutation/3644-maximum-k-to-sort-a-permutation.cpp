class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int AND = INT_MAX;
   
        for(int i = 0 ; i<n; i++){
            if(nums[i] != i) AND &= nums[i];
        }

        if(AND == INT_MAX) return 0;
        return AND;
    }
};