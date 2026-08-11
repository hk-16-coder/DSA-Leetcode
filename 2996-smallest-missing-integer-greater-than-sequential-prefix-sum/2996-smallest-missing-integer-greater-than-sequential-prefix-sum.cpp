class Solution {
public:
    int missingInteger(vector<int>& nums) {
        if(nums.size() == 1) return nums[0] + 1;

        vector<int> freq(52,0);
        for(int x : nums){
            freq[x]++;
        }
        int sum = nums[0];
        
        for(int i = 1 ; i<nums.size(); i++){
           
            if(nums[i] == nums[i-1] + 1){
                sum+=nums[i];
            }
            else break;
        }
       
        while(true){
            if(sum>=freq.size() || freq[sum] == 0) return sum;
            sum++;
        }

        return -1;
    }
};