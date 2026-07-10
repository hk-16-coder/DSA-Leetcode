class Solution {
public:
    // int ans = INT_MAX;
    // void CountJumps(int idx , int jumps , vector<int>& nums){
    //     int n = nums.size();
    //     if(idx + nums[idx] >= n-1) {
    //         ans =  min(ans,jumps+1);
    //         return;
    //         }
    //     if(idx<n-1 && nums[idx] == 0) return;
    //     for(int i = 1 ; i<=nums[idx] ; i++){
    //        CountJumps(idx+i , jumps+1,nums);
    //     }
    // }
    // int jump(vector<int>& nums) {
    //     int n = nums.size();
    //     CountJumps(0 , 0,nums);
    //     return ans;
    // }

    int jump(vector<int>& nums){
        int l = 0;
        int r = 0;
        int n = nums.size();
        int jumps = 0;
        
        while(r < n-1){
            int farthest = 0;
            for(int i = l ; i<=r ; i++){
                farthest = max(farthest,  i + nums[i]);
            }
            l = r+1;
            r = farthest;
            jumps++;
        }
       return jumps;
    }
};