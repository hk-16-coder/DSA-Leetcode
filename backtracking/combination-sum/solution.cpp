class Solution {
public:
    vector<vector<int>> ans;
    void combinations (int idx, int temp_sum, vector<int>& temp, vector<int>& candidates, int target){
           int n = candidates.size();
           if(temp_sum > target || idx >= n) return;
           if(temp_sum == target)  ans.push_back(temp);
            
           else{
            temp.push_back(candidates[idx]);
            temp_sum+=candidates[idx];
            combinations(idx , temp_sum , temp, candidates , target);

            temp.pop_back();
            temp_sum-=candidates[idx];
            combinations(idx+1 , temp_sum , temp , candidates , target);
           }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        combinations(0,0,temp,candidates,target);

        return ans;
    }
};