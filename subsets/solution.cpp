class Solution {
public:
    void subsequence(int idx ,vector<int> &nums , vector<int> &temp , int n ,vector<vector<int>> &ans){
        if(idx == n) {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        subsequence(idx+1,nums,temp,n,ans);
        temp.pop_back();
        subsequence(idx+1,nums,temp,n,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        subsequence(0,nums,temp,n,ans);

        return ans;
    }
};