class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(),nums.end());

        for(int i = 1 ; i<nums.size() ; i++){
            int diff = nums[i] - nums[i-1];
            if(diff > 1){
                for(int j = 1 ; j<diff ; j++) ans.push_back(nums[i-1] + j);
            }
        }
        return ans;
    }
};