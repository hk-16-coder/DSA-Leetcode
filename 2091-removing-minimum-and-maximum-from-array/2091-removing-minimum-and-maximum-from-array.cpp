class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int idx1  = 0, idx2 = 0; // idx1 is for maxi , idx2 is for mini
        int n = nums.size();
        if(n==1) return 1;

        for(int i = 0 ; i<n ; i++){
            if(nums[i]  > maxi){
                maxi = nums[i];
                idx1 = i;
            }

            if(nums[i] < mini){
                mini = nums[i];
                idx2  = i;
            }
        }

        if(idx1<=n/2 && idx2<=n/2) return max(idx1,idx2) + 1;

        if(idx1>n/2 &&  idx2>n/2) return max(n-idx1,n-idx2);

        if(idx1<=n/2) return min(idx1+1 + n-idx2 , min(idx2+1,n-idx1));

        if(idx2<=n/2) return min(idx2+1 + n-idx1 , min(idx1+1,n-idx2));
        return -1;            
    }
};