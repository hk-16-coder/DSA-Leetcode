class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        
        long long sum = 0;
        int mini = *min_element(nums.begin() , nums.end());

        for(int x : nums){
            sum += x-mini;
        }

       return sum;
    }
};