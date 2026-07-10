class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        int swaps = 0;
        int zeroes = 0;
        for(int i = 0; i<nums.size() ; i++){
             if(nums[i] == 0) zeroes++;
        }
        for( j ; j>=0 ;j--){
            if(zeroes == 0) break;
            if(nums[j] != 0){
                swaps++;
                zeroes--;
            }
            else zeroes--;
        }
        return swaps;
    }
};