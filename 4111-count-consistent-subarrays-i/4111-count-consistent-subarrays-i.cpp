class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();

        for(int i = 0 ; i<n ; i++){
            int mini = nums[i];
            int And = nums[i];

            for(int j = i ; j<n ; j++){
                mini = min(mini , nums[j]);
                And &= nums[j];
                if(mini == And) cnt++;
            }
        }

        return cnt;
    }
};