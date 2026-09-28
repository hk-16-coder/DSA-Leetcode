class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int init = 0 , n = nums.size();
        for(int i = 0 ; i<n-1 ; i++){
            if(nums[i] == nums[i+1]) init++;
        }

        map<pair<int,int> , int> mpp;

        for(int i = 0 ; i<n-1 ; i++){
            if(nums[i] != nums[i+1]){
                if(nums[i] < nums[i+1]) mpp[{nums[i] , nums[i+1]}]++;
                else mpp[{nums[i+1] , nums[i]}]++;
            }
        }

        int maxi = 0;
        for(auto it : mpp){
            maxi = max(maxi , it.second);
        }
        return init + maxi;
    }
};