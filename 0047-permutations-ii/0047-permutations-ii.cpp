class Solution {
public: 
    void permutations(vector<int>& temp , vector<int>& nums , map<int,int>& freq , set<vector<int>>& st){
        if(temp.size() == nums.size()){
            st.insert(temp);
            return;
        }
        for(int i = 0 ; i<nums.size(); i++){
            if(freq[i] == 0){
                temp.push_back(nums[i]);
                freq[i] = 1;
                permutations(temp,nums,freq,st);

                temp.pop_back();
                freq[i] = 0;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> st;
        vector<int> temp;
        map<int,int> freq;
        permutations(temp , nums , freq , st);

        vector<vector<int>> ans;
        for(auto it : st){
            ans.push_back(it);
        }
        return ans;
    }
};