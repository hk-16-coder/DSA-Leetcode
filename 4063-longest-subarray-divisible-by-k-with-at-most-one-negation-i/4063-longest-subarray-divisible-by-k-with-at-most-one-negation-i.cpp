class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int maxi = 0;
        int n = nums.size();
       
        for(int i = 0 ; i<n ; i++){
            int sum = 0;
            for(int j = i ; j<n ; j++){
                sum += nums[j];
                if(sum % k == 0) maxi = max(maxi , j-i+1);
                else if(j - i + 1 > maxi){
                    for(int idx = i ; idx<=j ; idx++){
                        if((sum - 2*nums[idx]) % k == 0){
                            maxi = j - i + 1;
                            break;
                        }
                    }
                }
            }
        }
        return maxi;
    }
};