class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int n = nums.size();
        int mini = 1e9;
        for(int i = 0 ; i<n-1 ; i+=2){
            string s1 = to_string(nums[i]);
            string s2 = to_string(nums[i+1]);
            string s = s1 + s2;
            int num = stoi(s);
            mini = min(mini, num);
        }

        return mini;
    }
};