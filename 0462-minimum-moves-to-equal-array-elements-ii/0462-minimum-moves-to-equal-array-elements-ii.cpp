class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        int val = nums[n/2];

        int sum = 0;
        for(int x : nums){
            sum += abs(x - val);
        }

        return sum;
    }
};