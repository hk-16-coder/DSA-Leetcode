class Solution {
public:
    int range(int n){
        int temp = n;
        int mini = 10;
        int maxi = -1;
        while(temp>0){
            mini = min(mini,temp%10);
            maxi = max(maxi,temp%10);
            temp/=10;
        }
        return maxi - mini;
    }
    int maxDigitRange(vector<int>& nums) {
        int ans = 0;
        int max_range = -1;
        for(int i = 0 ; i< nums.size(); i++){
            max_range = max(max_range,range(nums[i]));
        }
        for(int i = 0 ; i<nums.size() ; i++){
            if(range(nums[i]) == max_range) ans+=nums[i];
        }
        return ans;
    }
};