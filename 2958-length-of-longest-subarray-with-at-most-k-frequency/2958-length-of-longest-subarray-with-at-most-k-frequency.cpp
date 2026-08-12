class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int i = 0 , j = 0;
        int max_len = 0;
        while(j<nums.size()){
           // mpp[nums[j]]++;
            if(mpp[nums[j]] < k){
                mpp[nums[j]]++;
                j++;
                max_len = max(max_len,j-i);
            }
            else{
                mpp[nums[i]]--;
                i++;
            }
        }
        return max_len;
    }
};