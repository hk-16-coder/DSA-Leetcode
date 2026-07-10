class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        else if(n==2) {
            if(nums[0]>nums[1]) return 0;
            else return 1;
        }
        int low = 1;
        int high = n-2;

        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) return mid;
            // We move towards the half whose element adjacent to mid is greater
            if(nums[mid] < nums[mid+1]) low = mid+1;
            else high = mid-1;
        }
        // if no peak is found then we return first or last index
        if(nums[0]>nums[1]) return 0;
        else return n-1;
    }
};