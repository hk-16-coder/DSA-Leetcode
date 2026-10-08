class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int val = 0 , mini = 1e6;
        for(int i = 0 ; i<n ; i++){
            for(int j = i+1 ; j<n ; j++){
                for(int k = j+1 ; k<n ; k++){
                    int sum = nums[i] + nums[j] + nums[k];
                    int diff = abs(target - sum);
                    if(diff < mini){
                        mini = diff;
                        val = sum;
                    }
                }
            }
        }
        return val;
    }
};