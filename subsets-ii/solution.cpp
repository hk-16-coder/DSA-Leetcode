class Solution {
public:
    vector<vector<int>> ans;
    void subsets(int idx , vector<int>& temp , vector<int>& nums){
        int n = nums.size();
        ans.push_back(temp);
    
        for(int i = idx ; i<n ; i++){
            if(i>idx && nums[i] == nums[i-1]) continue;

            temp.push_back(nums[i]);
            subsets(i+1 , temp , nums);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        subsets(0,temp,nums);
        return ans;
    }
};