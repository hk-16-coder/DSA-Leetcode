class Solution {
public:
    int count(vector<int>& nums , int k){
        // counts subarrays with distinct integers less than equal to k
        if(k==0) return 0;
        unordered_map<int,int> freq;
        int cnt = 0;
        int left = 0;
        int right = 0;
        while(right<nums.size()){
            freq[nums[right]]++;
            while(freq.size()>k){
                freq[nums[left]]--;
                if(freq[nums[left]] == 0) freq.erase(nums[left]);
                left++;
            }
            if(freq.size()<=k) cnt+=right-left+1;
            right++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return count(nums,k) - count(nums,k-1);
    }
};