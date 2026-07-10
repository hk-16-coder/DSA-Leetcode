class Solution {
public:
    vector<vector<int>> ans;
    void permutations(vector<int>& temp , vector<int>& nums , map<int,int>& freq){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i = 0 ; i<nums.size(); i++){
            if(freq[i] == 0){
                temp.push_back(nums[i]);
                freq[i] = 1;
                permutations(temp,nums,freq);

                temp.pop_back();
                freq[i] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
       vector<int> temp;
       map<int,int> freq;
       permutations(temp,nums,freq);
       return ans;
    }
};