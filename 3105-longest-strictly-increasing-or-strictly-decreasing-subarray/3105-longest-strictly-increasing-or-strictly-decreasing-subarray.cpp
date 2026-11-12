class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxi = 1;
        int n = nums.size();

        for(int i = 0 ; i<n - 1; i++){
            bool flag = true;
            if(nums[i+1] < nums[i]) flag = false;
            if(nums[i+1] == nums[i]) continue;
            for(int j = i + 1; j<n ; j++){
                if(nums[j] > nums[j-1] && flag){
                    maxi = max(maxi , j-i+1);
                }

                else if(nums[j] < nums[j-1] && flag == false){
                    maxi = max(maxi , j - i + 1);
                }

                else{
                    break;
                }
            }
        }
        return maxi;
    }
};