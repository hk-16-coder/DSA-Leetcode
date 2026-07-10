class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int total = 0;
        int n = nums.size();
        for(int bit = 0 ; bit<32 ; bit++){
            int ones = 0;  // counts the number whose ith bit is 1
            for(int i = 0 ; i<n ; i++){
                if(nums[i] & (1<<bit)) ones++;
            }
            total += ones * (n-ones) ;  // for contributing towards xor we need pairs of 0 and 1 so toal pairs is no. of ones * no. of zeroes
        }
        return total;
    }
};