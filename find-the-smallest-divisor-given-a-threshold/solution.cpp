class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int maxi = INT_MIN;
        for(int i = 0 ; i<n ;i++){
            maxi = max(maxi,nums[i]);
        }
        if(n == threshold) return maxi;
        int low = 1;
        int high = maxi;
        int ans = -1;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            int temp = 0;
            for(int i = 0 ; i<n ; i++){
                if(nums[i]%mid != 0) temp += nums[i]/mid + 1;
                else temp += nums[i]/mid;
            }
            
            if(temp>threshold) low = mid + 1;
            else {
                ans = mid;
                high = mid -1; 
            }
        }
        return ans;
    }
};