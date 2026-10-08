class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int val = nums[0] + nums[1] + nums[2];
        sort(nums.begin() , nums.end());

        for(int i = 0 ; i<n-2 ; i++){
            int l = i+1 , r = n-1;
            
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];

                if(abs(target - sum) < abs(target - val)) val = sum;

                if(sum < target) l++;
                else r--;
            }
        }
        return val;
    }
};