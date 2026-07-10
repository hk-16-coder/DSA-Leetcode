class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        // for(int i = 0 ; i<nums.size()-1 ; i++){
        //     if(i>0 && nums[i] == nums[i-1]) continue;
        //     int target = (-1)*nums[i];
        //     map<int,int> mpp;
        //     for(int j = i+1 ; j<nums.size() ; j++){
        //         if(mpp.find(target-nums[j]) != mpp.end()) {
        //             ans.push_back({nums[i],target-nums[j],nums[j]});
        //             while(j<nums.size()-1 && nums[j] == nums[j+1] ) j++;
        //         }
        //         mpp[nums[j]] = j;
        //     }
        // }
        // return ans;

        for(int i = 0 ;i<nums.size()-1 ; i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            int target = (-1)*nums[i];
            int left = i+1;
            int right = nums.size() - 1;
            while(left<right){
                if(nums[left] + nums[right] < target) left++;
                else if(nums[left] + nums[right] > target) right--;
                else{
                     ans.push_back({nums[i],nums[right],nums[left]});
                     left++;
                     right--;
                     while(left<right && nums[left] == nums[left-1]) left++;
                     while(left<right && nums[right] == nums[right+1]) right--;
                }
            }
        }
        return ans;
    }
};