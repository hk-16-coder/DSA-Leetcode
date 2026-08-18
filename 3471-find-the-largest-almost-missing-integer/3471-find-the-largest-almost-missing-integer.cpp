class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
       int maxi = -1; // LARGEST ELEMENT WHICH APPEARS EXACTLY ONCE IN ARRAY
       int maxi2 = 0; // LARGEST ELEMENT OF ARRAY
       unordered_map<int,int> mpp;

       for(int x : nums){
        maxi2 = max(maxi2,x);
        mpp[x]++;
       }

       for(auto it : mpp){
        if(it.second == 1) maxi = max(maxi,it.first);
       }

       int n = nums.size();
       
       if(k == n) return maxi2;
       if(k == 1) return maxi;

       if(nums[0] == nums[n-1]) return -1;
  
       if(mpp[nums[0]] == 1 && mpp[nums[n-1]] == 1) return max(nums[0] , nums[n-1]);
       if(mpp[nums[0]] == 1 && mpp[nums[n-1]] >= 1) return nums[0];
       if(mpp[nums[0]] >= 1 && mpp[nums[n-1]] == 1) return nums[n-1];

       return -1;
    }
};