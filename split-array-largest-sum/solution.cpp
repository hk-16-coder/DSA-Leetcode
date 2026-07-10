class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int  maxi = INT_MIN;
        int sum = 0;
        for(int i = 0 ; i<n ; i++){
            maxi = max(maxi,nums[i]);
            sum+=nums[i];
        }
        int low = maxi;
        int high = sum;
        while(low<=high){
            int mid = low + (high-low)/2;
            int cnt = 1;
            int temp_sum = 0;
            for(int i = 0 ; i<n ; i++){
                if(nums[i] + temp_sum <= mid) temp_sum+=nums[i];
                else{
                    cnt++;
                    temp_sum = nums[i];
                } 
            }
            if(cnt > k) low = mid+1;
            else high = mid-1;
        }
       return low;
    }
};