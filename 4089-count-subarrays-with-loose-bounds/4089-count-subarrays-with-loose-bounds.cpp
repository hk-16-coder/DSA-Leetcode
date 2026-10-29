class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long cnt = 0;
        int i = 0 , j = 0;
        
        while(j<n){
            if(nums[j] > maxK || nums[j] < minK){
                int len = j - i;
                i = j+1;
                j++;

                cnt += 1LL*len*(len+1)/2;;
            }
            while(j<n && nums[j] <= maxK && nums[j] >= minK) j++;
        }
        int len = j - i;
        cnt += 1LL*len*(len+1)/2 ;
        return cnt;
    }
};