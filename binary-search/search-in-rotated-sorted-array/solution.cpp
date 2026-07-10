class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==1) {
            if (nums[0] == target )return 0;
            else return -1;
        }
        int low = 0;
        int high = n-1;
        while(low<=high){
            int mid = low + (high-low)/2 ;
            // left half sorted
            if(nums[mid] == target) return mid;
            if(nums[low] <= nums[mid]){
                 if(nums[low] <=target && nums[mid] >= target) high = mid-1;
                 else low = mid+1;
           }
           // right half sorted
           else{
             if(nums[mid] <= target && nums[high]>=target)low = mid+1;
             else high = mid-1;
          }
        }
        return -1;
    }
};