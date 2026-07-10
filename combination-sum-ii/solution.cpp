class Solution {
public:
    vector<vector<int>> ans;
    void combinations (int idx, int temp_sum, vector<int>& temp, vector<int>& candidates, int target){
           int n = candidates.size();
            if(temp_sum == target) {
             ans.push_back(temp);  
             return;
           }
           if(temp_sum > target || idx >= n) return;
  
           for(int i = idx ; i < n ; i++){
            if(i>idx && candidates[i] == candidates[i-1]) continue;

            temp.push_back(candidates[i]);
            temp_sum+=candidates[i];
            combinations(i + 1 , temp_sum , temp, candidates , target);

            temp_sum-= candidates[i];
            temp.pop_back();
           }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        combinations(0,0,temp,candidates,target);
       
        return ans;
    }
};